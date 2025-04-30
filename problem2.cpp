#include <iostream>
#include <iomanip>
using namespace std;

const int N = 4;

void invertMatrix(double A[N][N]) {
    double I[N][N] = {0};
    for (int i = 0; i < N; ++i) I[i][i] = 1;

    // Forward elimination
    for (int i = 0; i < N; ++i) {
        double pivot = A[i][i];
        for (int j = 0; j < N; ++j) {
            A[i][j] /= pivot;
            I[i][j] /= pivot;
        }
        for (int k = 0; k < N; ++k) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = 0; j < N; ++j) {
                    A[k][j] -= factor * A[i][j];
                    I[k][j] -= factor * I[i][j];
                }
            }
        }
    }

    // Output inverse
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << setw(10) << I[i][j] << " ";
        cout << endl;
    }
}

int main() {
    double A[N][N] = {
        {4,  1, -1,  0},
        {1,  3, -1,  0},
        {-1, -1, 6,  2},
        {0,  0,  2,  5}
    };
    invertMatrix(A);
    return 0;
}
