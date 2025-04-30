#include <iostream>
using namespace std;

const int N = 4;

void croutSolve(double A[N][N], double b[N]) {
    double L[N][N] = {0}, U[N][N] = {0};
    for (int i = 0; i < N; ++i) U[i][i] = 1;

    // Crout decomposition
    for (int j = 0; j < N; ++j) {
        for (int i = j; i < N; ++i) {
            L[i][j] = A[i][j];
            for (int k = 0; k < j; ++k)
                L[i][j] -= L[i][k] * U[k][j];
        }
        for (int i = j+1; i < N; ++i) {
            U[j][i] = A[j][i];
            for (int k = 0; k < j; ++k)
                U[j][i] -= L[j][k] * U[k][i];
            U[j][i] /= L[j][j];
        }
    }

    // Solve Ly = b
    double y[N];
    for (int i = 0; i < N; ++i) {
        y[i] = b[i];
        for (int k = 0; k < i; ++k)
            y[i] -= L[i][k] * y[k];
        y[i] /= L[i][i];
    }

    // Solve Ux = y
    double x[N];
    for (int i = N-1; i >= 0; --i) {
        x[i] = y[i];
        for (int k = i+1; k < N; ++k)
            x[i] -= U[i][k] * x[k];
    }

    for (int i = 0; i < N; ++i)
        cout << "x" << i+1 << " = " << x[i] << endl;
}

int main() {
    double A[N][N] = {
        { 3, -1,  0,  0},
        {-1,  3, -1,  0},
        { 0, -1,  3, -1},
        { 0,  0, -1,  3}
    };
    double b[N] = {2, 3, 4, 1};

    croutSolve(A, b);
    return 0;
}
