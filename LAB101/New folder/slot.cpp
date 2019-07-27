#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const char *Path = "SlotMachine.txt";
FILE * f;

int checkNumber(int inputNum, char stringChoice) {
    //if check is character not '\n' => input is not a number, return 0
    if (stringChoice != '\n') {
        printf("Data type error.\n");
        return 0;
    }
    //if input number out of required range, return 0
    if (inputNum < 1 || inputNum > 3) {
        printf("Input number must be in range(1,3).\n");
        return 0;
    }
    //else return 1
    return 1;
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
    char stringChoice; //input choice player enter
    double cash;
    loadCash(cash);//load the cash player left
    if(cash==0) cash = 10;//if player new, cash = $10.00
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
            scanf("%d",&choice);
            stringChoice = getchar();
        }while(checkNumber(choice, stringChoice) == 0);
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
