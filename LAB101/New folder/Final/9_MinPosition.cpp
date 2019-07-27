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
}

int imin(int a[],int n){
	int min = 0, i;
	for (i = 1; i < n; i++){
		if (a[i] < a[min]){//tim so nho nhat dau tien trong day
			min = i;
		}
	}
	return min;
}

void SmallestNumberItsPosition(int *array, int size){
	int positionMin = 0;
	for (int i = 0; i < size; i++){
		if (array[i] < array[positionMin]){
			positionMin = i;
		}
	}
	int min = array[positionMin];
	printf("\nThe smallest element: %d - Its position: ",min);
	for (int i = 0; i < size; i++){
		if (min == array[i]){
			printf("%d \t", i);
		}
	}
}

int main(){
	printf("Look up the smallest element position in a real array.\n\n");
    int *array = (int*)malloc(100*sizeof(int));//input array will be processed
    int size;//size of array
    createArray(array,size);
    array = (int*)realloc(array,size*sizeof(int));//re-size array for suitable
    SmallestNumberItsPosition(array,size);
	return 0;
}


