#include <stdio.h>
#include <stdlib.h>

void calculate_primes(int primes[], int n);
void goldbach(int n);

void calculate_primes(int primes[], int n) {
    for (int i = 0; i <= n; i++) {
        primes[i] = 1;
    }
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = 0;
            }
        }
    }
}

int main() {
    int n;
    printf("Введите значение n: ");
    scanf("%d", &n);
    if (n > 10000000) {
        printf("n не должно превышать 10 000 000\n");
        return 1;
    }
    int *primes = (int *)malloc((n + 1) * sizeof(int));
    if (primes == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    calculate_primes(primes, n);
    printf("Простые числа до %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    int a, b;
    printf("Введите два числа a и b: ");
    scanf("%d %d", &a, &b);
    if (a % 2 != 0 || b % 2 != 0 || a < 4 || b > 10000000) {
        printf("Неверные входные данные\n");
        return 1;
    }
    for (int i = a; i <= b; i += 2) {
        goldbach(i);
    }
    free(primes);
    return 0;
}
