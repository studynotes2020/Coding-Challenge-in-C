#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int kthSmallest(int** matrix, int matrixRowSize, int matrixColSize, int k) {
    int left = matrix[0][0];
    int right = matrix[matrixRowSize-1][matrixColSize-1];
    while (left < right) {
        int mid = (left + right) / 2;
        int n = 0;
        for (int i = 0; i < matrixRowSize; i++) {
            for (int j = 0; j < matrixColSize; j++) {
                if (mid >= matrix[i][j]) {
                    n++;
                }
            }
        }

        if (n < k)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void main() {
    clock_t start = clock();

    int matrixRowSize = 3;
    int matrixColSize = 3;
    int k = 8;
    int row1[3] = {1,5,9};
    int row2[3] = {10,11,13};
    int row3[3] = {12,13,15};
    int* matrix[3] = {row1,row2,row3};
    printf("%d\n",kthSmallest(matrix, matrixRowSize, matrixColSize, k));

    clock_t end = clock();
    double time_taken = ((double)(end - start))/CLOCKS_PER_SEC*1000;
    printf("kthSmallest() took %f milliseconds to execute \n", time_taken);
}