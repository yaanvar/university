#include <iostream>
#include <vector>

using namespace std;

int count_nums_in_range(vector<int> x, int left_border, int right_border) {
    int cnt = 0;
    for(auto elem: x) {
        if(elem >= left_border && elem <= right_border) {
            cnt++;
        }
    }
    return cnt;
}


void insert_num_after_max(int num, vector<int> &x) {
    int max_pos = 0;
    int max_num = INT32_MIN;
    for(int i = 0; i < x.size(); i++) {
        if(max_num < x[i]) {
            max_num = x[i];
            max_pos = i;
        }
    }
    x.insert(x.begin() + max_pos + 1, num);
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

    int l, r;
    cout << "enter range: ";
    cin >> l >> r;
    cout << "there is " << count_nums_in_range(x, l, r) << " numbers in range\n";
    cout << "enter a new number: ";
    cin >> n;
    insert_num_after_max(n, x);

    for(auto elem: x) {
        cout << elem << " ";
    }


    return 0;
}