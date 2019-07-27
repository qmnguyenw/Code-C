#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void swap(char x[], char y[]) {
	char *temp=(char*)malloc(50*sizeof(char));
	strcpy(temp,x);
	temp=(char*)realloc(temp,strlen(temp)*sizeof(char));
	strcpy(x,y); strcpy(y,temp);
}

void bubble(char **string, int size) {
	//from the first element to the last one in array
	for(int i = 0; i < size - 1; i++)
		//from the next to i element to the last one in array
		for(int j = i + 1; j < size; j++)
			//swap 2 string if they are wrong order
			if(strcmp(string[i],string[j]) > 0) swap(string[i],string[j]);
}

int checkNumber(int inputNum, char check) {
    //if check is character not '\n' => input is not a number, return 0
    if (check != '\n') {
        printf("Data type error.\n");
        return 0;
    }
    //if input number out of required range, return 0
    if (inputNum < 1) {
        printf("Input number must be in range > 1.\n");
        return 0;
    }
    //else return 1
    return 1;
}
int checkElement(char inputString[]) {
    //variable to count the blanks
    int countBlank = 0;
    //from first to last element of input string
    for (int i = 0; i < strlen(inputString); i++) {
        //if there is an element is blank, increase countBlank by 1
        if (inputString[i] == ' ') countBlank++;
    }
    //if the whole input string just contained only blanks, return 0
    if (countBlank == strlen(inputString)) {
        printf("The input string cannot blank. Please re-enter:\n");
        return 0;
    }
    return 1;
}

void inputSize(int &size) {
	char check;
	do {
		printf("Enter the value of n :\n");
		scanf("%d",&size);
		check = getchar();
 		fflush(stdin);
	}while (checkNumber(size,check) == 0);
}

void sortStringArray(char **string, int size) {
	inputSize(size);
	string = (char**)realloc(string,size*sizeof(char**));
	printf("Enter %d name :\n", size);
	for(int i = 0; i < size;i++) {
		do  {
			gets(string[i]);
			string[i]=(char*)realloc(string[i],strlen(string[i])*sizeof(char));
		}while(checkElement(string[i]) == 0);
	}
	printf("List input name :\n");
	for(int i = 0; i < size; i++) {
		printf("%d. ",i + 1);
		puts(string[i]);	
	}
	bubble(string,size);
	printf("List sort name :\n");
	for(int i = 0; i < size; i++) {
		printf("%d. ", i+1);
		puts(string[i]);
	}
}
int main() {
	printf("String Array Manipulations(Sort String Array).\n");
	char **string=(char**)malloc(50*sizeof(char*));
	for (int i = 0; i < 50; i++) {
		string[i]=(char*)malloc(50*sizeof(char));
	}
	int size;
	sortStringArray(string,size);
	return 0;
}
	



