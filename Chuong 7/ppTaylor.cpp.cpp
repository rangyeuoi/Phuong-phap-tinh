#include <iostream>
#include <cmath>

using namespace std;

double f(double t, double y) {
    return 1 + t * sin(t * y);
}

double taylor_method(double t, double y, double h) {
    double k1 = h * f(t, y);
    double k2 = h * f(t + h, y + k1);
    return y + 0.5 * (k1 + k2);
}

int main() {
    double t = 0.0; 
    double y = 0.0; 
    double h = 0.1; 
    double end_time = 2.0; 
    cout << "Result: " << endl;
    cout << "t = " << t << ", y(t) = " << y << endl;
    while (t < end_time) {
        y = taylor_method(t, y, h);
        t += h;
        cout << "t = " << t << ", y(t) = " << y << endl;
    }

    return 0;
}

