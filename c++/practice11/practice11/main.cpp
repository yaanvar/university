//
//  main.cpp
//  practice11
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

struct Rec {
    string full_name;
    string date_of_birth;
    string phone_number;
};

// • сортировку массива структур по возрастанию значений одного из полей структуры;
struct comporator {
    inline bool operator() (const Rec& rec1, const Rec& rec2) {
        return (rec1.full_name < rec2.full_name);
    }
};

//  • вывод данных об объектах на экран в упорядоченном по возрастанию виде;
void output_recs(vector <Rec> &recs) {
    sort(recs.begin(), recs.end(), comporator());
    for(int i = 0; i < recs.size(); i++) {
        cout << i + 1 << ". " + recs[i].full_name + " " + recs[i].date_of_birth + " " + recs[i].phone_number << endl;
    }
}

//  • ввод данных об n объектах из текстового файла в массив структур (0<n<=50);
void input_from_file(vector <Rec> &recs) {
    ifstream in;
    in.open("data.txt");
    Rec temp;
    string first_name, last_name, fathers_name;
    while(in >> last_name >> first_name >> fathers_name >> temp.date_of_birth >> temp.phone_number) {
        temp.full_name = last_name + " " + first_name + " " + fathers_name;
        recs.push_back(temp);
    }
    sort(recs.begin(), recs.end(), comporator());
}

//  • поиск объекта по значению одного из полей;
int bin_search(vector<Rec> array, string word, int low, int high) {
    if (low <= high) {
        int mid = (low + high)/2;
        if (array[mid].full_name == word)
            return mid;
        if (array[mid].full_name > word)
            return bin_search(array, word, low, mid-1);
        if (array[mid].full_name < word)
            return bin_search(array, word, mid+1, high);
    }
    cout << "invalid range!";
    return -1;
}

int find_index(string word, vector<Rec> recs) {
    return bin_search(recs, word, 0, recs.size());
}

// • запись упорядоченных данных об объектах в двоичный файл;
void write_in_binary_file(vector <Rec> recs) {
    fstream tab("binary_file.txt", ios::binary | ios::out);
    for(int i = 0; i < recs.size(); i++) {
        string str = recs[i].full_name +  " " +  recs[i].date_of_birth + " " + recs[i].phone_number + "\n";
        size_t size = str.size();
        tab.write((char *)&size, sizeof(size));
        tab.write(str.c_str(), size);
    }
    tab.close();
}

// • чтение двоичного файла.
void read_from_binary_file(vector<Rec> &recs, int lines) {
    fstream show("binary_file.txt", ios::binary | ios::in);
    for(size_t i = 0; i < lines; i++) {
        size_t size;
        show.read( (char *)&size, sizeof(size));
        char buf[size + 1];
        show.read(buf, size);
        buf[size] = 0;
        Rec temp;
        string data = string(buf);
        istringstream iss(data);
        vector<string> results((istream_iterator<string>(iss)),
                                         istream_iterator<string>());
        temp.full_name = results[0];
        temp.date_of_birth = results[1];
        temp.phone_number = results[2];
        recs.push_back(temp);
    }
    show.close();
}

int main() {
    vector <Rec> recs;
    input_from_file(recs);
    write_in_binary_file(recs);
    output_recs(recs);
    cout << "Рахимов Анвар Далерович находится под индексом - " << find_index("Рахимов Анвар Далерович", recs) + 1 << endl;
    return 0;
}
