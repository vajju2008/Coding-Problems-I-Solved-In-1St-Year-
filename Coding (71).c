#include<stdio.h>
main()
{
	int a[100][100],b[100][100];
	int i,j,r1,r2,c1,c2;
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&a[i][j]);
			b[j][i]=a[i][j];
		}
	}
		for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
}