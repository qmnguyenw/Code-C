#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int output(char letter[], int countLetter[]) {
	//output in screen letter and its number of appearance
	printf("Found characters: ");
	for(int i = 0; i < 26; i++) {
		//output will print the letter which appears in string only one time
		if (countLetter[i] == 1) printf("\t%c",letter[i]);
	}
	printf("\nPress enter to continue.\n");
	getchar();
}

void count(char str[]) {
	char letter[26];//create a string which include 26 letters in alphabet 
	strcpy(letter,"abcdefghijklmnopqrstuvwxyz");
	int countLetter[26] = {0};//create a variable which count the appearance of each letter in string
	int i, j;
	//count the appearance of each letter in string
	for (i = 0; i < 26; i++) {
		for(j = 0; j < strlen(str); j++) {
			if (letter[i] == str[j]) countLetter[i]++;
		} 
	}
	output(letter,countLetter);
}

void toLower(char str[]) {
	//lower each character
	for (int i = 0; i < strlen(str); i++) {
		str[i] = tolower(str[i]);
	}
}

int checkBlank(char str[]) {
	int countBlank;
	for (int i = 0; i < strlen(str); i++){
		if (str[i] == ' ') countBlank++;
	}
	//if input full of blank => re-input string
	if (countBlank == strlen(str)) {
		printf("The string is empty.\nPlease reenter a string.\n");
		return 0;	
	}else return 1;
}

void countLetter() {
	char *str = (char*)malloc(100 * sizeof(char));//allocate the requested memory
	str = (char*)realloc(str,strlen(str)*sizeof(char));//resize the dynamic memory to suitable
	//input string, if input blank => reinput
	printf("\nLook up all characters appear one time in a string.\n");
	do{
		printf("Enter a string: ");
		gets(str);
	}while (checkBlank(str) == 0);
	toLower(str);//lower charaters 
	count(str);//count the appearance of each letter in string
}

int main() {
	while(true){
		countLetter();//start
	}
	return 0;
}
