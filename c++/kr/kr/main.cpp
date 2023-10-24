#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
class Set {
    vector<T> set;
public:
    Set() { }
    Set(const Set& second_set) {
        this->set = second_set.set;
    }
    void insert(const T value) {
        if (!contains(value)) {
            set.push_back(value);
        }
    }
    Set unionSet(Set& second_set) {
        Set<T> temp = *this;
        for(auto elem: second_set.set) {
            temp.insert(elem);
        }
        return temp;
    }
    Set intersectionSet(Set& second_set) {
        Set<T> temp;
        for(int i = 0; i < second_set.set.size(); i ++) {
            if (contains(second_set.set[i])) {
                temp.insert(second_set.set[i]);
            }
        }
        return temp;
    }
    T remove(const T value) {
        for (int i = 0; i < set.size(); i++) {
            if (set[i] == value) {
                set.erase(set.begin() + i);
                return value;
            }
        }
        
        return value;
    }
    bool contains(T value) {
        for(auto elem: set) {
            if(value == elem) {
                return true;
            }
        }
        return false;
    }
    void print() {
        cout << "{ ";
        for(auto elem: this->set) {
            cout << elem << " ";
        }
        cout << "}" << endl;
    }
    void read() {
        set.clear();
        ifstream file;
        file.open("input.txt");
        T temp;
        while (file >> temp) {
            this->insert(temp);
        }
        file.close();
    }
    void write() {
        ofstream file;
        file.open("output.txt");
        int i = 1;
        for (auto elem: set) {
            file << elem << " ";
            i++;
        }
        file.close();
    }
    Set operator-(Set& second_set) {
        Set<T> temp = *this;
        for(int i = 0; i < second_set.set.size(); i ++) {
            if (contains(second_set.set[i])) {
                temp.remove(second_set.set[i]);
            }
        }
        return temp;
    }
    bool operator==(Set& second_set) {
        if (second_set.set.size() != this->set.size()) {
            return false;
        }
        for(int i = 0; i < this->set.size(); i++) {
            if (set[i] != second_set.set[i]) {
                return false;
            }
        }
        return true;
    }
};

template <typename T>
void input_set(Set<T> &set) {
    int length;
    T temp;
    cout << "Размер: ";
    cin >> length;
    if (length < 1) {
        return;
    }
    cout << "Введите элементы: ";
    for (int i = 0; i < length; i++) {
        cin >> temp;
        set.insert(temp);
    }
}

template <typename T>
void commander(Set<T> &set_1, Set<T> &set_2) {
    cout << "1. Cоздать множество\n";
    cout << "2. Добавить элемент в множество\n";
    cout << "3. Включение элемента в множестве\n";
    cout << "4. Удалить элемент из множества\n";
    cout << "5. Пересечение двух множеств\n";
    cout << "6. Эквивалентность двух множеств\n";
    cout << "7. Обьединение двух множест\n";
    cout << "8. Разность двух множеств\n";
    cout << "9. Записать в файл\n";
    cout << "10. Вывести множество в консоль\n";
    cout << "11. Ввести множество с файла\n";
    cout << "12. Завершить работу программы\n";
    
    while(true) {
        int number;
        cin >> number;
        T temp;
        if (number == 1) {
            set_1 = Set<T>();
            input_set(set_1);
        } else if (number == 2) {
            cout << "добавить элемент: ";
            cin >> temp;
            set_1.insert(temp);
        } else if (number == 3) {
            cout << "проверить включение элемента: ";
            cin >> temp;
            if (set_1.contains(temp)) {
                cout << "есть\n";
            } else {
                cout << "отсутствует\n";
            }
        } else if (number == 4) {
            cout << "элемент для удаления: ";
            cin >> temp;
            set_1.remove(temp);
        } else if (number == 5) {
            set_2 = Set<T>();
            cout << "создайте новое множество:\n";
            input_set(set_2);
            set_1 = set_1.intersectionSet(set_2);
            cout << "пересечение:\n";
            set_1.print();
        } else if (number == 6) {
            set_2 = Set<T>();
            cout << "создайте новое множество:\n";
            input_set(set_2);
            bool tempBool = set_1 == set_2;
            if (tempBool) {
                cout << "эквивалентны\n";
            } else {
                cout << "не эквивалентны\n";
            }
        } else if (number == 7) {
            set_2 = Set<T>();
            cout << "создайте множество:\n";
            input_set(set_2);
            set_1 = set_1.unionSet(set_2);
            cout << "обьединение:\n";
            set_1.print();
        } else if (number == 8) {
            set_2 = Set<T>();
            cout << "создайте множество:\n";
            input_set(set_2);
            set_1 = set_1 - set_2;
            cout << "разность:";
            set_1.print();
        } else if (number == 9) {
            set_1.write();
            cout << "множество успешно сохранено\n";
        } else if (number == 10) {
            set_1.print();
        } else if (number == 11) {
            set_1.read();
            cout << "множество успешно считано\n";
        } else if (number == 12) {
            set_1.write();
            cout << "множество сохранено перед завершением работы программы\n";
            break;
        } else {
            cout << "некорректная команда. введите ее снова.\n";
        }
    }
}

int main() {
    
    cout << "Выберите тип данных:\n";
    cout << "1. Int\n";
    cout << "2. Float\n";
    cout << "3. String\n";
    int type = -1;
    while (type < 1 || type > 3) {
        cin >> type;
    }
    
    if (type == 1) {
        Set<int> set_1 = Set<int>();
        Set<int> set_2 = Set<int>();
        commander(set_1, set_2);
    } else if (type == 2) {
        Set<float> set_1 = Set<float>();
        Set<float> set_2 = Set<float>();
        commander(set_1, set_2);
    } else if (type == 3) {
        Set<string> set_1 = Set<string>();
        Set<string> set_2 = Set<string>();
        commander(set_1, set_2);
    }
    
    return 0;
}
