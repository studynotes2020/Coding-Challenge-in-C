#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int binaryPatternMatching(char * pattern, char * s) {
    int m = strlen(pattern);
    int n = strlen(s);
    int ans = 0;
    for (int i = 0; i < n - m + 1; i++) {
        bool match = true;
        for (int j = i; j < i + m; j++) {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y') {
                if (pattern[j-i] =='1') {
                    match = false;
                    break;
                }
            } else {
                if (pattern[j-i] =='0') {
                    match = false;
                    break;
                }

            }

        }
        if (match == true) {
            ans += 1;
        }
    }
    return ans;
}


int main() {
    char* pattern = "asd";
    char* s = "asd";
    printf("%d", binaryPatternMatching(pattern, s));
    return 0;
}