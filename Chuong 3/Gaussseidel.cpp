#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calculateError(vector<double>& x, vector<double>& newX) {
    double maxError = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        double error = abs(newX[i] - x[i]);
        if (error > maxError) {
            maxError = error;
        }
    }
    return maxError;
}

vector<double> gaussSeidel(vector<vector<double> >& A, vector<double>& b, double tol, int maxIter) {
    int n = A.size();
    vector<double> x(n, 0.0); 

    for (int iter = 0; iter < maxIter; ++iter) {
        vector<double> newX(n);
        for (int i = 0; i < n; ++i) {
            double sum1 = 0.0;
            double sum2 = 0.0;
            for (int j = 0; j < i; ++j) {
                sum1 += A[i][j] * newX[j];
            }
            for (int j = i + 1; j < n; ++j) {
                sum2 += A[i][j] * x[j];
            }
            newX[i] = (b[i] - sum1 - sum2) / A[i][i];
        }

        double error = calculateError(x, newX);
        if (error < tol) {
            cout << "Converged after " << iter + 1 << " iterations." << endl;
            return newX;
        }

        for (int i = 0; i < n; ++i) {
            x[i] = newX[i];
        }
    }

    cout << "Maximum number of iterations reached." << endl;
    return x;
}

int main() {
    double a[3][3] = {{8, 2, 1}, {1, 6, 2}, {4, 0, 5}};
    double c[3] = {-11.5, 18.5, 12.5};

    vector<vector<double> > A;
    vector<double> b;

    for (int i = 0; i < 3; ++i) {
        vector<double> rowA(a[i], a[i] + sizeof(a[i]) / sizeof(a[i][0]));
        A.push_back(rowA);
        b.push_back(c[i]);
    }

    double tol = 1e-6;
    int maxIter = 1000;

    vector<double> solution = gaussSeidel(A, b, tol, maxIter);

    cout << "Ket qua:" << endl;
    for (size_t i = 0; i < solution.size(); ++i) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}

