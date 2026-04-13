
#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int search,left=0,right=n-1,mid;
	mid=(left+right)/2;
	scanf("%d",&search);
	
	while(left<=right)
	{
		if(search<arr[mid])
		
    right=mid-1;
				else if(arr[mid]==search)
				{
					 printf("element %d found  at %d",search,mid+1);
					 break;
				}	
				else
		  {
				
				left=mid+1;
			 }
				mid=(left+right)/2;
			   
	 
}
	if(left>right)
	printf("Element%d not found in arr\n",search);
	
}