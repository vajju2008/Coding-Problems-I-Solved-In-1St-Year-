#include<stdio.h>
int main()
{
          int a={9,15,7,21,10,5,11};
          in temp;
          for(int i=0;i<7;i++){
                  scanf("%d",&a[i});
                  }
                for(int i=0;i<6;i++){
          for(int j=0;j<7-i-1;j++){
                  if(a[j]>a[j+1])
                  temp=a[j];
                  a[j]=a[j+1];
                  a[j+1]=temp;}
                  }
                  for(int i=0;i<7;i++)
                  {
                          printf("%d",&a[i]);
                          }
                          }
                        
          
