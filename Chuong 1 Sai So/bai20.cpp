#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double factorial(int n) {
    if (n == 0) return 1;
    double result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double maclaurin_e_minus_x(int x, int terms) {
    double sum = 0.0;
    for (int n = 0; n < terms; ++n) {
        sum += pow(-x, n) / factorial(n);
    }
    return sum;
}

int main() {
    const int x = 10;
    const int terms_start = 5;
    const int terms_end = 10;

    cout << fixed << setprecision(15);
    cout << "Calculating e^-10 using Maclaurin series:" << endl;

    for (int terms = terms_start; terms <= terms_end; ++terms) {
        double result = maclaurin_e_minus_x(x, terms);
        cout << "Using " << terms << " terms: " << result << endl;
    }

    return 0;
}

