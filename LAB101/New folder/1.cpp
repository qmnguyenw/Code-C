#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

bool checkPalindrome(char * inputString) {
    char *str;
    str = (char*)malloc(100*sizeof(char));
    int j = 0;
	for(int i = strlen(inputString) - 1; i >= 0; i--){
        str[j]=inputString[i];
        j++;
    }
    puts(inputString);
    puts(str);
    if(strcmp(inputString, str) == 0){
        return true;
    }else{
        return false;
    }
}


int main(){
	char string[100]="ada";
	if (checkPalindrome(string)){
		printf("true");	
	}else {
		printf("f");	
	}
	
	return 0;
}


