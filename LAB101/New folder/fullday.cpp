#include <stdio.h>
#include <iostream>

int main(int argv, char** arv) {
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};   
    int d, m, y, i;
	int temp; 

    printf("Fill in a date after 01-01-1900 as dd-mm-yyyy: ");
    scanf("%d-%d-%d",  &d, &m, &y);
    temp=d;

    // correction for leap year
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
        month[1] = 29;

    if (y < 1900 || m < 1 || m > 12 || d < 1 || d > month[m - 1]) {
        printf("This is an invalid date.\n");
        return 1;
    }
       
    for (i = 1900; i < y; i++)
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
            d += 366;
        else
            d += 365;
        printf("%d\n", d);
    for (i = 0; i < m - 1; i++) 
        d += month[i];
        printf("%d", d);
    printf("This is a %s.\n", day[d % 7]);
    //return 0;
    // day of year.........................
    int doy=temp;
    for(i=0;i<(m-1);i++)
    	doy=doy+month[i];
    printf("This is %d days of the year\n", doy);
    //week of year
    printf("This is week %d of the year", (doy/7)+1);
}
