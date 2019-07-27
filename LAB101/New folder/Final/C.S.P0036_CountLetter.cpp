#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void output(char letter[], int countLetter[]) {
	//output in screen letter and its number of appearance
	for(int i = 0; i < 26; i++) {
		//output will print the number of letter's apearance which greater than 0
		if (countLetter[i] > 0) printf("\t %c: %d\n",letter[i],countLetter[i]);
	}
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
	printf("Count the number of the appearance of letters in a string.\n");
	//input string, if input blank => reinput
	do{
		printf("Enter a string: ");
		gets(str);
	}while (checkBlank(str) == 0);
	str = (char*)realloc(str,strlen(str)*sizeof(char));//resize the dynamic memory to suitable
	toLower(str);//lower charaters 
	count(str);//count the appearance of each letter in string
}

int main() {
	countLetter();//start
	return 0;
}
