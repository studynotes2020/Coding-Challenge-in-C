#include <stdio.h>

void CountSort(int A[], int range) {
    // assume 0 <= A[i] < range for any element A[i]
    int *pi = A;
    for (int i = 0; i < range; i++)
        pi[A[i]]++;
    for (int j = 0; j < range; j++) {
        for (int k = 1; k < pi[j]; k++) {
            printf("%d ",j);
        }
    }
}

int main() {
    printf("Hello, World!\n");
    int A[5] = {4,2,6,1,3};
    int range = 6;
    CountSort(A, range);
    return 0;
}