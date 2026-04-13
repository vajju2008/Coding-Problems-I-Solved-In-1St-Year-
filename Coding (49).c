#include<stdio.h>
int main()
	{
   int celsius;
   printf("enter the celsius value:");
   scanf("%d",&celsius);
   float fahrenheit;
   fahrenheit=(celsius*5/9+32);
   printf("fahreheit=%f",fahrenheit);
   return 0;
}

