//week7 doubly linked list program
#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* head = NULL, *tail = NULL ; 

struct Node* createNode(int data){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;

    if ( head == NULL){
        head = tail = newNode;
    }
    return newNode;
}

void insertAtFirst(int data){
    struct Node* newNode = createNode(data);

    if ( head == NULL){
        head = tail = newNode;
        return;
    }

    newNode->next = head ;
    head ->prev = newNode;
    head = newNode;
}
void insertAtEnd(int data){
    struct Node* newNode = createNode(data);
    
    if (head == NULL){
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail ;
    tail = newNode;
}
void insertAtleft(int pos ,int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = head, *prev = NULL;
    if (pos == 0){ 
        insertAtFirst(data);
        return;
    }
    
    for (int i = 0 ; i < pos - 1 ; i++){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("out of bounds");
        return;
    }
    
    prev->next = newNode;
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev = newNode;

}
void deleteVal(int val){
    struct Node* temp = head , *prevp = NULL;
    while(temp->data != val){
        prevp = temp;
        temp = temp->next;
    }
    if(temp->next == NULL){
        tail = temp->prev;
        tail->next = NULL;
        free(temp);
        return;
    }
    if(temp->prev == NULL){
        head = head->next;
        head->prev = NULL;
        free(temp);
        return;
    }
    prevp->next = temp->next;
    temp->next->prev = prevp;
    free(temp);
}
void display(){
    struct Node* temp = head ;
    while(temp != NULL){
    if(temp->next == NULL){
        printf("%d" ,temp->data);
        break;
    }
        printf("%d->", temp->data);
        temp = temp ->next;
    }
    printf("\n");
}
void createLinkedList(int n){
    int data;
    for(int i = 0 ; i < n ; i++){
        printf("enter data for node %d:" , i + 1);
        scanf("%d" , &data);
        insertAtEnd(data);
    }
}
int main (void){
    int data , ops , pos;
    while(1){
        printf("1 for createLinkedList()\n2 for insertAtLeft()\n3 for deleteVal()\n4 for display()\n5 for exit  :");
        scanf("%d" , &ops);
        switch (ops)
        {
        case 1:
            printf("enter no of nodes :");
            scanf("%d",&data);
            createLinkedList(data);
            break;
        case 2:
            printf("enter data :");
            scanf("%d",&data);
            printf("enter position:");
            scanf("%d", &pos);
            insertAtleft(pos , data);
            display();
            break;
            
        case 3 :
            printf("enter data :");
            scanf("%d",&data);
            deleteVal(data);
            display();
            break;
        case 4:
            display();
            break;
        case 5 :
            return 0 ;
        default:
            break;
        }
    }
}
