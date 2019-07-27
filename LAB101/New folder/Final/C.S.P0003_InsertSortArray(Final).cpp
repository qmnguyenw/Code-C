#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

void insert(int array[], int &size, int value, int position){
	//if position of insert value is out of range of position elements in array stop function
	if (position < 0 || position > size) return;
	size++;//size of array increase 1 after insert element 
	//from the last position in array to the position of insert element
	for (int i = size-1; i > position-1; i--){
		array[i] = array[i-1];//shift the element after the position of insert element to next position
	}
	array[position] = value;//transfer value of insert element to its position
}

int checkElement(int element, char check) {
    if(check != '\n') {
        printf("Data type error. Element must be a natural number. Please re-enter.\n");
        return 0;
    }
    return 1;
}

void inputNewValue(int &insertValue){
	char check;
	printf("\n");
	//loop to get correct type of input
	do{
		printf("Please enter new value: ");
        scanf("%d",&insertValue);
        check = getchar();
        fflush(stdin);
    }while(checkElement(insertValue,check) == 0);
}

void InsertSortNewValue(int array[], int size){
	int insertValue;
	inputNewValue(insertValue);
	printf("New array: \n");
	int beforeSize = size;//create a variable equal size before insert new element
	array = (int*)realloc(array,(size+1)*sizeof(int));//re-size of array after insert new element
	//from the last element to the first one in array 
	for(int i = size-1; i >= 0; i--){
		//insert element on postion which had value less than new element 
		if(array[i] <= insertValue){
			insert(array,size,insertValue,i+1);
			break;
		}
	}
	if(size == beforeSize) insert(array, size, insertValue, 0);//situation if insert element is the smallest
	for(int i = 0; i < size; i++){
		printf("%d\t", array[i]);
	}
}

void swap (int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

void bubbleSort(int array[], int size) { 
	//from the first element in array to the last one 
   	for (int i = 0; i < size-1; i++){
   		// from the first element to the nearly last one (Last i elements are already in place after the first loop)
       	for (int j = 0; j < size-i; j++){
       		//repeatedly swapping the adjacent elements if they are in wrong order
       		if (array[j] > array[j+1]){
       			swap(array[j], array[j+1]); 
			} 
		}  
   	}            
} 

void sortArray(int array[], int size){
	bubbleSort(array,size);
	printf("The array after sorting:\n");
	for(int i = 0; i< size; i++){
		printf("%d\t", array[i]);
	}
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
	printf("Program to insert new element into an existing array.\n\n");
	int *array = (int*)malloc(100*sizeof(int));//input array - create a dynamic memory
    int size;//input size of array
    createArray(array,size);
    array = (int*)realloc(array,size*sizeof(int));
    sortArray(array,size);
	InsertSortNewValue(array,size);
	return 0;
}


