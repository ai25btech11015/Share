#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Simple solver for 3x3 linear system using Gaussian elimination with partial pivoting
// Solves A x = b in-place. Returns 0 on success, non-zero on failure.
int solve_3x3(double A[3][3], double b[3], double x[3]) {
    int i, j, k, pivot_row;
    for (k = 0; k < 3; ++k) {
        // Partial pivoting: find row with largest |A[row][k]|
        double maxv = fabs(A[k][k]);
        pivot_row = k;
        for (i = k+1; i < 3; ++i) {
            double v = fabs(A[i][k]);
            if (v > maxv) { maxv = v; pivot_row = i; }
        }
        if (maxv < 1e-12) return -1; // singular or nearly singular

        // Swap rows k and pivot_row in A and b if needed
        if (pivot_row != k) {
            for (j = k; j < 3; ++j) {
                double tmp = A[k][j]; A[k][j] = A[pivot_row][j]; A[pivot_row][j] = tmp;
            }
            double tmpb = b[k]; b[k] = b[pivot_row]; b[pivot_row] = tmpb;
        }

        // Eliminate below
        for (i = k+1; i < 3; ++i) {
            double factor = A[i][k] / A[k][k];
            for (j = k; j < 3; ++j) A[i][j] -= factor * A[k][j];
            b[i] -= factor * b[k];
        }
    }

    // Back substitution
    for (i = 2; i >= 0; --i) {
        double s = b[i];
        for (j = i+1; j < 3; ++j) s -= A[i][j] * x[j];
        x[i] = s / A[i][i];
    }
    return 0;
}

void solve(double arr[3]) {
    // angles in radians
    const double B = 60.0 * M_PI / 180.0; // 60 deg
    const double C = 45.0 * M_PI / 180.0; // 45 deg

    double A_mat[3][3];
    double rhs[3];
    double sol[3] = {0.0, 0.0, 0.0};

    A_mat[0][0] = 1.0; A_mat[0][1] = 1.0; A_mat[0][2] = 1.0;
    A_mat[1][0] = -1.0; A_mat[1][1] = cos(C); A_mat[1][2] = cos(B);
    A_mat[2][0] = 0.0; A_mat[2][1] = sin(C); A_mat[2][2] = -sin(B);

    rhs[0] = 12.0; rhs[1] = 0.0; rhs[2] = 0.0;

    // Copy matrices because solver is in-place on A and b
    double A_copy[3][3];
    double b_copy[3];
    for (int i = 0; i < 3; ++i) {
        b_copy[i] = rhs[i];
        for (int j = 0; j < 3; ++j) A_copy[i][j] = A_mat[i][j];
    }

    if (solve_3x3(A_copy, b_copy, sol) != 0) {
        fprintf(stderr, "Linear solver failed (singular matrix)\n");
    }

    double a = sol[0];
    double b = sol[1];
    double c = sol[2];

    printf("a = %.3f, b = %.3f, c = %.3f\n", a, b, c);
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;

}
