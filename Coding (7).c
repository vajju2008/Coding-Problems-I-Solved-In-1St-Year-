#include<stdio.h>
int main()
{
int T=4;
scanf("%d",&T);
while(T--)
{
	int X,Y;
	scanf("%d%d",&X,&Y);
	if(X+Y>6)
	{
		printf("YES\n");
		else
		printf("NO\n");
	}
}
}                                 