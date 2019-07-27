#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//check float tuong tu khac moi phan nhap vao la %lf

int HaveMore(){
    char more;
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

void output(int inputNum) {
    printf("Multiplication table for %d number:\n",inputNum);
    //print multiplication table
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n",inputNum,i,inputNum*i);
    }
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

void multiplicationTable() {
    int inputNum;
    input(inputNum);
    output(inputNum);
}

int main() {
    printf("Program to print multiplication table for input number.\n");
    printf("-------------------------------------------------------\n");
    do{
    	multiplicationTable();
	}while(HaveMore() == true);
	return 0;
    
}
