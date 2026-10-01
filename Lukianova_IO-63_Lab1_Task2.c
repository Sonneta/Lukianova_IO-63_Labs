#include <stdio.h>

int main(void)
{
    double x = 0;
    double y = 0;

    printf("Enter x: ");
    scanf("%lf", &x);

    if (x > 0 && x <= 5) {
        y = x * x * x - 5 * x * x;
        printf("y(%g) = %.4f\n", x, y);
    } else if ((x >= -32 && x < -20) || x > 10) {
        y = x * x - 3;
        printf("y(%g) = %.4f\n", x, y);
    } else {
        printf("The function is undefined for x = %g\n", x);
    }

    return 0;
}