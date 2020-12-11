#include <stdio.h>

void f(int *x)
{
    *x = 90;
}

int main()
{
    int a = 10, b = 100;
    int *c;
    c = &a;

    f(&a);  // call by reference example

    scanf("%d", &a)  // that why &a rather than a
}

/*
// -g to stick the code in the executable for debugging
gcc .\gdb-example.c -o .\gdb-example -g
gdb .\gdb-example

// inside gdb
l  // list code
b 10  // set breakpoint at line 10
r  // run
s // step



*/