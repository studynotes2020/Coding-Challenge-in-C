#include <stdio.h>

// Sort list A into order, in place.

int main() {
    printf("Hello, World!\n");
    int A[5] = {4,2,6,1,3};
    int key, i;
    for (int j = 0; j < sizeof(A)/sizeof(A[0]); j++) {
        key = A[j];
        // insert A[j] into sorted sequence A[0..j-1]
        i = j - 1;
        while (i > -1 && A[i] > key) {
            A[i+1] = A[i];
            i -= 1;
        }
        A[i+1] = key;
    }

    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++) {
        printf("%d ", A[i]);
    }

    return 0;
}