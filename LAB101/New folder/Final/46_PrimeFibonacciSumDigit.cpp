#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

void SumDigitNumber(int inputNum){
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

int checkInputSumDigitNumber(int inputNum, char check) {
    //if check is character not '\n' => input is not a number, return 0
    if (check != '\n') {
        printf("Data type error. Please re-enter.\n");
        return 0;
    }
    if(inputNum < 0){
    	printf("Input number must be greater than 0. Please re-enter.\n");
	}
    //else return 1
    return 1;
}

void inputSumDigitNumber(int &inputNum){
	//char to check input
	char check;
	//loop if check invalid
	do{
		printf("Enter an integer: ");
		scanf("%d",&inputNum);
        check = getchar();
        //clear buffer
        fflush(stdin);
	}while(checkInputSumDigitNumber(inputNum,check)==0);
}

void SumDigitNumber(){
	int inputNum;
	inputSumDigitNumber(inputNum);
	SumDigitNumber(inputNum);
}

//second way to check Fibonacci Number if and only if one or both of (5n*n+4) or (5n*n-4) is square number 

void isFibonacci(int inputNum){
	int fibonacci1 = 1, fibonacci2 = 1, fibonacci;
	while(fibonacci1 + fibonacci2 <= inputNum){
		fibonacci = fibonacci1 + fibonacci2;
		fibonacci1 = fibonacci2;
		fibonacci2 = fibonacci;
	}
	//check if inputNum is Fibonacci Number or not
	if(fibonacci == inputNum){
		printf("It is a Fibonacci term.\n");
	}else{
		printf("It is NOT a Fibonacci term.\n");
	}
}

int checkInputIsFibonacciNumber(int inputNum, char check) {
    //if check is character not '\n' => input is not a number, return 0
    if (check != '\n') {
        printf("Data type error. Please re-enter.\n");
        return 0;
    }
    if(inputNum < 0 || inputNum > 1000){
    	printf("Input number must be in range (1-1000). Please re-enter.\n");
	}
    //else return 1
    return 1;
}

void inputCheckFibonacciNumber(int &inputNum){
	//char to check input
	char check;
	//loop if check invalid
	do{
		printf("Number tested: ");
		scanf("%d",&inputNum);
        check = getchar();
        //clear buffer
        fflush(stdin);
	}while(checkInputIsFibonacciNumber(inputNum,check)==0);
}

void checkFibonacciNumber(){
	int inputNum;
	inputCheckFibonacciNumber(inputNum);
	isFibonacci(inputNum);
}

int isPrime(int Number) {
	if(Number < 2) return 0;
	if(Number == 2) return 1;
	for(int i = 2; i < Number; i++) {
		if(Number % i == 0) return 0;
	}
	return 1;
}

void displayPrimes(int inputNum){
	int count = 0, primeNum;
	//display prime number from 2 
	for(primeNum = 2; ; primeNum++){
		//print prime number
		if(isPrime(primeNum) == 1){
			printf("%d\t", primeNum);
			count++;
		}
		if(count == inputNum){
			printf("\n");
			break;
		}
	}
}

int checkInputDisplayPrimeNumbers(int inputNum, char check) {
    //if check is character not '\n' => input is not a number, return 0
    if (check != '\n') {
        printf("Data type error. Please re-enter.\n");
        return 0;
    }
    if(inputNum < 0 || inputNum > 50){
    	printf("Input number must be in range (1-50). Please re-enter.\n");
	}
    //else return 1
    return 1;
}

void inputDisplayPrimeNumbers(int &inputNum){
	//char to check input
	char check;
	//loop if check invalid
	do{
		printf("Number of primes: ");
		scanf("%d",&inputNum);
        check = getchar();
        //clear buffer
        fflush(stdin);
	}while(checkInputDisplayPrimeNumbers(inputNum,check)==0);
}

void displayPrimeNumbers(){
	int inputNum;
	inputDisplayPrimeNumbers(inputNum);
	displayPrimes(inputNum);
}

int checkOption(int option, char check) {
    if(check != '\n') {
        printf("Option must be an integer. Please re-enter.\n");
        return 0;
    }
    if(option < 1 || option > 4){;
    	printf("Option input must be in range (1-4). Please re-enter.\n");
		return 0;
	}
    return 1;
}

void displayMenu(int &option) {
    char check;
    //repeat if user enter invalid option
    do {
    	printf("--------------------------------------\n");
        printf("Choose one of the following options:");
        printf("\n1- Output the first primes of the inputted number.");
        printf("\n2- Check a Fibonacci number.");
        printf("\n3- Sum of digits of a positive natural number.");
        printf("\n4- Exit.");
        printf("\nYour choice: ");
        scanf("%d",&option);
        check = getchar();
        fflush(stdin);
    }while(!checkOption(option,check));
}

int main(){
	printf("Basic Computation Practice.\n\n");
	int option;//option of menu	
    //repeat while user enter option 1 to 3
	do {
		displayMenu(option);
		//process option of user
		switch(option) {
			case 1:
				displayPrimeNumbers();
                break;
            case 2:
                checkFibonacciNumber();
                break;
            case 3:
                SumDigitNumber();
                break;
            case 4:
            	printf("Program stopped.\n");
            	break;
        }
    }while(option >= 1 && option <= 3);
	return 0;
}


