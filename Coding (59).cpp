#include<stdio.h>
int main()
{
	int i,j,N,M;
	int a[i][j],b[i][j],c[i][j];
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++){
		for(j=0;j<M;j++)
		{
			scanf("%d",a[i][j]);
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			scanf("%d",b[i][j]);
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	for(i=0;i<N;i++){
	for(j=0;j<M;j++)
		{
			scanf("%d",&c[i][j]);
			printf("%d",c[i][j]);
			printf("\n");
		}
	}
}