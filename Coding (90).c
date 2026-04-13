#include<stdio.h>
struct Node
{
    int data;
    struct Node* next;
};
int main()
{
    struct Node n1={10,NULL};
    struct Node n2={20,NULL};
    struct Node*head=&n1;
    n1.next=&n2;
    printf("%d\n%d\n",head->data,head->next->data);

}
