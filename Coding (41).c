typedef struct Node NODE;
NODE *getMiddleElement(NODE *head){
    // Write your code here
    if (!head || !head->next) {
    return head;
}
        NODE *slow = head;
        NODE *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
    return slow;
}
