#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int HaveMore(){
    char more;
    bool valid;
    //if user input wrong choice
    do{
        printf("Press 'Y' to continue, press 'N' to exit: ");
        scanf("%c",&more);
        fflush(stdin);
        more = tolower(more);//lower user input
        if(more =='y'){
        	printf("\n");
        	return true;
		} else if(more =='n'){
        	printf("Thanks for using.\n");
			return false;
		} else {
			printf ("Please choice Y/N. Try again.\n");
		}
    }while(more != 'y' && more != 'n');
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

int checkInput(int inputNum, char check) {
    //if check is character not '\n' => input is not a number, return 0
    if (check != '\n') {
        printf("Data type error.\n");
        return 0;
    }
    //if input number out of required range, return 0
    if (inputNum < 1 || inputNum > 9) {
        printf("Input number must be in range (1-9).\n");
        return 0;
    }
    //else return 1
    return 1;
}

void input(int &inputNum) {
    //char to check input
    char check;
    //loop if check invalid
    do {
        printf("Please enter a number (1-9): ");
        scanf("%d",&inputNum);
        check = getchar();
        //clear buffer
        fflush(stdin);
    }while(checkInput(inputNum,check)==0);
}

void ConvertNumberToWord(){
	char *number = (char*)malloc(50 * sizeof(char));//allocate the requested memory
	do{
		printf("Enter a string: ");
		gets(str);
	}while (checkBlank(str) == 0);
	number = (char*)realloc(number,strlen(str)*sizeof(char));//resize the dynamic memory to suitable
}

int main(){
	printf("Program to convert number to word.\n");
	printf("-------------------------------------------------\n");
	do{
		ConvertNumberToWord();
	}while(HaveMore() == true);
	return 0;
}


