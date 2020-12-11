#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* res = (int*) malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                *res = i;
                *(res + 1) = j;
                return res;
            }

        }
    }
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int numsSize = 4, target = 9;
    int n = 2;
    int* returnSize = &n;
    int* res = twoSum(nums, numsSize, target, returnSize);
    printf("%d ", *res);
    printf("%d ", *(res + 1));
    return 0;
}