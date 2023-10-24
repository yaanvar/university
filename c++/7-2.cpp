#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double f(double x, int t) {
  return pow(x, 2) * exp(-t * x);
}

double left_rectangles_method(double a, double b, int eps, double t) {
    double x, h;
    double sum = 0.0;
    double fx;
    h = (b - a) / eps;
    for(int i = 0; i < eps; i++) {
        x = a + i * h;
        fx = f(x, t);
        sum += fx;
    }
    return (sum * h);  
}
 
int main() {
    double a = -1., b = 1.;
    int eps;
    cout << "eps? ";
    cin >> eps;
    for(double t = 0.; t <= 2.; t += 0.5) {
         cout << t << " " << left_rectangles_method(a, b, eps, t) << endl;
    }
    return 0;
}