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
    printf("This is the array you have entered:\n");
    //display array user have entered
    for (int i = 0; i < size; i++) {
        printf("%d\t",array[i]);
    }
    printf("\n");
}

int checkOption(int option, char check) {
    if(check != '\n') {
        printf("Option must be an integer. Please re-enter.\n");
        return 0;
    }
        return 1;
}

void displayMenu(int &option) {
    char check;
    //repeat if user enter invalid option
    do {
    	printf("--------------------------------------\n");
        printf("Choose one of the following options:");
        printf("\n1- Add a value.");
        printf("\n2- Search a value.");
        printf("\n3- Print out the array.");
        printf("\n4- Print out values in a range of inputted min and max values, inclusively.");
        printf("\n5- Sort the array in ascending order.");
        printf("\nOthers- Quit\n");
        printf("Your choice: ");
        scanf("%d",&option);
        check = getchar();
        fflush(stdin);
    }while(!checkOption(option,check));
}

void addNewValue (int *array, int &size) {
    int newValue;
    char check;
    //repeat if user enter invalid element
    do {
        printf("Please enter insert value: ");
        scanf("%d",&newValue);
        check = getchar();
        fflush(stdin);
    }while(checkElement(newValue,check) == 0);
    array = (int*)realloc(array,(size+1)*sizeof(int));
    //add new value to array
    array[size++] = newValue;
    printf("New value has been added!\n");
}

void searchValue(int *array, int size) {
    int searchValue;
    char check;
    int count = 0;//count the appearance of search value
    //repeat if user enter invalid value
    do {
        printf("Please enter search value: ");
        scanf("%d",&searchValue);
        check = getchar();
        fflush(stdin);
    }while(!checkElement(searchValue,check));
    printf("Found index(es) of %d(count from 0):",searchValue);
    //from first to last element in array
    for (int i = 0; i < size; i++) {
        //if input value appear in array
        if(searchValue == array[i]) {
            printf("\t%d",i);//output its position
            count++;//increase number of occurrences
        }
    }
    //if input number not in array, display notification
    if(count == 0) printf("\tNothing\nThe array does not contain your search value\n");
    else printf("\n");
}

void displayArray(int *array, int size) {
    printf("The current array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t",array[i]);
    }
    printf("\n");
}

void displayValueInRange(int *array, int size){
	int maxValue, minValue;
	char check;
	int count = 0;
	//repeat if user enter invalid value
	do {
		do {
	        printf("Please enter max value: ");
	        scanf("%d",&maxValue);
	        check = getchar();
	        fflush(stdin);
	    }while(!checkElement(maxValue,check));
    	do {
	        printf("Please enter min value: ");
	        scanf("%d",&minValue);
	        check = getchar();
	        fflush(stdin);
	    }while(!checkElement(minValue,check));
	}while(maxValue <= minValue);
	printf("All values in a range of %d and %d appearance in array:", minValue, maxValue);
	//from first to last element in array
    for (int i = 0; i < size; i++) {
        //if input value appear in array
        if(array[i] >= minValue && array[i] <= maxValue) {
            printf("\t%d",array[i]);
            count++;//increase number of occurrences
        }
    }
    //if input number not in array, display notification
    if(count == 0) printf("\tNothing\nThe array does not contain your input range\n");
    else printf("\n");
	
}

void swap (int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

void bubbleAscSort(int array[], int size) { 
	//from the first element in array to the last one 
   	for (int i = 0; i < size-1; i++){
   		// from the first element to the nearly last one (Last i elements are already in place after the first loop)
       	for (int j = 0; j < size-i-1; j++){
       		//repeatedly swapping the adjacent elements if they are in wrong order
       		if (array[j] > array[j+1]){
       			swap(array[j], array[j+1]); 
			} 
		}  
   	}            
} 

void sortAsc(int *array, int size) {
	bubbleAscSort(array, size);
	printf("Your array has been sorted in ascending order.\n");
}

int main(){
	printf("Array Manipulations.\n\n");
    int *array = (int*)malloc(100*sizeof(int));//input array will be processed
    int size;//size of array
    createArray(array,size);
    array = (int*)realloc(array,size*sizeof(int));//re-size array for suitable
    int option;//option of menu
    //repeat while user enter option 1 to 5
    do {
        displayMenu(option);
        //process option of user
        switch(option) {
            case 1:
                addNewValue(array,size);
                break;
            case 2:
                searchValue(array,size);
                break;
            case 3:
                displayArray(array,size);
                break;
            case 4:
                displayValueInRange(array,size);
                break;
            case 5:
                sortAsc(array,size);
                break;
            default:
                printf("Thanks for using!");
        }
    }while(option >= 1 && option <= 5);
    return 0;
}


