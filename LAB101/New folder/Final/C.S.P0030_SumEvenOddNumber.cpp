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

int sumNumber(int array[], int size){
	int sumOdd = 0;
	int sumEven = 0;
	for(int i = 0; i < size; i++){
		if(array[i] % 2 == 0){
			sumEven += array[i];
		}
		sumOdd += array[i];
	}
	printf("Sum of Odd = %lf\n", sumOdd);
	printf("Sum of Even = %lf\n", sumEven);
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

int checkElement(int array[], char check) {
    if(check != '\n') {
        printf("Data type error. Element must be a natural number. Please re-enter.\n");
        return 0;
    }
    return 1;
}

void createArray(int array[], int &size) {
    char check;
    do {
        printf("Number of element s = ");
        scanf("%d",&size);
        check = getchar();
        fflush(stdin);
    }while(checkSize(size,check) == 0);
    printf("Input elements: ");
    for (int i = 0; i < size; i++) {
        do {
            printf("\tEnter element[%d]: ",i);
            scanf("%d",&array[i]);
            check=getchar();
            fflush(stdin);
        }while(checkElement(array,check) == 0);
    }
}


void sumOddEven(){
	int *array = (int*)malloc(100*sizeof(int));//input array - create a dynamic memory
    int size;//input size of array
    createArray(array,size);
    array = (int*)realloc(array,size*sizeof(int));
    sumNumber(array, size);
}

int main(){
    printf("Sum Odd Even program.\n");
    printf("---------------------------------------------------\n");
    do{
    	sumOddEven();
	}while(HaveMore() == true);
	return 0;
}


