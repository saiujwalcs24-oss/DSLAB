#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//stack implementation of linked list
void push(int data){
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("top = %d\n", data);
}

void pop(){
    struct Node* temp;
    if ( head == NULL){
        printf("Stack underflow \n");
        return;
    }
    if (head->next == NULL){
        temp = head ;
        head = NULL;
        free(temp);
        return;
    }

    temp = head ; 
    head = head -> next ;
    free(temp);
}
void peek(){
    if (!head){
        printf("NULL\n");
        return;
    }

    printf("top element = %d\n" , head->data);
    return;
}

void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

int main(void){
    int ops , data;


    while(1){
        printf("enter stack operation: \n 1 for push \n 2 for pop \n 3 for peek \n 4 for display");
        scanf("%d" , &ops);

        switch(ops){
            case 1 :
                printf("enter data :");
                scanf("%d" , & data);
                push(data);
                break;
            case 2 :
                pop();
                break;
            case 3 : 
                peek();
                break;
            case 4:
                display();
                break;
            default:
                printf("invalid ops\n");
                break;            
        }
    }
}
