#include<stdio.h>
#include<cstdlib>
main() {
	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	char* day[] = {"sunday", "monday", "tuesday", "wenedsday", "thursday", "friday", "saturday"};
	int d,m,y,i;
	printf("Enter a day as dd-mm-yyyy: ");
	scanf("%d-%d-%d",&d , &m, &y);
	printf("d = %d, m = %d, y = %d\n",d,m,y);
	int count = d;//count dem so ngay
	if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
			month[1] = 29;
	if((d>month[m-1] || d<1) || (m<1 || m>12) || (y<1)){
		printf("That day is invalid\n");
		return 1;
	}	
	for(i = 0; i < m-1; i++) {
		count += month[i];
	}
	printf("this is day %d of year\n",count);
	printf("this is week %d of year\n",count/7+1);
	//
	for(i = 1900 ; i < y ; i ++) {
		if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)){
			count += 366;
		}else count += 365;
	}
	printf("this day is %s\n",day[count%7]);
	printf("count = %d\n",count);	
}
