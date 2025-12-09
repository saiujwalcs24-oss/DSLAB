#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left , *right ; 
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode ->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root , int value){
    if (root == NULL) return createNode(value);
    if(value > root->data){
        root->right = insert(root->right , value);
    }
    if (value < root->data ){
        root->left = insert(root->left,value);
    }
    return root ; 
}
void inorder(struct Node* root){
    if (root == NULL) return;
    inorder(root->left);
    printf("%d " , root->data);
    inorder(root->right);
}
void postorder(struct Node* root){
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d " , root->data);
}
void preorder(struct Node* root){
    if (root == NULL) return;
    printf("%d " , root->data);
    preorder(root->left);
    preorder(root->right);
}
void display(struct Node* root){
    if ( root == NULL) {
        printf("Empty tree!\n");
        return;
    }

    printf("BST elements(inorder):\n");
    inorder(root);
}
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Display (Inorder)\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                display(root);
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }


}
