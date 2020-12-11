#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test() {
    int a = 12;
    char b = 'b';
    a += b;
    printf("%d", a);

    return 0;
}

int main () {
   int i = 10518535;
   short s = i;

//    i = 37;
//    float f = *(float*) &i;
//    printf("%f", f);  // print very small number

   float f = 7.0;
   short sh = *(short*) &f;
   printf("%h", sh);

   return(0);
}