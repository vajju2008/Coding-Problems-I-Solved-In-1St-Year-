#include<stdio.h>
#define size 5
int queue[size],front=-1,rear=-1;
void enqueue()
{
	int ele;
	printf("Enter data:");
	scanf("%d",&ele);
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=ele;
	}
	else if((rear+1)%size==front)
	    printf("Q is overflow\n");
	else{
		rear=(rear+1)%size;
		queue[rear]=ele;
	}
}
void dequeue()
{
	if(front==-1 && rear==-1)
     printf("Underflow\n");
     else if(front==rear)
     {
     	printf("Deleted ele:%d\n",queue[front]);
     	front=rear-1;
	 }
	 else{
	 	printf("Deleted ele:%d\n",queue[front]);
	 	front=(front+1)%size;
	 }
}
void display()
{
	int i;
	for(i=front;i<=rear;i=(i+1)%size)
	{
		printf("%d",queue[i]);
	}
	printf("%d\n",queue[i]);
}
int main()
{
	int ch;
	do{
		printf("**MENU\n**");
		printf("1.enqueue\n 2.dequeue\n 3.display\n Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enqueue();break;
			case 2:dequeue();break;
			case 3:display();break;
			default:printf("Wrong Choice\n");
		}
	}while(ch<4);
}