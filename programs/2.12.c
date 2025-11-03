#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long long ull;

ull pow_mod(ull n, ull exp, ull m);
ull gcd(ull x, ull y);
int is_prime(ull N);
ull find_largest_prime(int k, int n);

int main(void) {
    int k, n;
    if(scanf("%d%d", &k, &n) != 2) {
        printf("0\n");
        return 0;
    }
    
    srand(time(NULL)); // Инициализация генератора случайных чисел
    ull prime = find_largest_prime(k, n);
    printf("%llu\n", prime);
    
    return 0;
}

ull find_largest_prime(int k, int n) {
    ull seq0 = 0, seq1 = 1;
    ull largest_prime = 0;
    const ull limit = (1ULL << 60);
    
    while(seq1 < limit) {
        if(seq1 > 1 && is_prime(seq1)) {
            largest_prime = seq1;
        }
        
        ull next = k * seq1 + n * seq0;
        seq0 = seq1;
        seq1 = next;
        
        // Проверка на переполнение
        if(seq1 < seq0) break;
    }
    
    return largest_prime;
}

ull gcd(ull x, ull y) {
    while(y != 0) {
        ull tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}

ull pow_mod(ull n, ull exp, ull m) {
    ull res = 1;
    n %= m;
    while(exp > 0) {
        if(exp % 2 == 1) {
            res = (res * n) % m;
        }
        n = (n * n) % m;
        exp /= 2;
    }
    return res;
}

int is_prime(ull N) {
    // Быстрые проверки для маленьких чисел
    if(N < 2) return 0;
    if(N == 2 || N == 3) return 1;
    if(N % 2 == 0) return 0;
    
    // Тест Ферма с 10 случайными основаниями
    for(int i = 0; i < 10; i++) {
        ull a = 2 + rand() % (N - 3);
        if(gcd(a, N) != 1) return 0;
        if(pow_mod(a, N-1, N) != 1) return 0;
    }
    
    return 1;
}