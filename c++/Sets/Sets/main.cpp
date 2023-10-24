#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template<std::size_t N>
bool operator<(const std::bitset<N>& x, const std::bitset<N>& y) {
    int cmp = std::memcmp(&x, &y, sizeof(x));
    return (cmp < 0);
}

template<std::size_t N>
bool operator>(const std::bitset<N>& x, const std::bitset<N>& y) {
    int cmp = std::memcmp(&y, &x, sizeof(x));
    return (cmp < 0);
}

template <typename T>
class Set {
    vector<T> set;
public:
    // создание пустого множества
    Set() { }
    // coздание множества
    Set(const Set& second_set) {
        this->set = second_set.set;
    }
    // включение элемента в множество
    void insert(const T value) {
        if (!contains(value)) {
            set.push_back(value);
        }
    }
    // объединение двух множеств
    Set unionSet(Set& second_set) {
        Set<T> temp = *this;
        for(auto elem: second_set.set) {
            temp.insert(elem);
        }
        return temp;
    }
    // пересечение двух множеств
    Set intersection(Set& second_set) {
        Set<T> temp;
        for(int i = 0; i < second_set.set.size(); i ++) {
            if (contains(second_set.set[i])) {
                temp.insert(second_set.set[i]);
            }
        }
        return temp;
    }
    // исключение элемента из множества
    T pop(const T value) {
        for (int i = 0; i < set.size(); i++) {
            if (set[i] == value) {
                set.erase(set.begin() + i);
                return value;
            }
        }
        
        return value;
    }
    // проверка вхождения элемента в множество
    bool contains(T value) {
        for(auto elem: set) {
            if(value == elem) {
                return true;
            }
        }
        return false;
    }
    // вывод множества
    void print() {
        cout << "{ ";
        for(auto elem: this->set) {
            cout << (int)(elem.to_ulong()) << " ";
        }
        cout << "}" << endl;
    }
    // вычисление индекса элемента массива, в котором хранится элемент со значением x
    int findIndex(T value) {
        for(int i = 0; i < this->set.size(); i++) {
            if (value == this->set[i]) {
                return i;
            }
        }
        return -1;
    }
    // запись в file
    void write() {
        ofstream file;
        file.open("storage.txt");
        int i = 1;
        for (auto elem: set) {
            file << "Элемента массива: " << i << "\n" << makeText(elem) << "\n";
            i++;
        }
        file.close();
    }

    string makeText(bitset<32> value) {
        string str_value = "Значение элемента: " + to_string((int)value.to_ulong()) + "\n";
        string raz = "";
        for(int i = 31; i > -1; i--) {
            raz += to_string(i) + "\t";
        }
        string bit = "Номер разряда:  " + raz + "\n";
        string temp = value.to_string();
        string bits = "";
        for(int i = 31; i > -1; i--) {
            bits += to_string(value[i]) + "\t";
        }
        bits = "Значение битов: " + bits + "\n";
        return str_value + bits + bit;
    }
    // проверка равенства двух множеств
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
    // разность двух множеств
    Set operator-(Set& second_set) {
        Set<T> temp = *this;
        for(int i = 0; i < second_set.set.size(); i ++) {
            if (contains(second_set.set[i])) {
                temp.pop(second_set.set[i]);
            }
        }
        return temp;
    }
};

template <typename T>
void input_set(Set<T> &set) {
    int length, temp;
    cout << "размер множества: ";
    cin >> length;
    if (length < 1) {
        return;
    }
    cout << "введите элементы множества: ";
    for (int i = 0; i < length; i++) {
        cin >> temp;
        set.insert(bitset<32>(temp));
    }
}

void program(Set<bitset<32>> &set_1, Set<bitset<32>> &set_2) {
    while(true) {
        string word;
        cin >> word;
        int temp;
        cout << "\n";
        if (word == "sozdat") {
            set_1 = Set<bitset<32>>();
            input_set(set_1);
        } else if (word == "pokazat") {
            set_1.print();
        } else if (word == "vvesti") {
            cout << "введи элемент, который хотите добавить: ";
            cin >> temp;
            set_1.insert(bitset<32>(temp));
        } else if (word == "udalit") {
            cout << "введите элемент, который хотите удалить: ";
            cin >> temp;
            set_1.pop(bitset<32>(temp));
        } else if (word == "index") {
            cout << "введите номер значение, чтобы получить индекс: ";
            cin >> temp;
            bitset<32> tempBitSet(temp);
            cout << "индекс: " << set_1.findIndex(tempBitSet) << endl;
        } else if (word == "vkl") {
            cout << "введите элемент для проверки включения: ";
            cin >> temp;
            if (set_1.contains(bitset<32>(temp))) {
                cout << "элемент есть в множестве\n";
            } else {
                cout << "элемента нет в множестве\n";
            }
        } else if (word == "peresech") {
            set_2 = Set<bitset<32>>();
            cout << "создайте множество для пересечения\n";
            input_set(set_2);
            set_1 = set_1.intersection(set_2);
            cout << "пересечение:\n";
            set_1.print();
        } else if (word == "+") {
            set_2 = Set<bitset<32>>();
            cout << "создайте множество для обьединения\n";
            input_set(set_2);
            set_1 = set_1.unionSet(set_2);
            cout << "обьединенные множества:\n";
            set_1.print();
        } else if (word == "=") {
            set_2 = Set<bitset<32>>();
            cout << "создайте множество для проверки эквивалентности\n";
            input_set(set_2);
            bool tempBool = set_1 == set_2;
            if (tempBool) {
                cout << "множества эквивалентны\n";
            } else {
                cout << "множества НЕ эквивалентны\n";
            }
        } else if (word == "-") {
            set_2 = Set<bitset<32>>();
            cout << "создайте множества для вычитания\n";
            input_set(set_2);
            set_1 = set_1 - set_2;
            cout << "вычитание первого и второго множества\n";
            set_1.print();
        } else if (word == "zapisat") {
            set_1.write();
            cout << "множество успешно записано\n";
        } else if (word == "vihod") {
            set_1.write();
            cout << "множество успешно записано перед выходом\n";
            break;
        } else {
            cout << "неправильная команда\n";
        }
    }
}

int main() {
    cout << "sozdat создать новое множество\n";
    cout << "vvesti добавить элемент в множество\n";
    cout << "udalit удалить элемент из множества\n";
    cout << "peresech показать пересечение двух множеств\n";
    cout << "= показать эквивалентность двух множеств\n";
    cout << "+ показать обьединение двух множест\n";
    cout << "- показать разность двух множеств\n";
    cout << "vkl проверить находиться ли элемент в множестве\n";
    cout << "index показать индекс элемента в множестве по значение\n";
    cout << "zapisat записать множество в файл\n";
    cout << "pokazat показать множество в консоли\n";
    cout << "vihod завершить работу программы\n";
    Set set_1  = Set<bitset<32>>();
    Set set_2 = Set<bitset<32>>();
    program(set_1, set_2);
    return 0;
}
