#include <iostream>
#include <vector>

using namespace std;

template<typename T>
T sum(vector<T> x, size_t n) {
    if(n == 0) {
        return x[0];
    }
    return x[n] + sum(x, --n);
}

int main() {
    int n;
    cout << "n? ";
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << "sum is: " << sum(x, n);

    return 0-0;
}