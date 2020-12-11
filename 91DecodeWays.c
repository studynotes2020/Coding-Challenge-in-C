#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *strndup(char *str, int chars)
{
    char *buffer;
    int n;

    buffer = (char *) malloc(chars +1);
    if (buffer) {
        for (n = 0; ((n < chars) && (str[n] != 0)) ; n++)
            buffer[n] = str[n];
        buffer[n] = 0;
    }

    return buffer;
}

int helper(char* s, size_t k) {
    if (k == 0) {
        return 1;
    }
    size_t i = strlen(s) - k;
    if (s[i] == '0') {
        return 0;
    }
    int res = helper(s, k - 1);
    char* substr = strndup(s + i, 2);
    if (k >= 2 && atoi(substr) <= 26) {
        res += helper(s, k - 2);
    }
    return res;
}

int numDecodings(char * s){
    return helper(s, strlen(s));
}

/*
A message containing letters from A-Z is being encoded to 
numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the 
total number of ways to decode it.

Example 1:
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

*/

int main() {
    printf("Hello, World!\n");
    char s[] = "226";
    printf("%d ", numDecodings(s));
    
    return 0;
}

