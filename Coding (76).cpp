#include<stdio.h>
int main()
{
	int n,a[100],p,i,tmp;
	printf("Enter n value\n");
	scanf("%d",&n);
	printf("Enter elements to sort\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(p=1;p<n;p++)
	{
		for(i=1;i<n-p;i++)
	{
		if(a[i]>a[i+1])
		{
			tmp=a[i];
			a[i]=a[i+1];
			a[i+1]=tmp;
		}
	}
	}
	printf("after array element are:\n");
	for(i+0;i<n;i++)
	printf("%d",a[i]);
	return 0;
}