#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
struct Node* insert(struct Node* root, int data) {

    if (root == NULL) return newNode(data);

    
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    
    return root;
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);     
        preorder(root->left);           
        preorder(root->right);     
    }
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Preorder Traversal of the BST: ");
    preorder(root);
    printf("\n");

    return 0;
}
