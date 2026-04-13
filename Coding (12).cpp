#include<stdio.h>
int main (){
    FILE *fp;
    int salaries[10],i;
    int least_salary, high_salary, second_highest_salary;
    fp = fopen("sal.txt","r");
    if(fp == NULL) {
          printf("Error opening file!\n");
          return 1;
          }
          for(i=0;i<10;i++) {
          scanf("%d", &salaries[i]);
          }
          fclose(fp);
          least_salary = salaries[0];
          highest_salary = salaries
