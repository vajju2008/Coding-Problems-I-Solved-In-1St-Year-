#include <stdio.h>
struct student
{
    int marks;
    long int roll_number;
    char name[25];
}  s[2];
void display (struct student st[]);
int main() {
   
int i;
for(i=0;i<2;i++)

{
    scanf("%d %ld %s",&s[i].marks,&s[i].roll_number,s[i].name);
   
}
 display(s);
}
void display(struct student st[])
{
    int i;
    for(i=0;i<2;i++)
{
    printf("%d %ld %s\n",st[i].marks,st[i].roll_number,st[i].name);
}
}