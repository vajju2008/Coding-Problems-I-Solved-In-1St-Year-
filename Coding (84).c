#include<stdio.h>
int energy();
int main()
{
	int e=energy();
	printf("%d",e);
	return 0;
}
int energy ()
{
	int m1=2,c1=5,e1;
	e1=m1*c1*c1;
	return e1;
}
