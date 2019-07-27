#include<stdio.h>
#include<cstdlib>



void checkday() {
	
	int dd, mm, yy;
	printf("enter the day dd-mm-yy\n");
	scanf("%d-%d-%d",&dd,&mm,&yy);
	printf("d = %d, m = %d, y = %d\n",dd,mm,yy);
	
	if((dd <= 31 && dd >=1) && (yy >= 1 && yy <= 9999) &&
			(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
			{
			printf("right 1\n");
			printf("It's a day of the year\n");
			}
	else if((dd <= 30 && dd >=1) && (yy >= 1 && yy <= 9999) &&
			(mm == 4 || mm == 6 || mm == 9 || mm ==11))
			{
				printf("right 2\n");
				printf("It's a day of the year\n");
			}
	else if((dd <=28 && dd >=1) && (mm == 2) && (yy >= 1 && yy <= 9999))
			{
				printf("right 3\n");
				printf("It's a day of the year\n");
			}
	else if((dd <= 29 && dd >= 1) && (yy >= 1 && yy <= 9999) &&
			(yy % 400 == 0 || (yy % 4 == 0) && (yy % 100 !=0)))
			{
				printf("right 4\n");
				printf("It's a day of the year\n");
			}
	else{
			printf("That is not a day of the year\n");
			}
}

int main(int argc, char** argv) {
	printf("MENU\n----------------------\n");
	printf("1- Processing date data\n");
	printf("2- Charater data\n");
	printf("3- Quit\n");
	
	int n;
	printf("Enter your choice: "); scanf("%d",&n);
	
	switch(n){
		case 1:{
				printf("Your choice 1\n");
				checkday();
				break;
			}
		case 2:{
				printf("Your choose 2\n");
				char z,x;
				fflush(stdin);
				printf("Input two characters: ");
				scanf("%c%c",&z,&x);
				if(z <= x) {
					for (char i = x ; i >= z; i--) {
						printf("%c : %d\n",i,i);
					}
				}
				else {
					for (char j = z ; j >= x ; j--) {
						printf("%c : %d\n",j,j);
					}
				}
				break;
			}
		case 3:{
				break;
			}
		default:{
				printf("wrong number choice");
			}
	}
	
	return 0;	
}


