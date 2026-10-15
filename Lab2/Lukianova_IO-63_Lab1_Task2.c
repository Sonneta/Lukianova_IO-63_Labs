#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1) return 1;

    double x = 0.5;
    double pi = 3.14159265358979323846;
    int ops = 0;

    double P = (2.0 * x) / pi;
    ops += 3;

    double sum = 0.0;
    ops += 1;

    double x_sq = x * x;
    double pi_sq = pi * pi;
    ops += 4;

    ops += 1;
    for (int i = 1; i <= n; i++) {
        ops += 1;

        sum += (2.0 * i - 1.0);
        ops += 4;

        double num = 4.0 * (x_sq - pi_sq * sum);
        ops += 4;

        double den = pi_sq * (1.0 - 4.0 * sum);
        ops += 4;

        P *= (num / den);
        ops += 3;

        ops += 2;
    }
    ops += 1;

    printf("Result (Dynamic Programming): %.7lf\n", P);
    printf("Error: %.7e\n", fabs(sin(x) - P));
    printf("Number of operations: %d\n", ops);

    return 0;
}