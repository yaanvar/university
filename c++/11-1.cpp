#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Rec {
    string first_name;
    string last_name;
    string fathers_name;
    string full_name;
    string date_of_birth;
    string phone_number;
};

struct comporator {
    inline bool operator() (const Rec& rec1, const Rec& rec2) {
        return (rec1.full_name < rec2.full_name);
    }
};

void output_recs(vector <Rec> &recs) {
    for(int i = 0; i < recs.size(); i++) {
        cout << i + 1 << ". " + recs[i].full_name + " " + recs[i].date_of_birth + " " + recs[i].phone_number << endl;
    }
} 

void input_from_file(vector <Rec> &recs) {
    ifstream in;
    in.open("data.txt");
    Rec temp;
    while(in >> temp.last_name >> temp.first_name >> temp.fathers_name >> temp.date_of_birth >> temp.phone_number) {
        temp.full_name = temp.last_name + " " + temp.first_name + " " + temp.fathers_name;
        recs.push_back(temp);
    }

    cout << recs.size();
}

int main() {

    vector <Rec> recs;
    input_from_file(recs);
    output_recs(recs);
    

    return 0;
}