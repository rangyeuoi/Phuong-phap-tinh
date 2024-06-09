#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double forward_difference(const vector<double>& x, const vector<double>& y, int i, double h) {
    return (y[i + 1] - y[i]) / h;
}

double backward_difference(const vector<double>& x, const vector<double>& y, int i, double h) {
    return (y[i] - y[i - 1]) / h;
}

double central_difference(const vector<double>& x, const vector<double>& y, int i, double h) {
    return (y[i + 1] - y[i - 1]) / (2 * h);
}

void calculate_derivative(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    vector<double> derivatives(n);

    double h = x[1] - x[0];

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            derivatives[i] = forward_difference(x, y, i, h);
        } else if (i == n - 1) {
            derivatives[i] = backward_difference(x, y, i, h);
        } else {
            derivatives[i] = central_difference(x, y, i, h);
        }
    }

    cout << fixed << setprecision(6);
    for (int i = 0; i < n; ++i) {
        cout << "f'(" << x[i] << ") = " << derivatives[i] << endl;
    }
}

int main() {
    double x1_array[] = {1.05, 1.10, 1.15, 1.20, 1.25, 1.30};
    double y1_array[] = {-1.709847, -1.373823, -1.119214, -0.9160143, -0.7470223, -0.6015966};

    vector<double> x1(x1_array, x1_array + sizeof(x1_array) / sizeof(double));
    vector<double> y1(y1_array, y1_array + sizeof(y1_array) / sizeof(double));

    cout << "Ket qua cua y a la:" << endl;
    calculate_derivative(x1, y1);
    cout << endl;

    double x2_array[] = {-3.0, -2.8, -2.6, -2.4, -2.2, -2.0};
    double y2_array[] = {16.08554, 12.64465, 9.863738, 7.623176, 5.825013, 4.389056};

    vector<double> x2(x2_array, x2_array + sizeof(x2_array) / sizeof(double));
    vector<double> y2(y2_array, y2_array + sizeof(y2_array) / sizeof(double));

    cout << "Ket qua cua y b la:" << endl;
    calculate_derivative(x2, y2);

    return 0;
}

