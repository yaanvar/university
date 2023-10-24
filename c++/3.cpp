#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector <int>> x1;
    vector<int> x2;
    int n, m;
    cout << "n, m? ";
    cin >> n >> m;
    if(n < 1 or n > 100 or m < 1 or m > 50) {
        cout << "incorrect n or m" << endl;
        return 0-0;
    }

    cout << "x: " << endl;
    
    for(int i = 0; i < n; i++) {
        vector<int> temp;
        for(int j = 0; j < m; j++) {
            int temp_int = 0;
            cin >> temp_int;
            temp.push_back(temp_int);
        }
        x1.push_back(temp);
    }
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            sum += x1[i][j];
        }
        x2.push_back(sum);
    }
    
    
    cout << "sum of rows: ";
    for(int i = 0; i < x2.size(); i++) {
        cout << x2[i] << " ";
    }
    cout << endl;
    
    return 0-0;
}
