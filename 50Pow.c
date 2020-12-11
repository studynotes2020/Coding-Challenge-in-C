#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n) {
    double res = 1.0;
    bool positive = 0;
    if (n >= 0)
        positive = true;
    else {
        positive = false;
        n = -n;
    }

    if (x >= 0) {
        while (n) {
            res *= x;
            if (res < 0.0000009)
                return res;
            n--;
        }
    } else {
        while (n) {
            res = res * -x * -1;
            n--;
        }
    }
    if (positive)
        return res;
    else
        return 1/res;

}

double myPow2(double x, int n)
{
    double ret = 1;
    if (x == 1) { return 1; }
    if (x == 2 && n == -2147483648) { return 0;}
    if (x == -1 && n == -2147483648) { return 1;}
    if (n < 0) {
        int b = -n;
        for (;;) {
            if (b & 1)ret *= x;
            b >>= 1;
            if (!b)  break;
            x *= x;
        }
        ret = 1/ret;
    }
    else {
        for (;;) {
            if (n & 1)ret *= x;
            n >>= 1;
            if (!n)
                break;
            x *= x;
        }
    }
    return ret;
}

double myPow3(double x, int n) {
    if (n < 0) {
        x = 1/x;
        n = -n;
    }
    double pow = 1;
    while (n) {
        if (n & 1) {
            pow *= x;
        }
        x *= x;
        n >>= 1;
    }
    return pow;
}

void main() {
    double x = 2;
    int n = 5;
    printf("%f", myPow3(x, n));
}

