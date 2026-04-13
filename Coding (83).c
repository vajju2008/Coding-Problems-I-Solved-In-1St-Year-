#include<stdio.h>
void energy(int,int);
int main()
{
	int m=2,c=5;
	energy(m,c);
	return 0;
}
void energy (int m1,int c1)
{
	int e1=m1*c1*c1;
	printf("%d",e1);
	return 0;
}
