#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char* hex_string(uint16_t value)
{
    /* 
        In C single quotes identify a single character,
        while double quotes create a string literal. 
        containing an 'a' and a null terminator 
        (that is a 2 char array) 
    */
    // wrong -> char* hex[16] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    char hex[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int value_cpy = value;
    int n = 0;  //determine how long is the return char
    while(value_cpy != 0){
        n++;
        value_cpy /= 16;
    }

    char *str = (char*) malloc(n + 1);
    for (int i = 0; i < n; i++){
        str[n-1-i] = hex[value%16];
        value = value/16;             
    }
    str[n] = '\0';
    return str;    
}

int main() {
    uint16_t value = 800;
    char* s = hex_string(value);
    printf("%s", s);
    free(s);
    return 0;
}