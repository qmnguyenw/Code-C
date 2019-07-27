#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int checkArray(char check) {
    if(check != '\n') {
        printf("Size must be an integer. Please re-enter.\n");
        return 0;
    }
    return 1;
}

void createArray(int *array, int &size) {
    char check;
	printf("Enter the element of array\n");
	/* Enter the value in the array until it encounters 0 then break and 
	assign it to rank check input array*/
	for (int i = 0;i < 100 ; i++) {
		scanf("%d", &array[i]);
		size = i;
		check = getchar();
		fflush(stdin);
		if (checkArray(check) == 0) {
			i--;
		}
		if(array[i] == 0) break;
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


