#include<stdio.h>
int main()
{
	int finalvelocity,initialvelocity,acceleration,time;
	initialvelocity=25;
	acceleration=18;
	time=12;
	finalvelocity=initialvelocity+(acceleration*time);
	printf("finalvelocity=%d",finalvelocity);
	return 0;
}