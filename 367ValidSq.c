#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Output: true
Example 2:

Input: 14
Output: false
 */
bool isPerfectSquare(int num) {
    if (num <= 1) {
        return true;
    }
    for (int i = num/2; i > 0; i--) {
        if (i * i == num) {
            return true;
        }
    }
    return false;
}

bool isPerfectSquare2(int num) {
    long long int low = 0, high = num / 2 + 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (mid * mid < num)
            low = mid + 1;
        else if (mid * mid > num)
            high = mid - 1;
        else
            return true;
    }
    return false;
}

int main() {
    int num = 123;
    printf("%d", isPerfectSquare2(num));
    return 0;
}


