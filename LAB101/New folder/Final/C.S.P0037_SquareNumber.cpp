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

int checkSquareNumber(int n){
	fflush(stdin);
	if(n <= 0){
		printf("Please enter a positive integer!\n");
		return 0;
	}else if(n <= 2){
		printf("%d is not a square number\n", n);
	}else{
		for(int i = 0; i < n; i++){
			if(n == i * i){
				printf("%d is a square number %d = %d x %d\n", n, n, i, i);
				break;
			}
			else if(n < i * i){
				printf("%d is not a square number\n", n);		
				break;
			} 
		}
	}
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
		printf("Enter a positive integer n = ");
		scanf("%d",&inputNum);
        check = getchar();
        //clear buffer
        fflush(stdin);
	}while(checkInput(inputNum,check)==0);
}

void SquareNumber(){
	int inputNum;
	//re-input if user input wrong 
	do{
		fflush(stdin);
		input(inputNum);
	}while(checkSquareNumber(inputNum) == 0);
}

int main(){
	printf("Check Square Number Program.\n");
	printf("--------------------------------\n");
	do{
		fflush(stdin);
    	SquareNumber();
	}while(HaveMore() == true);
	return 0;
}


