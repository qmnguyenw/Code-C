#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int check(char letter, char word[30], char puzzle[60]) {
	for (int i = 0; i < strlen(word); i++) {
		if(toupper(letter) == word[i] && toupper(letter) != puzzle[2*i]) return 1;
		if(toupper(letter) == word[i] && toupper(letter) == puzzle[2*i]) return -1;
	}
	return 0;
}

int checkwin(char puzzle[], char word[]) {
	int i;
	for(i = 0; i < 2 * strlen(word); i++) {
		if (puzzle[i] == '_') return 0;
	}
	return 1;
}
int main() {
	//create file in the same folder with file .cpp
	const char *Path = "words.txt";
	FILE *f;
	char filename[100];
	//loop if player enter the wrong file name
	do {
	printf("What file stores the puzzle words?\n");
	gets(filename);
	if (strcmp(filename,"words.txt") != 0) printf("\nThe file not exist, please try again.\n\n");
	} while(strcmp(filename,"words.txt") != 0);
	//indexes
	int i,j,k;
	// create guessed words
	char listinfile[30000] = "MALL FOOTBALL FEMALE UNIVERSITY GAME PROGRAMMING";
	//2 dimension string which will contains words to exucute
	char gword[1001][30];
	//number of words
	int n;
	//string contain words to load intp 2 dimension string above
	char listword[30000];
	char puzzle[60];
	//choice yes or no
	char choice[3];
	//write list of words into file
	f = fopen(Path,"w");
		fputs(listinfile,f);
	fclose(f);
	//read list of words in file and assign into a 2-dimension string array
	f = fopen(Path,"r");
		//read words into a string
		fgets(listword,30000,f);
		//split words in string and assign into 2-dimension string array
		i = 0; j = 0; k = 0; //i: index of word in gword array
							 //j: index of character is each word
							 //k: index of character in listword string
		n = 1;
		while(k < strlen(listword)) {
			gword[i][j] = listword[k];
			j++;
			k++;
			//if listword[k] is a space then increase k, increase index of word, reset index of character in new word to 0
			if (listword[k] == ' ') {
				k++;
				i++;
				j = 0;
				n++;
			}
		}
	fclose(f);
	//loop until choice == no
	do {
		//assign the puzzle (string of underscore)
		strcpy(puzzle,"_ _ _ _ _ _ _ _ _ _ _");
		printf("\nWould you like to play hangman (yes,no)?\n");
		gets(choice);
		//if choice is yes
		if (strcmp(choice,"yes") == 0) {
			//random different values by time
			srand(time(NULL));
			int fail = 0;
			int random = rand() % n; //random the index of guessed word
			//word used in game
			char word[30];
			strcpy(word,gword[random]);
			//length of the guessed word
			int len = strlen(word);
			//loop until player have 5 misses
			do {
				printf("\nYou currently have %d incorrect guesses.",fail);
				printf("\nHere is your puzzle:\n\n");
				//output the current puzzle
				for (i = 0; i < 2*len; i ++) {
					printf("%c",puzzle[i]);
				}
				printf("\n\nPlease enter your guess.\n");
				char letter;
				//player enter guessed letter
				scanf("%c",&letter);
				fflush(stdin);
				//when player guess a correct letter
				if (check(letter,word,puzzle) == 1) {
					for(i = 0; i < len; i++) {
						if(toupper(letter) == word[i]) puzzle[2*i]= toupper(letter);
					}
					//check whether the player have guessed the whole word or not
					if(checkwin(puzzle,word) == 1) {
					printf("\nCongratulations! You got the correct word, %s",word);
					}
					else printf("\nCongratulations, you guessed a letter in the puzzle!");
				//when player guess an appeared letter
				}else if (check(letter,word,puzzle) == -1) {
					printf("\nSorry, you have guessed that letter already.");
					printf("\nNow it count as a miss.");
					fail++;
				//when player guess a wrong letter
				}else {
					printf("\nSorry, that letter is NOT in the puzzle");
					fail++;
				}
				if (fail == 5) {
					printf("\nSorry, you have made 5 incorrect guesses, you lose.");
					printf("\nThe corret word was %s",word);
				}
				printf("\n");
			}while (fail < 5 and checkwin(puzzle,word) == 0);
	}else if (strcmp(choice,"no") == 0) printf("\nThanks for playing!");
	else printf("\nYour choice is invalid, please re-enter.");
	}while (strcmp(choice,"yes") == 0 or (strcmp(choice,"yes") != 0 and strcmp(choice,"no") != 0));
}
