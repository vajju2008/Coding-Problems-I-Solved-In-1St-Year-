#include<stdio.h>
int main()
{
	int n,j,i,temp;                    
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("before the array is sorting");
	for(i=0;i<n;i++)
	{
		printf("%d/n",a[i]);
	}
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i;j>0&&temp<a[j-1];j--)
		{
			a[j]=a[j-1];
		}
		a[j]=temp;
		printf("\nstep:%d===>",i);
		for(j=0;j<n;j++);
	}
	printf("after sorting the elements");
	for(i=0;i<n;i++);
	{
		printf("%d",a[i]);
	}
}