#include <limits.h>
#include <stdio.h>

int reverse(int x){
    long long r = 0;
    while (x != 0)
    {
        r = r * 10 + x % 10;
        if (r < INT_MIN || r > INT_MAX) return 0;
        x /= 10;
    }
//    return (r < INT_MIN || r > INT_MAX) ? 0 : r;
    return r;
}


int main() {
    int x = 1234;
    printf("%d ", reverse(x));
    printf("\tHello, World!\n");
    return 0;
}
 

