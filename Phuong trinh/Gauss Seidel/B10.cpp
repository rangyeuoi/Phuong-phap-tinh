#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void gaussSeidel(const vector<vector<double> >& A, const vector<double>& b, vector<double>& x, int maxIterations, double tolerance) {
    int n = A.size();
    vector<double> x_old(n, 0.0);

    for (int k = 0; k < maxIterations; ++k) {
        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        bool converged = true;
        for (int i = 0; i < n; ++i) {
            if (fabs(x[i] - x_old[i]) > tolerance) {
                converged = false;
                break;
            }
        }
        
        if (converged) {
            cout << "Converged after " << k + 1 << " iterations." << endl;
            return;
        }

        x_old = x;
    }

    cout << "Max iterations reached without convergence." << endl;
}

int main() {
    vector<vector<double> > A(3, vector<double>(3));
    A[0][0] = 8; A[0][1] = 2; A[0][2] = 1;
    A[1][0] = 1; A[1][1] = 6; A[1][2] = 2;
    A[2][0] = 4; A[2][1] = 0; A[2][2] = 5;

    vector<double> b(3);
    b[0] = -11.5; b[1] = 18.5; b[2] = 12.5;

    vector<double> x(3, 1.0);

    int maxIterations = 100;
    double tolerance = 1e-6;

    gaussSeidel(A, b, x, maxIterations, tolerance);

    cout << "Solution:" << endl;
    for (int i = 0; i < x.size(); ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}

