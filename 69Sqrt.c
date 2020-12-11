#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Newton method
int mySqrt(int x) {
    if (x == 1)
        return 1;
    int n = x/2;
    int prev = x;
    while (n < prev) {
        prev = n;
        n = (n + x/n) / 2;
    }
    return prev;
}

// Bisection method
int mySqrt2(int x) {
    if (x == 1)
        return 1;
    int start = 0, end = x, mid;

    while (start <= end) {
        mid = start + (end - start)/2;
        if (mid > x/mid)
            end = mid - 1;
        else if (mid < x/mid)
            start = mid + 1;
        else
            return mid;
    }
    return end;
}

void main() {
    int x = 2147395599;
    printf("%d", mySqrt2(x));
}


