#include<stdio.h>
int main()
{
	float A,B,C;
	printf("enter coefficient A:");
	scanf("%f",&A);
	printf("enter coefficient B:");
	scanf("%f",&B);
	printf("enter coefficient C:");
	scanf("%f",&C);
	float discriminant=(B*B)-(4*A*C);
	if (discriminant>0)
	printf("the roots are real and different.\n");
	else
	if (discriminant=0)
	printf("the roots are real and equal.\n");
	else
	printf("the roots are imaginary.\n");
	return 0;
}