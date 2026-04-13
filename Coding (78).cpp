#include<stdio.h>
int main(){
	int i,n,key,a[n],flag=0;
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("enter the element to be searched\n");
	scanf("%d",&key);
	int low,high=n-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]==key){
			flag==1;
			break;
		}
		else if(a[mid]<key){
			low=mid+1;
		}
		else if(a[mid]>key){
			high=mid-1;
		}
	}
	if(flag==1){
		printf("element is found at position");
	}
	else{
		printf("element is not found");
	}
	
}