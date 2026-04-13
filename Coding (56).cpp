//area of circle;
#include<stdio.h>
#define pi 3.14
int main ()
{
	float area, r;
	printf("enter the value of radius");
	scanf("%f\n",&r);
	printf("%f",r);
	area=pi*r*r;
	printf("%f\n",area);
	return 0;
}
