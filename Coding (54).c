#include<stdio.h>
#include<stdlib.h>
#define max 5
int q[max];
int f=-1,r=-1;
void enq(int);
void deq();
void display;
int main()
{
	int choice,x;
	while(1)
	{
		printf("\n1.enqueue\n2. dequeue\n3. display\n4. exit\n enter your choice");
		scanf("%d",&choice);
		
			switch(choice)
			{
				case 1: printf("enter element to insert");
				scanf("%d",&x);
				enq(x);
				break;
		        case 2: deq();
		        break;
		        case 3:display();
		        break;
		        case 4:exit(0);
		        break;
			}
		
		return 0;
	}
}
void enq(int element)
{
	if(f==-1 && r==-1)
	{
		f=0;
		r=0;
		q[r]=element;
	}
	else if((r)%max==f)
	{
		printf("queue is overflow");
	}
	else{
		r=(r+1)%max;
		q[r]=element;
	}
}
void deq()
{
	if((f==-1)&&(r==-1))
	{
		printf("queue is underflow");
	}
	else if(f==r)
	{
		printf("the deequeue element is %d",q[f]);
		f=-1;
		r=-1;
		
	}
	else{
		printf("dequeue is %d",q[f]);
		f=(f+1)%max;
	}
}
void display()
{
	int i=f,j;
	if(f=-1 && r=-1)
	{
		printf("\nqueue is empty");
		
	}
	else {
		printf("element is queue");
		for(i=f;i<=max-1;i++)
		printf("%d",q[i]);
		for(j=0;j<=r;j++)
		printf("%d",&q[j]);
	}
}


