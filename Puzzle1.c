#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a = 12;
    char b = 'b';  // ascii b is 98
    a += b;  // 98 + 12 = 110
    printf("%d", a);

    return 0;
}