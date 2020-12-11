#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool circularArrayLoop(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++) {
        int linkLength = 0;
        int j = i;
        bool forward = nums[j] > 0;
        while (true) {
            if ((forward && nums[j] < 0) || (!forward && nums[j] > 0)) {
                break;
            }
            int nextj = (j + nums[j] ) % numsSize;
            if (nextj == j) {
                break;
            }
            j = nextj;
            linkLength++;
            if (linkLength > numsSize) {
                return true;
            }

        }
    }
    return false;
}

/*
You are given a circular array nums of positive and negative integers. 
If a number k at an index is positive, then move forward k steps. 
Conversely, if it's negative (-k), move backward k steps. 
Since the array is circular, you may assume that the last 
element's next element is the first element, and the first element's 
previous element is the last element.

Determine if there is a loop (or a cycle) in nums. 
A cycle must start and end at the same index and the cycle's length > 1. 
Furthermore, movements in a cycle must all follow a single direction. 
In other words, a cycle must not consist of both forward and backward 
movements.

Example 1:
Input: [2,-1,1,2,2]
Output: true
Explanation: There is a cycle, from index 0 -> 2 -> 3 -> 0. 
The cycle's length is 3.

Example 2:
Input: [-1,2]
Output: false
Explanation: The movement from index 1 -> 1 -> 1 ... is not a cycle, 
because the cycle's length is 1. By definition the cycle's length 
must be greater than 1.

*/
int main() {
    printf("Hello, World!\n");
    int nums[] = {2,-1,1,2,2};
    int numsSize = 5;
    printf("%d ", circularArrayLoop(nums, numsSize));
    
    return 0;
}



