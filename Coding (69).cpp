#include<stdio.h>
int main()
{
	int battery;
	scanf("%d",&battery);
	if(battery>=80%){
		printf("in optimalcondition");
	}
	else{
		printf("not in optimal condition");
	}
}