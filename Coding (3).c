#include<stdio.h>
int main()
{
	int n;
	printf("enter n");
	scanf("%d",&n);
	int a[n],i,j, temp;
	printf("enter array elements");
	for(i=1; i<n; i++)
	scanf("%d",&a[i]);
	for(i=1; i<n; i++)
	{
	 for(j=0; j<n-i; j++)
	  {
	 	if(a[j]>a[j+1])
	 	{
	 	temp=a[j];
		 a[j]=a[j+1];
		 a[j+1]=temp;	
		}
	  }
	}
	printf("After sorting:");
	for (i=0; i<n; i++)
	printf("%d",a[i]);
}

