#include <stdio.h>

// Recursive function to calculate a^b
int power(int a, int b) {
    if (b == 0)
        return 1;              // Base case
    return a * power(a, b - 1); // Recursive call
}

int main() {
    int a, b;

    printf("Enter base (a): ");
    scanf("%d", &a);

    printf("Enter exponent (b): ");
    scanf("%d", &b);

    printf("%d^%d = %d\n", a, b, power(a, b));

    return 0;
}