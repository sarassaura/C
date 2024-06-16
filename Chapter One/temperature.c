#include <stdio.h>

// Celsius - Fahrenheint - Kelvin
/*
    1 to 100 Celsius
*/

float c_to_k(float n) { return n + 273.15; }

float c_to_f(float n) { return n * 9.0 / 5.0 + 32; }

int main() {
    printf("Celsius     Fahrenheint     Kelvin\n\n");
    for (int i = 0; i <= 100; i++) {
        printf("%4d%16.2f%14.2f\n", i, c_to_f(i), c_to_k(i));
    }
    return 0;
}