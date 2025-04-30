#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int N = 4;
    double A[N][N+1] = {
        {1.19, 2.11, -100, 1, 1.12},
        {14.2, -0.112, 12.2, -1, 3.44},
        {0, 100, -99.9, 1, 2.15},
        {15.3, 0.11, -13.1, -1, 4.16}
    };

    for (int i = 0; i < N; ++i) {
        int maxRow = i;
        for (int k = i+1; k < N; ++k)
            if (fabs(A[k][i]) > fabs(A[maxRow][i]))
                maxRow = k;
        for (int k = 0; k <= N; ++k)
            swap(A[i][k], A[maxRow][k]);
        for (int k = i+1; k < N; ++k) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j <= N; ++j)
                A[k][j] -= factor * A[i][j];
        }
    }

    double x[N];
    for (int i = N-1; i >= 0; --i) {
        x[i] = A[i][N];
        for (int j = i+1; j < N; ++j)
            x[i] -= A[i][j] * x[j];
        x[i] /= A[i][i];
    }

    cout << "Q1 Gaussian solution:\n";
    for (int i = 0; i < N; ++i)
        cout << "x" << i+1 << " = " << x[i] << endl;

    return 0;
}

