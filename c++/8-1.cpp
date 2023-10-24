#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void input_matrix(vector<vector<T> > &x, int n, int m) {
    cout << "enter matrix elements:\n";
    for(int i = 0; i < n; i++) {
        vector<T> temp_vec;
        for(int j = 0; j < m; j++) {
            T temp;
            cin >> temp;
            temp_vec.push_back(temp);
        }
        x.push_back(temp_vec);
    }
}

template<typename T>
void output_matrix(vector<vector<T> > &x) {
    cout << "matrix:\n";
    for(int i = 0; i < x.size(); i++) {
        for(int j = 0; j < x[i].size(); j++) {
            cout << x[i][j] << "\t";
        }
        cout << "\n";
    }
}

template<typename T>
void process_matrix(vector<vector<T> > &x) {
    for(int i = 0; i < x.size(); i++) {
        sort(x[i].begin(), x[i].end());
        reverse(x[i].begin(), x[i].end());
    }
}

int main() {
    bool isString;
    cout << "0 - int matrix\n1 - string matrix\n";
    cin >> isString;
    int n, m;
    cout << "n m? ";
    cin >> n >> m;
    if (isString) {
        vector<vector<string> > x(0);
        input_matrix(x, n, m); 
        process_matrix(x);
        output_matrix(x);
    } else {
        vector<vector<int> > x(0);
        input_matrix(x, n, m); 
        process_matrix(x);
        output_matrix(x);
    }
    
    return 0;
}