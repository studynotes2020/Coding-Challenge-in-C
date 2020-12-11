#include <stdio.h>
#include <memory.h>
#include <malloc.h>


char * defangIPaddr(char * address){
    // char* res = (char*) malloc(sizeof(char) * (strlen(address) + 1 + 6));
    char* res = (char*) malloc(strlen(address) + 7); // this and above both fine
    int j = 0;
    for (int i = 0; address[i] != '\0'; i++) {
        if (address[i] == '.') {
            res[j++] = '[';
            res[j++] = '.';
            res[j++] = ']';
        }
        else {
            res[j++] = address[i];
        }
    }
    res[j] = '\0';
    return res;
}


int main() {
    char address[] = "1.1.1.1";
    printf("%s", defangIPaddr(address));
    return 0;
}

