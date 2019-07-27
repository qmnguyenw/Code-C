#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

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
        printf("\n1- Add a value");
        printf("\n2- Search a value");
        printf("\n3- Remove the first existence of a value");
        printf("\n4- Remove all existence of a value");
        printf("\n5- Print out the array");
        printf("\n6- Sort the array in ascending order");
        printf("\n7- Sort the array in descending order");
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

void removeAt(int *array, int &size, int removeIndex) {
    //from first to last element in array
    for(int i = removeIndex; i < size-1; i++) {
        //assign right value to left value
        array[i]=array[i+1];
    }
    //decrease size
    size--;
}

void removeFirstExistence(int *array, int &size) {
    //remove value user input
    int removeValue;
    //check input
    char check;
    //check removing process perform or not
    bool isRemove = false;
    //repeat if user enter invalid value
    do {
        printf("Please enter remove value: ");
        scanf("%d",&removeValue);
        check = getchar();
        fflush(stdin);
    }while(!checkElement(removeValue,check));
    //from 1st to last element in array
    for (int i = 0; i < size; i++) {
        //if found input value in array
        if(removeValue == array[i]) {
            //remove it
            removeAt(array,size,i);
            isRemove = true;
            //stop looping, just remove first existence
            break;
        }
    }
    array = (int*)realloc(array,size*sizeof(int));
    //if removing process have been performed, notice
    if(isRemove) printf("First existence of input value have been removed.\n");
    else printf("The array does not contain input value.\n");
}

void removeAllExistence(int *array, int &size) {
    //remove value user input
    int removeValue;
    //check input
    char check;
    //check if removing process perform or not
    bool isRemove = false;
    //repeat if user enter invalid value
    do {
        printf("Please enter remove value: ");
        scanf("%d",&removeValue);
        check = getchar();
        fflush(stdin);
    }while(!checkElement(removeValue,check));
    //from 1st to last element in array
    for (int i = size - 1; i >= 0; i--) {
        //if found input value in array
        if(removeValue == array[i]) {
            //remove it
            removeAt(array,size,i);
            isRemove = true;
        }
    }
    array = (int*)realloc(array,size*sizeof(int));
    if(isRemove) printf("All existence of input value have been removed.\n");
    else printf("The array does not contain input value.\n");
}

void displayArray(int *array, int size) {
    printf("The current array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t",array[i]);
    }
    printf("\n");
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
	int *arrayClone = (int*)malloc(100*sizeof(int));//input array will be processed
	*arrayClone = *array;
	arrayClone = (int*)realloc(array,size*sizeof(int));//re-size array for suitable
	bubbleAscSort(arrayClone, size);
	printf("Your array has been sorted in ascending order.\n");
}

void bubbleDesSort(int arrayClone[], int size) { 
	//from the first element in array to the last one 
   	for (int i = 0; i < size-1; i++){
   		// from the first element to the nearly last one (Last i elements are already in place after the first loop)
       	for (int j = 0; j < size-i-1; j++){
       		//repeatedly swapping the adjacent elements if they are in wrong order
       		if (arrayClone[j] < arrayClone[j+1]){
       			swap(arrayClone[j], arrayClone[j+1]); 
			} 
		}  
   	}            
} 

void sortDes(int *array, int size) {
	int *arrayClone = (int*)malloc(100*sizeof(int));//input array will be processed
	*arrayClone = *array;
	arrayClone = (int*)realloc(array,size*sizeof(int));//re-size array for suitable
	bubbleDesSort(arrayClone, size);
	printf("Your array has been sorted in descending order.\n");
}

int main() {
    printf("Array Manipulations.\n\n");
    int *array = (int*)malloc(100*sizeof(int));//input array will be processed
    int size;//size of array
    createArray(array,size);
    array = (int*)realloc(array,size*sizeof(int));//re-size array for suitable
    int option;//option of menu
    //repeat while user enter option 1 to 7
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
                removeFirstExistence(array,size);
                break;
            case 4:
                removeAllExistence(array,size);
                break;
            case 5:
                displayArray(array,size);
                break;
            case 6:
                sortAsc(array,size);
                break;
            case 7:
                sortDes(array,size);
                break;
            default:
                printf("Thanks for using!");
        }
    }while(option >= 1 && option <= 7);
    return 0;
}

