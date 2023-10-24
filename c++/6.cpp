#include <iostream>
#include <vector>

using namespace std;

int count_even_nums(vector<int> x) {
    int cnt = 0;
    for(auto elem: x) {
        if(elem % 2 == 0) {
            cnt++;
        }
    }
    return cnt;
}

void insert_num_before_max(int num, vector<int> &x) {
    int max_pos = 0;
    int max_num = INT32_MIN;
    for(int i = 0; i < x.size(); i++) {
        if(max_num < x[i]) {
            max_num = x[i];
            max_pos = i;
        }
    }
    x.insert(x.begin() + max_pos, num);
}

int main() {

    int n;
    cout << "enter n: ";
    cin >> n;
    vector<int> x(n);
    cout << "enter array: ";
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "there is " << count_even_nums(x) << " even numbers in an array\n";
    cout << "enter new number: ";
    cin >> n;
    insert_num_before_max(n, x);

    for(auto elem: x) {
        cout << elem << " ";
    }


    return 0-0;
}