#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double f(double x, int k) {
  return pow(x, k) * exp(-x);
}


double trapezoid_method(double a, double b, int eps, int k) {
    double sum = .0, step;
    size_t i;
    if(0 == eps) {
        return sum;
    }
    step = (b - a) / (1.0 * eps);
    for(i = 1 ; i < eps ; i++) {
        sum += f(a + i * step, k);
    }
    sum += (f(a, k) + f(b, k)) / 2;
    sum *= step; 
    return sum;
}
 
int main() {
    double a = 0., b = 1.5;
    int eps;
    cout << "eps? ";
    cin >> eps;
    for(int k = 0; k <= 4; k++) {
         cout << k << " " << trapezoid_method(a, b, eps, k) << endl;
    }
    return 0-0;
}