#include<stdio.h>
int main(){
int mat[3][3],i,j;
printf("enter the 3*3 matrix elements:");
for(i=0;i<3;i++){
for(j=0;j<3;j++)
scanf("%d",&mat[i][j]);
}
for(i=0;i<3;i++){
for(j=0;j<3;j++)
printf("%d\t",mat[i][j]);
printf("\n");
}
}                
