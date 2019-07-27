#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int imax(int a[],int n){
	int max = 0, i;
	//max 
	for (i = 1; i < n; i++){
		if (a[i] > a[max]){
			max = i;
		}
	}
	return max;
}

void output(char letter[], int countLetter[]) {
	int numberLetter;
	printf("Times of appearance for each character: \n");
	//output in screen letter and its number of appearance
	for(int i = 0; i < 94; i++) {
		//output will print the number of letter's apearance which greater than 0
		if (countLetter[i] > 0) printf("\t %c: %d\n",letter[i],countLetter[i]);
	}
	printf("-------------------------------------\n");
	printf("Characters that appears the most:\n");
	int x = imax(countLetter ,94);//max number of letter's appearance in string 
	//find letters that appears the most
	for(int i = 0; i < 94; i++) {
		//if character has its number of appearance equal with the most appearance and it must has number of appearance != 0 
		if (countLetter[i] == countLetter[imax(countLetter ,94)] && countLetter[i] != 0) 
		printf("\t %c: %d\n",letter[i],countLetter[imax(countLetter ,94)]);
	}
}


void count(char str[]) {
	char letter[94];//create a string which include 26 letters in alphabet 
	strcpy(letter,"0123456789abcdefghijklmnopqrstuvwxyz~!@#$%^&*()_+-=?{}[]<>,./'\"'\'\|`;:");
	int countLetter[94] = {0};//create a variable which count the appearance of each letter in string
	int i, j;
	//count the appearance of each letter in string
	for (i = 0; i < 94; i++) {
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
	char exit;
	char *str = (char*)malloc(50 * sizeof(char));//allocate the requested memory
	printf("Program to look up character that appears the most in a string.\n");
	do {
		//input string, if input blank => reinput
		do{
			printf("Enter a string: ");
			gets(str);
		}while (checkBlank(str) == 0);
		str = (char*)realloc(str,strlen(str)*sizeof(char));//resize the dynamic memory to suitable
		toLower(str);//lower charaters 
		count(str);//count the appearance of each letter in string
		do {
			printf("Press enter to continue, ESC to exit");
			exit = getchar();
			fflush(stdin);
		}while(exit != 27 && exit != '\n');
	}while (exit == '\n');
}

int main() {
	countLetter();//start
	return 0;
}

