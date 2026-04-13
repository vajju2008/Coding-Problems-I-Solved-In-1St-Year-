#include<stdio.h>
int main()
{
	int a=1,b=2,d=1;
	printf("%d%d%d",a++ + ++a+a++,a++ + ++b,++d + d++ + a++);
}