#include<stdio.h>
int energy(int,int);
int main()
{
	int m=2,c=5,e;
	e=energy(m,c);
	printf("%d",e);
	return 0;
}
int energy (int m1,int c1)
{
	int e1=m1*c1*c1;
	return e1;
}
