// C code to calculate area of parallelogram
#include <stdio.h>
#include "libs/matfun.h"
#include <math.h>

int main() {
    // create a b vectros 
    double **a = createMat(3,1);
    a[0][0] = 3;
    a[1][0] = 1;
    a[2][0] = 4;

    double **b = createMat(3,1);
    b[0][0] = 1;
    b[1][0] = -1;
    b[2][0] = 1;

    double mag_a = sqrt(Matdot(a, a,3));
    double mag_b = sqrt(Matdot(b, b,3));

    double cos_theta = Matdot(a, b,3) / (mag_a * mag_b);
    double angle = acos(cos_theta);

    double area = mag_a * mag_b * sin(angle);

    FILE *fp = fopen("var.dat", "w");
    if (fp != NULL) {
        fprintf(fp, "%lf\n", area);
        fclose(fp);
    } else {
        printf("Error opening file for writing.\n");
    }
    


    return 0;

}