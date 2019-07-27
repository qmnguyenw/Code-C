#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const char *Path = "SlotMachine.txt";
FILE * f;

void convertNum(char stringDigit[],int &convertedNumber) {
    int dozen = 1;//positional value
    convertedNumber = 0;
    //convert String into Number
    for(int i = strlen(stringDigit) - 1; i >= 0; i--) {
        //if converted number is negative
        if(stringDigit[i] == '-') {
            convertedNumber *= (-1);
            break;
        }
        //sum of positional value times each digit in stringDigit
        convertedNumber += dozen * (stringDigit[i]-48);
        //positional value times 10 each loop
        dozen*=10;
    }
}

int checkChoice(char stringChoice[], int &choice) {
    //check if input has non-number charater
    for(int i = 0; i < strlen(stringChoice); i++) {
        //if there is an non-digit element, return 0
        if(isdigit(stringChoice[i]) == 0) {
            printf("Data type error.\nYour choice must be an integer in menu.\nPlease re-enter.");
            return 0;
        }
    }
    //convert from string to integer
    convertNum(stringChoice,choice);
    if (choice < 1 || choice > 3) {
        printf("Out of required range.\nYour choice must be in range [1,3].\nPlease re-enter.");
        return 0;
    }else return 1;
}

void saveCash(double &cash) {
    f = fopen(Path,"w");
    fprintf(f,"%lf",cash);
    fclose(f);
    printf("Your money had saved!");
}

int checkdigit(int a, int b, int c) {
    //if 3 digits are equal to each other, return 3
    if(a == b and b == c) return 3;
    //if 2 in 3 digits are equal
    else if (a == b or a == c or b == c) return 2;
    //if 3 digits are different
    else return 1;
}

void game(int a, int b, int c, double &cash) {
    a = rand()%10;    b = rand()%10;    c = rand()%10;
    printf("The slot machine shows %d%d%d",a,b,c);
    if(checkdigit(a,b,c) == 3) {
        printf("\nYou win the big prize,$10.00!\n");
        cash+=9.75;
        printf("You have $%.2lf.",cash);
    }
    if(checkdigit(a,b,c) == 2) {
        printf("\nYou win 50 cents!\n");
        cash+=0.25;
        printf("You have $%.2lf.",cash);
    }
    if (checkdigit(a,b,c) == 1) {
        printf("\nSorry you don't win anything.\n");
        cash-=0.25;
        printf("You have $%.2lf.",cash);
    }
}

void loadCash(double &cash) {
    f = fopen(Path,"r");
    fscanf(f,"%lf",&cash);
    fclose(f);
}

void SlotMachine() {
    int choice;//choice of player
    char stringChoice[10]; //input choice player enter
    double cash;
    loadCash(cash);//load the cash player left
    if(int(cash)==0) cash = 10;//if player new, cash = $10.00
    printf("You have $%.2lf.",cash);
    int a,b,c;//random numbers;
    srand(time(NULL));//random different number by time
    //repeat until cash = 0 or player enter choice = 3
    do {
        //repeat this if checkChoice return 0
        do {
            printf("\nChoose one of the following menu options:");
            printf("\n1) Play the slot machine.");
            printf("\n2) Save game.");
            printf("\n3) Cash out.\n");
            gets(stringChoice);
        }while(checkChoice(stringChoice,choice) == 0);
        switch(choice){
            case 1:
                game(a,b,c,cash);
                break;
            case 2:
                saveCash(cash);
                break;
            case 3:
                printf("Thank you for playing! You end with $%.2lf",cash);
        }
    }while(choice != 3 and cash != 0);
}

int main() {
    SlotMachine();
}
