//
//  main.cpp
//  practice11-1
//
//  Created by Anvar Rahimov on 14.11.2022.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// (номер заказа, ФИО заказчика, товар в заказе, количество товара, сумма заказа) / номер заказа

struct Order {
    string order_number;
    string full_name;
    string item_in_order;
    string amount_of_items;
    string cost;
};

// • сортировку массива структур по возрастанию значений одного из полей структуры;
struct comporator {
    inline bool operator() (const Order& ord1, const Order& ord2) {
        return (ord1.order_number < ord2.order_number);
    }
};

//  • вывод данных об объектах на экран в упорядоченном по возрастанию виде;
void output_recs(vector <Order> &orders) {
    sort(orders.begin(), orders.end(), comporator());
    for(int i = 0; i < orders.size(); i++) {
        cout << i + 1 << ". " + orders[i].order_number + " " + orders[i].full_name + " " + orders[i].item_in_order + " " + orders[i].amount_of_items + " " + orders[i].cost << endl;
    }
}

//  • ввод данных об n объектах из текстового файла в массив структур (0<n<=50);
void input_from_file(vector <Order> &orders) {
    ifstream in;
    in.open("orders.txt");
    Order temp;
    string first_name, last_name, fathers_name;
    while(in >> temp.order_number >> last_name >> first_name >> fathers_name >> temp.item_in_order >> temp.amount_of_items >> temp.cost) {
        temp.full_name = last_name + " " + first_name + " " + fathers_name;
        orders.push_back(temp);
    }
    sort(orders.begin(), orders.end(), comporator());
}

//  • поиск объекта по значению одного из полей;
int bin_search(vector<Order> array, string order_number, int low, int high) {
    if (low <= high) {
        int mid = (low + high)/2;
        if (array[mid].order_number == order_number)
            return mid;
        if (array[mid].order_number > order_number)
            return bin_search(array, order_number, low, mid-1);
        if (array[mid].order_number < order_number)
            return bin_search(array, order_number, mid+1, high);
    }
    cout << "invalid range!";
    return -1;
}

int find_index(string order_number, vector<Order> orders) {
    return bin_search(orders, order_number, 0, orders.size());
}

// • запись упорядоченных данных об объектах в двоичный файл;
void write_in_binary_file(vector <Order> orders) {
    fstream tab("bin.txt", ios::binary | ios::out);
    for(int i = 0; i < orders.size(); i++) {
        string str = orders[i].order_number +  " " +  orders[i].full_name + " " + orders[i].item_in_order + " " + orders[i].amount_of_items + " " + orders[i].cost + "\n";
        size_t size = str.size();
        tab.write((char *)&size, sizeof(size));
        tab.write(str.c_str(), size);
    }
    tab.close();
}

// • чтение двоичного файла.
void read_in_binary_file(vector<Order> &orders, int lines) {
    fstream show("bin.txt", ios::binary | ios::in);
    for(size_t i = 0; i < lines; i++) {
        size_t size;
        show.read( (char *)&size, sizeof(size));
        char buf[size + 1];
        show.read(buf, size);
        buf[size] = 0;
        Order temp;
        string data = string(buf);
        istringstream iss(data);
        vector<string> results((istream_iterator<string>(iss)),
                                         istream_iterator<string>());
        temp.order_number = results[0];
        temp.full_name = results[1];
        temp.item_in_order = results[2];
        temp.amount_of_items = results[3];
        temp.cost = results[4];
        orders.push_back(temp);
    }
    show.close();
}

int main() {
    vector <Order> orders;
    input_from_file(orders);
    write_in_binary_file(orders);
    cout << "Заказ 122-122 под номером: " << find_index("122-122", orders) + 1 << endl;
    output_recs(orders);
    return 0;
}
