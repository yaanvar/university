#include <iostream>
#include <vector>

using namespace std;

int min(vector<int> x, int n) {
    if (n == 0) {
        return x[0];
    } else {
        int min_x = min(x, --n);
        return min_x < x[n] ? min_x : x[n];
    }
}

int main() {
    int n;
    cout << "n? ";
    cin >> n;
    vector<int> x;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        x.push_back(temp)
    }
    cout << "min: " << min(x, n);

    return 0;
}