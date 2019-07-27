#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>

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

int Sum(int inputNum){
	int temp, sum = 0, remaider;
	fflush(stdin);
	temp = inputNum > 0 ? inputNum : -inputNum;
	while(temp != 0){
		remaider = temp % 10;
		sum = sum + remaider;
		temp = temp / 10;
	}	
	printf("Sum digit of integer number %d is %d\n", inputNum, sum);	
}

int checkInput(int inputNum, char check) {
    //if check is character not '\n' => input is not a number, return 0
    if (check != '\n') {
        printf("Data type error.\n");
        return 0;
    }
    //else return 1
    return 1;
}

void input(int &inputNum){
	//char to check input
	char check;
	//loop if check invalid
	do{
		printf("Enter an integer n = ");
		scanf("%d",&inputNum);
        check = getchar();
        //clear buffer
        fflush(stdin);
	}while(checkInput(inputNum,check)==0);
}

void SumDigitNumber(){
	int inputNum;
	input(inputNum);
	Sum(inputNum);
}

int main(){
	printf("Addition of digits in a natural number.\n");
	printf("---------------------------------------\n");
	do{
    	SumDigitNumber();	
	}while(HaveMore() == true);
	return 0;
}


