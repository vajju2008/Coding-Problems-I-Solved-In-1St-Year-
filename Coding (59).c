#include<stdio.h>
#include<stdlib.h>
#define max 5

int q[max];
int f = -1, r = -1;

void enq(int);
void deq();
void display();

int main()
{
    int choice, x;
    while(1)
    {
        printf("\n1. enqueue\n2. dequeue\n3. display\n4. exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &x);
                enq(x);
                break;
            case 2:
            	printf("dequeue");
                deq();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
x
void enq(int element)
{
    if(f == 0 && r == max - 1 || (r + 1) % max == f)
    {
        printf("Queue Overflow!\n");
    }
    else if(f == -1 && r == -1)
    {
        f = 0;
        r = 0;
        q[r] = element;
    }
    else
    {
        r = (r + 1) % max;
        q[r] = element;
    }
}

void deq()
{
    if(f == -1 && r == -1)
    {
        printf("Queue Underflow!\n");
    }
    else if(f == r)
    {
        printf("The dequeued element is %d\n", q[f]);
        f = -1;
        r = -1;
    }
    else
    {
        printf("Dequeued element is %d\n", q[f]);
        f = (f + 1) % max;
    }
}

void display()
{
    if(f == -1 && r == -1)
    {
        printf("\nQueue is empty!\n");
    }
    else
    {
        printf("Elements in the queue: ");
        
        int i = f;
        while(i != r)
        {
            printf("%d ", q[i]);
            i = (i + 1) % max;
        }
        printf("%d\n", q[r]);
    }
}
