#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

void swap (int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

void bubbleDesSort(int array[], int size) { 
	//from the first element in array to the last one 
   	for (int i = 0; i < size-1; i++){
   		//after each loop the smallest element in checked range has been set on correct place
   		//check each element in array except the element has been set on correct place
       	for (int j = 0; j < size-i-1; j++){
       		//repeatedly swapping the adjacent elements if they are in wrong order
       		if (array[j] < array[j+1]){
       			swap(array[j], array[j+1]); 
			} 
		}  
   	}            
} 

void bubbleAscSort(int array[], int size) { 
	//from the first element in array to the last one 
   	for (int i = 0; i < size-1; i++){
   		//after each loop the smallest element in checked range has been set on correct place
   		//check each element in array except the element has been set on correct place
       	for (int j = 0; j < size-i-1; j++){
       		//repeatedly swapping the adjacent elements if they are in wrong order
       		if (array[j] > array[j+1]){
       			swap(array[j], array[j+1]); 
			} 
		}  
   	}            
} 

void sortArray(int array[], int size){
	bubbleAscSort(array,size);
	printf("The array sorted in ascending:\n");
	for(int i = 0; i< size; i++){
		printf("%d\t", array[i]);
	}
	bubbleDesSort(array,size);
	printf("\nThe array sorted in descending:\n");
	for(int i = 0; i< size; i++){
		printf("%d\t", array[i]);
	}
}

int checkElement(int element, char check) {
    if(check != '\n') {
        printf("Data type error. Element must be a natural number. Please re-enter.\n");
        return 0;
    }
    return 1;
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

void createArray(int array[], int &size) {
    char check;
    do {
        printf("Number of element s = ");
        scanf("%d",&size);
        check = getchar();
        fflush(stdin);
    }while(checkSize(size,check) == 0);
    printf("Input elements: \n");
    for (int i = 0; i < size; i++) {
        do {
            printf("\tEnter element[%d]: ",i);
            scanf("%d",&array[i]);
            check=getchar();
            fflush(stdin);
        }while(checkElement(array[i],check) == 0);
    }
}

int main(){
	printf("Sort an array in ascending and descending order.\n\n");
	int *array = (int*)malloc(100*sizeof(int));//input array - create a dynamic memory
    int size;//input size of array
    createArray(array,size);
    array = (int*)realloc(array,size*sizeof(int));
    sortArray(array,size);
	return 0;
}


