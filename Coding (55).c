#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];

int front = -1, rear = -1;

void enqueue()
 {
    int value;
      if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
    } 
    else {
         if (front == -1)
            front = 0;
          printf("Enter value to enqueue: ");
          scanf("%d", &value);
          rear = (rear + 1) % MAX;
          queue[rear] = value;
          printf("%d enqueued\n", value);
    }
}

void dequeue() {
    if (front == -1) {
           printf("Queue is empty\n");
    } 
    else {
        printf("%d dequeued\n", queue[front]);
        if (front == rear) {
              front = rear = -1;
        } else {
             front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } 
    else {
        int i = front;
          printf("Queue: ");
         while (i != rear) {
             printf("%d ", queue[i]);
             i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice;
       while (1) {
    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

       switch (choice) {
        case 1:
                enqueue();
                break;
        case 2:
                dequeue();
                break;
       case 3:
                display();
                break;
       case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
