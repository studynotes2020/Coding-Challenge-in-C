#include <stdio.h>
#include <string.h>

// Parses the C-string str interpreting its content as an integral number, 
// which is returned as a value of type int.
int atoi(const char* str){
	int num = 0;
	for (int i = 0;i < strlen(str); i++){
		num = num * 10 + (str[i] - '0');
	}
	return num;
}


int main() {
    const char* a = "311";
    int i = atoi(a);
    printf("%d", i);

    return 0;
}