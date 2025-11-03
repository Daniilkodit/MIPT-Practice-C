#include <stdio.h>
#include <stdlib.h>

void matrix_mult(unsigned long a[4], unsigned long b[4], unsigned long res[4], unsigned long m) {
    res[0] = (a[0] * b[0] + a[1] * b[2]) % m;
    res[1] = (a[0] * b[1] + a[1] * b[3]) % m;
    res[2] = (a[2] * b[0] + a[3] * b[2]) % m;
    res[3] = (a[2] * b[1] + a[3] * b[3]) % m;
}

void matrix_pow(unsigned long a[4], unsigned long n, unsigned long m, unsigned long res[4]) {
    unsigned long temp[4];

    res[0] = 1; res[1] = 0;
    res[2] = 0; res[3] = 1;
    
    if (n == 0) return;
    
    unsigned long current[4];
    for (int i = 0; i < 4; i++) current[i] = a[i];
    
    while (n > 0) {
        if (n % 2 == 1) {
            matrix_mult(res, current, temp, m);
            for (int i = 0; i < 4; i++) res[i] = temp[i];
        }
        matrix_mult(current, current, temp, m);
        for (int i = 0; i < 4; i++) current[i] = temp[i];
        n /= 2;
    }
}

int main(void) {
    unsigned long a1, a2, a3, a4, n, m;
    unsigned long a[4], res[4];
    
    if (scanf("%lu%lu%lu%lu%lu%lu", &a1, &a2, &a3, &a4, &n, &m) != 6) {
        printf("Invalid input\n");
        return 1;
    }
    
    a[0] = a1 % m;
    a[1] = a2 % m;
    a[2] = a3 % m;
    a[3] = a4 % m;
    
    matrix_pow(a, n, m, res);
    
    printf("%lu %lu %lu %lu\n", res[0], res[1], res[2], res[3]);
    return 0;
}