#include <stdio.h>

int main(void)
{
    double x = 0;
    double y = 0;

    printf("Enter x: ");
    scanf("%lf", &x);

    if (x <= 0) {
        if (x < -20) {
            if (x < -32) {
                printf("The function is undefined for x = %g\n", x);
            } else {
                y = x * x - 3;
                printf("y(%g) = %.4f\n", x, y);
            }
        } else {
            printf("The function is undefined for x = %g\n", x);
        }
    } else {
        if (x <= 5) {
            y = x * x * x - 5 * x * x;
            printf("y(%g) = %.4f\n", x, y);
        } else {
            if (x <= 10) {
                printf("The function is undefined for x = %g\n", x);
            } else {
                y = x * x - 3;
                printf("y(%g) = %.4f\n", x, y);
            }
        }
    }

    return 0;
}