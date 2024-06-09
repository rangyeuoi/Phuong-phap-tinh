#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return (25.0 / (x * x) + 2 * x) / 3.0;
}

int main() {
    double x0 = 3.0; 
    double epsilon = 1e-4;

    int iterations = 0;
    double x = x0;

    while (abs(x - f(x)) >= epsilon) {
        x = f(x);
        iterations++;
    }

    cout << fixed << setprecision(4);
    cout << "Approximation to cbrt(25) that is accurate to within 10^-4: " << x << endl;
    return 0;
}

