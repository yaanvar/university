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
    vector<vector<T> > new_x;
    for(int i = 0; i < x[0].size(); i++) {
        vector<T> temp_x;
        for(int j = 0; j < x.size(); j++) {
            temp_x.push_back(x[j][i]);
        }
        reverse(temp_x.begin(), temp_x.end());
        new_x.push_back(temp_x);
    }
    x = new_x;
}

int main() {
    int type;
    cout << "0 - int matrix\n1 - string matrix\n2 - float matrix\n";
    cin >> type;
    int n, m;
    cout << "n m? ";
    cin >> n >> m;
    if (type == 0) {
        vector<vector<int> > x;
        input_matrix(x, n, m); 
        process_matrix(x);
        output_matrix(x);
    } else if (type == 1) {
        vector<vector<string> > x;
        input_matrix(x, n, m); 
        process_matrix(x);
        output_matrix(x);
    } else {
        vector<vector<double> > x;
        input_matrix(x, n, m); 
        process_matrix(x);
        output_matrix(x);
    }
    
    return 0-0;
}