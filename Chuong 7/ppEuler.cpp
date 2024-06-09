#include <iostream>
#include <cmath>

using namespace std;

// Define the differential equation dy/dt = f(t, y)
double f(double t, double y) {
    return -10 * y;
}

// Implement Euler's method
double euler_method(double t, double y, double h) {
    return y + h * f(t, y);
}

int main() {
    double t = 0.0; // Initial value of t
    double y = 1.0; // Initial value of y
    double h = 0.1; // Step size
    double end_time = 2.0; // End time

    // Iterate from t = 0 to t = 2 with step size h
    cout << "t = " << t << ", y(t) = " << y << endl;
    while (t < end_time) {
        y = euler_method(t, y, h);
        t += h;
        cout << "t = " << t << ", y(t) = " << y << endl;
    }

    return 0;
}

