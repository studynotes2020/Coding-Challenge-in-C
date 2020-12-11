#include <stdio.h>
#include <memory.h>

/*
You're given strings J representing the types of stones that are jewels, 
and S representing the stones you have.  Each character in S is a 
type of stone you have.  You want to know how many of the stones you 
have are also jewels.

The letters in J are guaranteed distinct, and all characters in 
J and S are letters. Letters are case sensitive, so "a" is considered 
a different type of stone from "A".

Example 1:
Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:
Input: J = "z", S = "ZZ"
Output: 0
*/

int numJewelsInStones(char * J, char * S){
    int cnt = 0;
    // 1. Use strlen to loop
    // 2. Use S[i] != '\0' to loop
    for (int i = 0; i < strlen(S); i++) {
        for (int j = 0; j < strlen(J); j++) {
            if (S[i] == J[j]) {
                cnt++;
            }
        }
    }
    return cnt;
}


void main() {
    char* J = "aA";
    char* S = "aAAbbbb";
    printf("%d", numJewelsInStones(J, S));
}
