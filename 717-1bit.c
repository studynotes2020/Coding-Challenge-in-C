#include <stdio.h>
#include <stdbool.h>

bool isOneBitCharacter(int* bits, int bitsSize){
    int i = 0;
    while (i < bitsSize - 1) {
        i += bits[i] + 1;
    }
    return i == bitsSize - 1;
}

int main() {
    int bits[] = {1, 1, 1, 0};
    int bitsSize = sizeof(bits)/sizeof(int);
    printf("%d\n", isOneBitCharacter(bits, bitsSize));
    return 0;
}