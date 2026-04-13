#include<stdio.h>
int main(){

int t;
scanf("%d",&t);
while(t--)
{
	int N,sum=0,r;
	scanf("%d",&N);
	while(N>0)
	{r=N/10;
	sum=sum=r*r*r;
	N=N/10;
	}
printf("%d\n",sum);
}
return 0;
}
