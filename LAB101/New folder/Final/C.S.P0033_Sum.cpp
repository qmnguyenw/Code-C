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

int sumNumber(double array[], int size){
	double sum = 0;
	for(int i = 0; i < size; i++){
		sum += array[i];
	}
	printf("Sum = %lf\n", sum);
}

int checkSize(int size, char check) {
    if(check != '\n') {
        printf("Data type error. Size must be a natural number. Please re-enter.\n");
        return 0;
    }
    if(size <= 0) {
        printf("Size must be larger than 0.\n");
        return 0;
    }
        return 1;
}

int checkElement(double array[], char check) {
    if(check != '\n') {
        printf("Data type error. Element must be a decimal number. Please re-enter.\n");
        return 0;
    }
    return 1;
}

void createArray(double array[], int &size) {
    char check;
    do {
        printf("Number of element s = ");
        scanf("%d",&size);
        check = getchar();
        fflush(stdin);
    }while(checkSize(size,check) == 0);
    for (int i = 0; i < size; i++) {
        do {
            printf("Enter element[%d]: ",i);
            scanf("%lf",&array[i]);
            check=getchar();
            fflush(stdin);
        }while(checkElement(array,check) == 0);
    }
}


void sumDecimalNumber(){
	double *array = (double*)malloc(100*sizeof(double));//input array - create a dynamic memory
    int size;//input size of array
    createArray(array,size);
    array = (double*)realloc(array,size*sizeof(double));
    sumNumber(array, size);
}

int main(){
    printf("Sum of decimal numbers.\n");
    printf("---------------------------------------------------\n");
    do{
    	sumDecimalNumber();
	}while(HaveMore() == true);
	return 0;
}


