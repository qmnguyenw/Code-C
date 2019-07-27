#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int checkSize(int size, char check) {
    if(check != '\n') {
        printf("Size must be an integer. Please re-enter.\n");
        return 0;
    }
    if(size <= 0) {
        printf("Size must be larger than 0.\n");
        return 0;
    }
        return 1;
}

int checkElement(int element, char check) {
    if(check != '\n') {
        printf("Size must be an integer. Please re-enter.\n");
        return 0;
    }
    return 1;
}

void createArray(int *array, int &size) {
    //char to check input
    char check;
    //repeat if size is invalid
    do {
        printf("Please enter size of array: ");
        scanf("%d",&size);
        check = getchar();
        fflush(stdin);
    }while(!checkSize(size,check));
    //from first to last element in array
    for (int i = 0; i < size; i++) {
        //repeat if user enter invalid element
        do {
            printf("Enter element[%d]: ",i);
            scanf("%d",&array[i]);
            check=getchar();
            fflush(stdin);
        }while(!checkElement(array[i],check));
    }
    printf("\nArray Elements: \n");
    //display array user have entered
    for (int i = 0; i < size; i++) {
        printf("%d\t",array[i]);
    }
    printf("\n");
}

void maxValue(int *array, int size){
	int max = 0;
	for (int i = 0; i < size; i++){
		if(array[i] > array[max]){
			max = i;
		}
	}
	printf("\nArray maximum value: \n");
	printf("The max is %d\n", array[max]);
}

void evenValue(int *array, int size){
	printf("\nArray even values:\n");
	for (int i = 0; i < size; i++){
		if ((array[i] % 2) == 0){
			printf("%d\t",array[i]);
		}
	}
}

int main(){
	printf("Array Manipulations.\n\n");
    int *array = (int*)malloc(100*sizeof(int));//input array will be processed
    int size;//size of array
    createArray(array,size);
    array = (int*)realloc(array,size*sizeof(int));//re-size array for suitable
    maxValue(array,size);
    evenValue(array,size);
	return 0;
}


