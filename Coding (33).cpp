#include <stdio.h>
#define MAX 100  // Maximum size of the stack

int stack[MAX];
int top = -1;  // Indicates the top of the stack

// Push operation
void push(int data) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
    printf("%d pushed to stack\n", data);
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;  // Return -1 to indicate underflow
    }
    return stack[top--];
}

// Peek operation (view the top element without removing it)
int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

// Check if the stack is empty
int isEmpty() {
    return top == -1;
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element is %d\n", peek());

    printf("%d popped from stack\n", pop());
    printf("%d popped from stack\n", pop());

    printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No");

    return 0;
}
