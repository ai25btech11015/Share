#include <math.h>
#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Exported function for DLL: computes a, b, c and returns via pointers
EXPORT void solve_triangle(double *a, double *b, double *c) {
    const double B = 60.0 * M_PI / 180.0;
    const double C = 45.0 * M_PI / 180.0;
    double A_mat[3][3];
    double rhs[3];
    double sol[3] = {0.0, 0.0, 0.0};

    A_mat[0][0] = 1.0; A_mat[0][1] = 1.0; A_mat[0][2] = 1.0;
    A_mat[1][0] = -1.0; A_mat[1][1] = cos(C); A_mat[1][2] = cos(B);
    A_mat[2][0] = 0.0; A_mat[2][1] = sin(C); A_mat[2][2] = -sin(B);
    rhs[0] = 12.0; rhs[1] = 0.0; rhs[2] = 0.0;

    // Gaussian elimination (same as before)
    double A_copy[3][3];
    double b_copy[3];
    for (int i = 0; i < 3; ++i) {
        b_copy[i] = rhs[i];
        for (int j = 0; j < 3; ++j) A_copy[i][j] = A_mat[i][j];
    }
    // Solve
    int i, j, k, pivot_row;
    for (k = 0; k < 3; ++k) {
        double maxv = fabs(A_copy[k][k]);
        pivot_row = k;
        for (i = k+1; i < 3; ++i) {
            double v = fabs(A_copy[i][k]);
            if (v > maxv) { maxv = v; pivot_row = i; }
        }
        if (maxv < 1e-12) return;
        if (pivot_row != k) {
            for (j = k; j < 3; ++j) {
                double tmp = A_copy[k][j]; A_copy[k][j] = A_copy[pivot_row][j]; A_copy[pivot_row][j] = tmp;
            }
            double tmpb = b_copy[k]; b_copy[k] = b_copy[pivot_row]; b_copy[pivot_row] = tmpb;
        }
        for (i = k+1; i < 3; ++i) {
            double factor = A_copy[i][k] / A_copy[k][k];
            for (j = k; j < 3; ++j) A_copy[i][j] -= factor * A_copy[k][j];
            b_copy[i] -= factor * b_copy[k];
        }
    }
    for (i = 2; i >= 0; --i) {
        double s = b_copy[i];
        for (j = i+1; j < 3; ++j) s -= A_copy[i][j] * sol[j];
        sol[i] = s / A_copy[i][i];
    }
    *a = sol[0];
    *b = sol[1];
    *c = sol[2];
}
