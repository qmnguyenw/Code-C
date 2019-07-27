#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int checkYear(int inputNum, char check) {
    //if check is character not '\n' => input is not a number, return 0
    if (check != '\n') {
        printf("Data type error.\n");
        return 0;
    }
    //if input number out of required range, return 0
    if (inputNum < 0 || inputNum > 9999) {
        printf("Input number must be in range (1-9999).\n");
        return 0;
    }
	return 1;
}

void inputYear(int &inputNum) {
    char check;
    //loop if check invalid
    do {
    	printf("\tYear: ");
        scanf("%d",&inputNum);
        check = getchar();
        //clear buffer
        fflush(stdin);
    }while(checkYear(inputNum,check)==0);
}

int checkMonth(int inputNum, char check) {
    //if check is character not '\n' => input is not a number, return 0
    if (check != '\n') {
        printf("Data type error.\n");
        return 0;
    }
    //if input number out of required range, return 0
    if (inputNum < 1 || inputNum > 12) {
        printf("Input number must be in range (1-12).\n");
        return 0;
    }
	return 1;
}

void inputMonth(int &inputNum) {
    char check;
    //loop if check invalid
    do {
    	printf("\tMonth: ");
        scanf("%d",&inputNum);
        check = getchar();
        //clear buffer
        fflush(stdin);
    }while(checkMonth(inputNum,check)==0);
}

int checkDay(int inputNum, char check) {
    //if check is character not '\n' => input is not a number, return 0
    if (check != '\n') {
        printf("Data type error.\n");
        return 0;
    }
    //if input number out of required range, return 0
    if (inputNum < 1 || inputNum > 31) {
        printf("Input number must be in range (1 - 31).\n");
        return 0;
    }
	return 1;
}

void inputDay(int &inputNum) {
    char check;
    //loop if check invalid
    do {
    	printf("\tDay: ");
        scanf("%d",&inputNum);
        check = getchar();
        //clear buffer
        fflush(stdin);
    }while(checkDay(inputNum,check)==0);
}

int checkOption(int option, char check) {
    if(check != '\n') {
        printf("Option must be an integer. Please re-enter.\n");
        return 0;
    }
    if (option < 1 || option > 3) {
        printf("Input number must be in range (1-3).\n");
        return 0;
    }
        return 1;
}

void displayMenu(int &option){
	char check;
	do {
		printf("MENU\n");
		printf("-------------------------------------------\n");
		printf("Choose one of the following options:\n");
		printf("1- Processing date data\n");
		printf("2- Charater data\n");
		printf("3- Quit\n");
		printf("Your choice: ");
        scanf("%d",&option);
        check = getchar();
        fflush(stdin);
	}while(!checkOption(option,check));
}

void checkDate() {
	int check = 1;
	int day, month, year;
	printf("Enter the date you want to check: \n");
	inputDay(day);
	inputMonth(month);
	if((month == 4 || month == 6 || month == 9 || month ==11)&&
			(day == 31)){
				printf("It's not a day of the year.\n");
				check = 0;
			}
	else if((month == 2)&&(day >29)){
		printf("It's not a day of the year.\n");
		check = 0;
	}
	if(check == 1){
		inputYear(year);
		printf("The date you entered dd-mm-yy: %d-%d-%d\n",day,month,year);
		//situation a month has 31 days
		if((day <= 31 && day >= 1) && (year >= 1 && year <= 9999) &&
			(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)){
			printf("It's a day of the year\n");
		}
		//situation a month has 30 days
		else if((day <= 30 && day >= 1) && (year >= 1 && year <= 9999) &&
				(month == 4 || month == 6 || month == 9 || month ==11))	{
			printf("It's a day of the year\n");
		}
		//situation of February - 28 days if year input is not leap year
		else if((day <=28 && day >=1) && (month == 2) && (year >= 1 && year <= 9999)) {
			printf("It's a day of the year\n");
		}
		//situation of February - 29 days if year input is leap year
		else if((day <= 29 && day >= 1) && (day >= 1 && year <= 9999) &&
			(year % 400 == 0 || (year % 4 == 0) && (year % 100 !=0))) {
			printf("It's a day of the year\n");
		}
		else {
			printf("That is not a day of the year\n");
		}
	}		
	
}

int checkInput(char str[]) {
	int countBlank;
	for (int i = 0; i < strlen(str); i++){
		if (str[i] == ' ') countBlank++;
	}
	//if input full of blank => re-input string
	if (countBlank == strlen(str)) {
		printf("The string is empty.\nPlease reenter a string.\n");
		return 0;	
	}
	//if input more than 2 characters
	if(strlen(str) != 2){
		printf("The string input must has 2 characters.\nPlease re-enter a string.\n");
		return 0;
	}
	return 1;
}

int main(){
	printf("Using a simple menu to manage program functions.\n\n");
	int option;
	do{
		displayMenu(option);
		switch(option){
			case 1:{
				checkDate();
				break;
			}
			case 2:{
				char *str = (char*)malloc(100 * sizeof(char));//allocate the requested memory
				char firstChar, secondChar;
				fflush(stdin);
				//input string 
				do{
					printf("Input two characters: ");
					gets(str);
				}while (checkInput(str) == 0);//check input
				str = (char*)realloc(str,strlen(str)*sizeof(char));//resize the dynamic memory to suitable
				//get character
				firstChar = str[0];
				secondChar = str[1];
				//situation first character has ASCII
				if(firstChar <= secondChar) {
					for (char i = secondChar ; i >= firstChar; i--) {
						printf("%c : %d\n",i,i);
					}
				}else {
					for (char j = firstChar ; j >= secondChar ; j--) {
						printf("%c : %d\n",j,j);
					}
				}
				break;
			}
			case 3:{
				printf("Thanks for using!");
				break;
			}
		}
	}while(option >= 1 && option < 3);
	return 0;
}


