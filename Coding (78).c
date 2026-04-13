#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        newNode->prev = NULL;
    } else {
        struct Node* temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void findMaxAndPredecessor(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    struct Node* maxNode = head;
    struct Node* prevMaxNode = NULL;
    while (current) {
        if (current->data > maxNode->data) {
            maxNode = current;
            prevMaxNode = current->prev;
        }
        current = current->next;
    }

    printf("%d ", maxNode->data);
    if (prevMaxNode) printf("%d\n", prevMaxNode->data);
    else printf("No predecessor (max node is the first node).\n");
}

int main() {
    struct Node* head = NULL;
    int data;

    printf("Enter the data for the doubly linked list (enter -1 to end): ");
    while (1) {
        scanf("%d", &data);
        if (data == -1) break;
        append(&head, data);
    }

    findMaxAndPredecessor(head);

    return 0;
}
