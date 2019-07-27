#include <stdio.h>  
#include <string.h>  

int main()  
{  
    long decimal;  
    char binary[65];  
    int index = 0;  
 
    printf("Enter any decimal value : ");  
    scanf("%ld", &decimal);  

    while(decimal!=0)  
    {  
        
        binary[index] = (decimal % 2) + '0';  
        printf("%s\n",binary); 
        decimal /= 2;  
        index++;  
    }  
    binary[index] = NULL;  

    strrev(binary);   
    printf("Binary value of decimal = %s", binary);  

    return 0;




//#include <stdio.h>
//
//int convert(int);
//int main()
//{
//    int dec, bin;
//    printf("Enter a decimal number: ");
//    scanf("%d", &dec);
//    bin = convert(dec);
//    printf("The binary equivalent of %d is %d.\n", dec, bin);
// 
//    return 0;
//}
//
//int convert(int dec){
//    if (dec == 0)
//        return 0;
//    else
//     	return (dec % 2 + 10 * convert(dec / 2));
//    
}
