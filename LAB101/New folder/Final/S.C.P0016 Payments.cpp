#include<stdio.h>

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


main() {
	printf("Payment.\n\n");
	float loan, rate, payment;
	int month = 1;
	printf("what is the value left on the mortage?\n");
//	scanf("%f",&loan);
	inputRealElement(loan);
	printf("what is the annual interest rate of loan, in percent?\n");
//	scanf("%f",&rate);
	inputRealElement(rate);
	printf("what is the only payment\n");
//	scanf("%f",&payment);
	inputRealElement(payment);
	
	printf("Month\tPayment\tAmount Owed\n");
	while(loan > 0) {		
		loan = loan + loan*(rate/1200) - payment;
		printf("%d\t%.2f\t%.2f\n",month,payment,loan);
		month++;
		if(loan < payment) {
//			payment =  loan + loan*(rate/1200);
			break;
		}
	}
	//last month 
	payment =  loan + loan*(rate/1200);
	loan = 0;
	printf("%d\t%.2f\t%d\n",month,payment,loan);
}
