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
    if (inputNum <= 0) {
        printf("Input number must be greater than 0.\n");
        return 0;
    }
    if (inputNum >= 500){
    	printf("Input number out of range. Please input number less than 500.");
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
    if (inputNum <= 0) {
        printf("Input number must be greater than 0.\n");
        return 0;
    }
    if (inputNum >= 10000){
    	printf("Input number out of range. Please input number less than 10000.");
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
}

void WeddingInvitation(){
	float priceSmallPackage, priceLargePackage, sum;
	int invitation, countSmallPackage, countLargePackage;
	printf("What is the cost of a small package (in dollars)?\n");
	inputRealElement(priceSmallPackage);
//	scanf("%f", priceSmallPackage);
	printf("What is the cost of a large package (in dollars)?\n");
	inputRealElement(priceLargePackage);
//	scanf("%f", priceLargePackage);
	printf("How many invitations are you sending out?\n");
	inputIntElement(invitation);
//	scanf("%d", invitation);
//	fflush(stdin);
	if (invitation <=  50){
		countSmallPackage = 1;
		countLargePackage = 0;
	}
	if (invitation > 50 && invitation <= 200){
		countLargePackage = 1;
		countSmallPackage = 0;
	}
	if (invitation > 200){
		countSmallPackage = 0;
		countLargePackage = invitation / 200;
		if ((invitation % 200) > 50) {
			countLargePackage++;
		}
			
		if ((invitation % 200) <= 50 && (invitation % 200) > 0){
			countSmallPackage ++;
		}
			
	}
	sum = countSmallPackage * priceSmallPackage + priceLargePackage * countLargePackage;
	printf("\nYou should order %d small package(s).\n", countSmallPackage);
	printf("You should order %d large package(s).\n", countLargePackage);
	printf("Your cost for invitations will be $%.2f.", sum);
}

int main(){
	printf("Wedding Invitations.\n");
	printf("---------------------------------------------------\n");
	WeddingInvitation();
	return 0;
}


