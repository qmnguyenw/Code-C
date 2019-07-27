#include <stdio.h>
#include <stdlib.h>

int checkInput(int inputNum, char check) {
    //if check is character not '\n' => input is not a number, return 0
    if (check != '\n') {
        printf("Data type error.Please re-enter.\n");
        return 0;
    }
    //else return 1
    return 1;
}

void input(int &inputNum){
	//char to check input
	char check;
	//loop if check invalid
	do{
		scanf("%d",&inputNum);
        check = getchar();
        //clear buffer
        fflush(stdin);
	}while(checkInput(inputNum,check)==0);
}

int main() {
	printf("Matrix Add.\n");
    int row, col, **m1, **m2, **m, i, j;
//    do {
//    	printf("Accept size: ");	scanf("%d %d", &row, &col);
//    printf("Enter number of row : ");
//    scanf("%d", &row);
//    printf("Enter number of collum : ");
//    scanf("%d", &col);
//	}while(checkRowCol(row,col) == 0);
	printf("Enter number of row : ");
	input(row);
	printf("Enter number of collum : ");
	input(col);	
    m1=(int**)malloc(row*sizeof(int*));
    m2=(int**)malloc(row*sizeof(int*));
    m=(int**)malloc(row*sizeof(int*));
    for(i = 0; i < row; i++){
    	m1[i] = (int*)malloc(col*sizeof(int));
    	m2[i] = (int*)malloc(col*sizeof(int));
    	m[i] = (int*)malloc(col*sizeof(int));
	}
    printf("Accept matric m1: \n");
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++) {
//        	m1[i][j]=rand()%10;
//            printf("%4d", m1[i][j]);
			printf("\t");
//			scanf("%d",&m1[i][j]);
			input(m1[i][j]);
        }
     	printf("\n");
    }
    printf("Accept matric m2: \n");
	for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
//        	m2[i][j]=rand()%10;
//        	printf("%4d", m2[i][j]);
			printf("\t");
			scanf("%d",&m2[i][j]);
        }
        printf("\n");
    }
    printf("m = m1 + m2: \n");
    for (i = 0; i < row; i++) {
        for ( j = 0; j < col; j++) {
            m[i][j] = m1[i][j] + m2[i][j];
            printf("%4d ", m[i][j]);
        }
         printf("\n");
    }
    return 0;
}

