//
//  main.cpp
//  Set
//
//  Created by Anvar Rahimov on 15.11.2022.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

// MARK: bitset
typedef bitset<32> _4bytes;
typedef bitset<16> _2bytes;
typedef bitset<8> _1byte;

template<size_t N>
bool operator<(const bitset<N>& x, const bitset<N>& y) {
    int cmp = memcmp(&x, &y, sizeof(x));
    return (cmp < 0);
}

template<size_t N>
bool operator>(const bitset<N>& x, const bitset<N>& y) {
    int cmp = memcmp(&y, &x, sizeof(x));
    return (cmp < 0);
}

// MARK: Binary-Searh Tree
template <typename T>
struct Node {
    T data;
    
    Node* left;
    Node* right;
    
public:
    int containsNode(Node* root, T data) {
        if (root == NULL) {
            return 0;
        }
        int x = root->data == data ? 1 : 0;
        return x | containsNode(root->left, data) | containsNode(root->right, data);
    }
    
    Node* insert(Node* root, T data) {
        if (root == NULL) {
            Node<T>* tmp = new Node<T>;
            tmp->data = data;
            tmp->left = tmp->right = NULL;
            return tmp;
        }
        if (data < root->data) {
            root->left = insert(root->left, data);
            return root;
        } else if (data > root->data) {
            root->right = insert(root->right, data);
            return root;
        } else {
            return root;
            
        }
    }
    
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }
    
    Node* deleteNode(Node* root, T data) {
        if (root == NULL) {
            return root;
        }
        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        } else if (data > root->data) {
            root->right = deleteNode(root->right, data);
        } else {
            if (root->left == NULL and root->right == NULL)
                return NULL;
            else if (root->left == NULL) {
                Node* temp = root->right;
            free(root);
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                free(root);
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
};

// MARK: Set
template <typename T>
class Set {
    Node<T>* root;
    
    int size;
    
public:
    
    // MARK: создание пустого множества
    Set() {
        root = NULL;
        size = 0;
    }
    
    Set(const Set& s) {
        root = s.root;
        size = s.size;
    }
    
    // MARK: включение элемента в множество
    void add(const T data) {
        if (!root->containsNode(root, data)) {
            root = root->insert(root, data);
            size++;
        }
    }
    
    // MARK: объединение двух множеств
    Set unionSet(Set& s) {
        Set<T> res;
        if (root == NULL)
            return res;
        if (s.root == NULL)
            return *this;
        
        stack<Node<T>*> nodeStack;
        nodeStack.push(root);
        
        while (!nodeStack.empty()) {
            Node<T>* node;
            node = nodeStack.top();
            nodeStack.pop();
            res.add(node->data);
            
            if (node->right) {
                nodeStack.push(node->right);
            }
            if (node->left) {
                nodeStack.push(node->left);
            }
        }
        
        stack<Node<T>*> nodeStack1;
        nodeStack1.push(s.root);
        
        while (!nodeStack1.empty()) {
            Node<T>* node;
            node = nodeStack1.top();
            nodeStack1.pop();
            
            res.add(node->data);
            
            if (node->right) {
                nodeStack1.push(node->right);
            }
            if (node->left) {
                nodeStack1.push(node->left);
            }
        }
        
        return res;
    }
    
    // MARK: пересечение двух множеств
    Set intersectionSet(Set& s) {
        Set<T> res;
        stack<Node<T>*> nodeStack;
        nodeStack.push(root);
        
        while (!nodeStack.empty()) {
            Node<T>* node;
            node = nodeStack.top();
            nodeStack.pop();
            if (s.contains(node->data)) {
                res.add(node->data);
            }
            if (node->right) {
                nodeStack.push(node->right);
            }
            if (node->left) {
                nodeStack.push(node->left);
            }
        }
        return res;
    }
    
    // MARK: разность двух множеств
    Set operator-(Set& s) {
        Set<T> res;
        stack<Node<T>*> nodeStack;
        nodeStack.push(this->root);
        
        while (!nodeStack.empty()) {
            Node<T>* node;
            node = nodeStack.top();
            nodeStack.pop();
            if (!s.contains(node->data)) {
                res.add(node->data);
            }
            if (node->right) {
                nodeStack.push(node->right);
            }
            if (node->left) {
                nodeStack.push(node->left);
            }
        }
        return res;
    }
    
    // MARK: исключение элемента из множества
    T pop(const T data) {
        root->deleteNode(root, data);
        return data;
    }
    
    // MARK: проверка равенства двух множеств
    bool operator==(Set& s) {
        if (s.size != size) {
            return false;
        }
        stack<Node<T>*> nodeStack;
        nodeStack.push(this->root);
        
        while (!nodeStack.empty()) {
            Node<T>* node;
            node = nodeStack.top();
            nodeStack.pop();
            if (!s.contains(node->data)) {
                return false;
            }
            if (node->right) {
                nodeStack.push(node->right);
            }
            if (node->left) {
                nodeStack.push(node->left);
            }
        }
        return true;
    }
    
    // MARK: проверка вхождения элемента в множество
    bool contains(T data) {
        return root->containsNode(root, data) ? true : false;
    }
    
    // MARK: вычисление индекса элемента массива, в котором хранится элемент со значением x
    int indexOf(T data) {
        int i = 0;
        stack<Node<T>*> nodeStack;
        nodeStack.push(this->root);
        
        while (!nodeStack.empty()) {
            Node<T>* node;
            node = nodeStack.top();
            nodeStack.pop();
            
            if (node->data == data) {
                 return i;
            }
            i++;
            
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        return -1;
    }
    // MARK: TODO
    // MARK:  вывод множества
    void showNumbers() {
        cout << "{ ";
        
        if (this->root != NULL) {
            
            stack<Node<T>*> nodeStack;
            nodeStack.push(this->root);
            
            while (!nodeStack.empty()) {
                Node<T>* node;
                node = nodeStack.top();
                nodeStack.pop();
                
                cout << (int)((node->data).to_ulong()) << " ";
                
                if (node->right)
                    nodeStack.push(node->right);
                if (node->left)
                    nodeStack.push(node->left);
            }
        }
        
        cout << "}" << endl;
    }
    
    // MARK: запись в file
    
    void writeInFile() {
        ofstream out;
        out.open("data.txt");
        
        int i = 0;
        stack<Node<T>*> nodeStack;
        nodeStack.push(this->root);
        
        while (!nodeStack.empty()) {
            Node<T>* node;
            node = nodeStack.top();
            nodeStack.pop();
            
            out << "Номер элемента массива: " << i << "\n";
            out << textToWrite(node->data);
            out << "\n";
            i++;
            
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        
        out.close();
    }

    string textToWrite(bitset<32> data) {
        string value = "Значение элемента: " + to_string((int)data.to_ulong()) + "\n";
        
        string temp = data.to_string();
        string strBits = "";
        for(int i = 31; i > -1; i--) {
            strBits += to_string(data[i]) + "\t";
        }
        string bits = "Значение битов: " + strBits + "\n";
        
        string numbers = "";
        for(int i = 31; i > -1; i--) {
            numbers += to_string(i) + "\t";
        }
        string bitNumber = "Номер разряда:  " + numbers + "\n";
        
        return value + bits + bitNumber;
    }
};

// MARK: Console

enum Command {
    createEmptyset,
    addNewElement,
    removeElement,
    checkIfContains,
    unionSet,
    intersectionSet,
    equalSet,
    indexOf,
    writeInFile,
    subtract,
    leave,
    show,
    indexof,
    
    help,
    error
};

Command command(string com) {
    if (com == "create")
        return createEmptyset;
    else if (com == "show")
        return show;
    else if (com == "add")
        return addNewElement;
    else if (com == "remove")
        return removeElement;
    else if (com == "contains")
        return checkIfContains;
    else if (com == "intersection")
        return intersectionSet;
    else if (com == "equals")
        return equalSet;
    else if (com == "union")
        return unionSet;
    else if (com == "write")
        return writeInFile;
    else if (com == "leave")
        return leave;
    else if (com == "subtract")
        return subtract;
    else if (com == "help")
        return help;
    else if (com == "index")
        return indexof;
    else
        return error;
}

template <typename T>
void fill_set(Set<T> &set) {
    int len = 0, temp;
    cout << "how many elements do you want?\n";
    cin >> len;
    if (len < 1) {
        return;
    }
    cout << "input elements:\n";
    while(len--) {
        cin >> temp;
        set.add(_4bytes(temp));
    }
}

void showAllCommans() {
    cout << "create - create new set\n";
    cout << "add - add element to the set\n";
    cout << "remove - remove element from the set\n";
    cout << "contains - check if the element contains in the set\n";
    cout << "index - shows index of given value\n";
    cout << "intersection - show the intersection of set and the new set\n";
    cout << "equals - show if the set and the new set equal\n";
    cout << "union - show the union of set and the new set\n";
    cout << "subtract - subtract the new set from o set\n";
    cout << "write - write the set in the file\n";
    cout << "show - print out the set in the console\n";
    cout << "leave - exit the program\n";
}

void program() {
    cout << "type 'help' to see all commands\n\n";
    
    Set tempSet_1  = Set<_4bytes>();
    Set tempSet_2 = Set<_4bytes>();
    
    while(true) {
        string tempStr;
        cin >> tempStr;

        int temp;
        cout << "\n";
        
        switch (command(tempStr)) {
            case createEmptyset: {
                tempSet_1 = Set<_4bytes>();
                
                fill_set(tempSet_1);
                
                break;
            }
            case show: {
                
                tempSet_1.showNumbers();
                
                break;
            }
            case addNewElement: {
                
                cout << "input element: ";
                cin >> temp;
                tempSet_1.add(_4bytes(temp));
                
                break;
            }
            case subtract: {
                tempSet_2 = Set<_4bytes>();
                
                cout << "creating new set for subtraction\n";
                fill_set(tempSet_2);
                tempSet_1 = tempSet_1 - tempSet_2;
                cout << "subtraction of first and second set:\n";
                tempSet_1.showNumbers();
                
                break;
            }
            case removeElement: {
                
                cout << "input element: ";
                cin >> temp;
                tempSet_1.pop(_4bytes(temp));
                
                break;
            }
            case checkIfContains: {
                
                cout << "input element: ";
                cin >> temp;
                if (tempSet_1.contains(_4bytes(temp))) {
                    cout << "true\n";
                } else {
                    cout << "false\n";
                }
                
                break;
            }
            case unionSet: {
                tempSet_2 = Set<_4bytes>();
                
                cout << "creating new set for union\n";
                fill_set(tempSet_2);
                tempSet_1 = tempSet_1.unionSet(tempSet_2);
                cout << "union set:\n";
                tempSet_1.showNumbers();
                
                break;
            }
            case intersectionSet: {
                tempSet_2 = Set<_4bytes>();
                
                cout << "creating new set for intesrsection\n";
                fill_set(tempSet_2);
                tempSet_1 = tempSet_1.intersectionSet(tempSet_2);
                cout << "intersection set:\n";
                tempSet_1.showNumbers();
                
                break;
            }
            case equalSet: {
                tempSet_2 = Set<_4bytes>();
                
                cout << "creating new set for equal\n";
                fill_set(tempSet_2);
                bool tempBool = tempSet_1 == tempSet_2;
                if (tempBool) {
                    cout << "true\n";
                } else {
                    cout << "false\n";
                }
                
                break;
            }
            case indexOf: {
                
                cout << "input element: ";
                cin >> temp;
                _4bytes tempBitSet(temp);
                tempSet_1.indexOf(tempBitSet);
                
                break;
            }
            case writeInFile: {
                
                tempSet_1.writeInFile();
                
                break;
            }
            case indexof: {
                
                cout << "input value: ";
                cin >> temp;
                bitset<32> tempBitSet(temp);
                cout << "index: " << tempSet_1.indexOf(tempBitSet) << endl;
                
                break;
            }
            case help: {
                
                showAllCommans();
                
                break;
            }
            case error: {
                
                cout << "invalid command. type 'help' to see all commands\n";
                
                break;
            }
            case leave: {
                
                tempSet_1.writeInFile();
                return;
            }
        }
        cout << "\n-----\n\n";
    }
}

// MARK: main
int main() {
    
    program();
    
    return 0-0;
}
