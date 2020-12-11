#include <stdio.h>
extern int var;

int main() {
    var = 10;  // undefined reference to `var'
    printf("%d", var);
    return 0;
}