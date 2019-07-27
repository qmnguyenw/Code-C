#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int checkRealInputElement(float inputNum, char check) {
    //if check is character not '\n' => input is not a number, return 0
    if (check != '\n') {
        printf("Data type error.\n");
        return 0;
    }
    //if input number out of required range, return 0
    if (inputNum < 0) {
        printf("Input number must be greater than 0.\n");
        return 0;
    }
    //else return 1
    return 1;
}

int inputRealElement(float &inputNum) {
    //char to check input
    char check;
    //loop if check invalid
    do {
        scanf("%f",&inputNum);
        check = getchar();
        fflush(stdin);
    }while(checkRealInputElement(inputNum,check)==0);
}

int checkIntInputElement(int inputNum, char check) {
    //if check is character not '\n' => input is not a number, return 0
    if (check != '\n') {
        printf("Data type error.\n");
        return 0;
    }
    //if input number out of required range, return 0
    if (inputNum < 0) {
        printf("Input number must be greater than 0.\n");
        return 0;
    }
    //else return 1
    return 1;
}

int inputIntElement(int &inputNum) {
    //char to check input
    char check;
    //loop if check invalid
    do {
        scanf("%d",&inputNum);
        check = getchar();
        //clear buffer
        fflush(stdin);
    }while(checkIntInputElement(inputNum,check)==0);
//    return inputNum;
}

void option3(){
	int v;
	float g, r;
	printf("\nYour choice : 3\n\n");
	printf("Enter radius of the car's tires: \n");
	inputRealElement(r);
	printf("Enter number of revolutions the car's tires : \n");
	inputIntElement(v);
	printf("Enter amount of gas, in gallons, the car uses: \n");
	inputRealElement(g);
	printf("Your car arveged %.2f miles\n",r*2*3.14*v*0.00001579/g);
}

void option2(){
	float r;
    int v;
    printf("\nYour choice : 2\n\n");
    printf("Enter radius of the tires: \n");
    inputRealElement(r);
    printf("Enter number of revolutions of the tires: \n");
	inputIntElement(v);
    printf("your car tralved %.2f miles\n",r*2*3.14*v*0.00001579);
} 

void option1(){
	int m;
    float s,g;
    fflush(stdin);
	printf("\nYour choice : 1\n\n");
	printf("Enter number of minutes the car has traveled: \n");
	inputIntElement(m);
	printf("Enter speed of the car: \n")
	inputRealElement(s);
	printf("Enter gasoline consumed: \n");
	inputRealElement(g);
	printf("Your car averaged %.2f miles per gallon\n",s*(m/60.00)/g);
}

int checkInputOption(int option, char check) {
    //if check is character not '\n' => input is not a number, return 0
    if (check != '\n') {
        printf("Data type error. Please re-input.\n");
        return 0;
    }
    //if input number out of required range, return 0
    if (option < 1 || option > 4) {
        printf("Input number must be in range (1-4).\n");
        return 0;
    }
    //else return 1
    return 1;
}

int inputOption(int &option) {
    //char to check input
    char check;
    //loop if check invalid
    do {
        printf("Enter your option (1-4): ");
        scanf("%d",&option);
        check = getchar();
        //clear buffer
        fflush(stdin);
    }while(checkInputOption(option,check)==0);
    return option;
}

int menu(){
	int option;
    printf("\n*****************************************\n");
    printf("Choose one of the following menu options:\n");
    printf("1. Calculating Fuel Economy.\n");
    printf("2. Calculating Distance Traveled.\n");
    printf("3. Revised Fuel Economy Calculation.\n");
    printf("4. Exit.\n");
    option = inputOption(option);
    return option;
}

void FuelEconomy(){
	int option;
	//repeat to get user's option
	while (true){
		option = menu();
		if (option == 1){
			option1();
		}
		else if (option == 2){
			option2();
		}
		else if (option == 3){
			option3();
		}
		else {
			printf("Program stoped.\n");
            break;
		}
	}
}

int main() {
	printf("Fuel Economy.\n");
	FuelEconomy();
	return 0;
}	

