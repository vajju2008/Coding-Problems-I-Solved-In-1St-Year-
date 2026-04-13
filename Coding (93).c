#include<stdio.h>
int main()
{
	int m,y,i;
	scanf("%d%d%d%d",&m,&y,&i);
	if (i==2&& m==1&&y==24)
	{
		printf("fine=0");
	}
	else if( i!=2&&m!=2&&y==24)
{
	printf("fine=15 hackos");
}
else if ( i!=2&&m!=1&&y!=24)
{
	printf("fine=100 hackos ");
}
return 0;
	}
