#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

int digitsManipulations(int n) {
    int prod = 1;
    int sum = 0;

    while (n) {
        int i = n % 10;
        prod *= i;
        sum += i;

        n /= 10;
    }
    return prod - sum;
}

int main() {
    printf("Hello, World!\n");
    int n = 100;
    printf("%d", digitsManipulations(n));
    return 0;
}