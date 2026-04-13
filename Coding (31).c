#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *ptr,i,n,*ptr1;
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++) 
    scanf("%d",(ptr+i));
    for(i=0;i<n;i++)
    printf("\n%d",*(ptr+i));
    ptr1=realloc(ptr,n*sizeof(int));
    for(i=0;i<n;i++)
    scanf("%d",(ptr+i));
    for(i=0;i;i++)
    printf("\n%d",*(ptr1+i));
    free(ptr1);
    }
