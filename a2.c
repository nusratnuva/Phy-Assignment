#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main() {
    double lambda_green = 530; // nm
    double lambda_red = 700;   // nm
    double m_green = 3, m_red = 2;
    double theta_green = 65.0 * (PI / 180.0); // Convert to radians

    // Calculate d
    double d = (m_green * lambda_green * 1e-9) / sin(theta_green);

    // Calculate theta for red light
    double sin_theta_red = (m_red * lambda_red * 1e-9) / d;
    if (sin_theta_red > 1.0) {
        printf("No second-order bright spot for red light.\n");
    }
    else{
        double theta_red = asin(sin_theta_red) * (180.0 / PI); // Convert to degrees
        printf("Angle for second-order bright spot (red light): %.2f degrees\n", theta_red);
    }
    return 0;
}

