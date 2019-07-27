#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

void removeAt(int *array, int &size, int removeIndex) {
    //from first to last element in array
    for(int i = removeIndex; i < size-1; i++) {
        //assign right value to left value
        array[i]=array[i+1];
    }
    size--;//decrease size
}

void deleteDuplicateElement(int array[], int size){
	printf("\nThe original array:\n");
    //display array user have entered
    for (int i = 0; i < size; i++) {
        printf("%d\t",array[i]);
    }
    
    //from the first element to the nearly last one in array
    for (int i = 0; i < size-1; i++){
    	//from the element after i to the last one in array
    	for (int j = i + 1; j < size; j++){
    		//if after i has any element equal with a[i], remove it 
    		if (array[i] == array[j]) {
    			removeAt(array,size,j);
    			j--;//in case when >= 2 duplicate element next to each other
			}
		}
	}
	
	printf("\nThe array after removing duplicate elements:\n");
	for (int i = 0; i < size; i++) {
        printf("%d\t",array[i]);
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
	printf("Delete duplicate elements in an array.\n\n");
    int *array = (int*)malloc(100*sizeof(int));//input array will be processed
    int size;//size of array
    createArray(array,size);
    array = (int*)realloc(array,size*sizeof(int));//re-size array for suitable
    deleteDuplicateElement(array,size);
	return 0;
}


