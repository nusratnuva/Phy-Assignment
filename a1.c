#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main() {
    double lambda, m, a1, a2, a3;
    printf("Enter wavelength (in nm, range 380-750): ");
    scanf("%lf", &lambda);

    if (lambda < 380 || lambda > 750) {
        printf("Out of range. Please enter a valid number.\n");
    }
    else{
        printf("Enter diffraction order (m): ");
        scanf("%lf", &m);

        printf("Enter three slit widths (in µm): ");
        scanf("%lf %lf %lf", &a1, &a2, &a3);

        double theta1 = asin((m * lambda * 1e-3) / a1) * (180.0 / PI); // Convert to degrees
        double theta2 = asin((m * lambda * 1e-3) / a2) * (180.0 / PI);
        double theta3 = asin((m * lambda * 1e-3) / a3) * (180.0 / PI);

        printf("Theta for a1: %.2f degrees\n", theta1);
        printf("Theta for a2: %.2f degrees\n", theta2);
        printf("Theta for a3: %.2f degrees\n", theta3);

        if (theta1 >= theta2 && theta1 >= theta3) {
            printf("Slit with a1 bent the light the most.\n");
        } else if (theta2 >= theta1 && theta2 >= theta3) {
            printf("Slit with a2 bent the light the most.\n");
        } else {
            printf("Slit with a3 bent the light the most.\n");
        }
    }
    return 0;
}


