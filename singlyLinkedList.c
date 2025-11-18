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


void insertAtFirst(int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning\n", data);
}

void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtAny(int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    struct Node *newNode = createNode(data);

    if (position == 1) {
        newNode->next = head;
        head = newNode;

        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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

void createLinkedList(int n) {
    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(data);
    }
}
void deleteFirst(){
    struct Node* temp;
    if ( head == NULL){
        printf("List is empty\n");
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
void deleteLast(){
    struct Node *temp , *prev;
    if ( head == NULL){
        printf("empty list\n");
        return;
    }
    temp = head ; 
    prev = NULL ;

    while (temp ->next != NULL){
        prev = temp ; 
        temp = temp -> next; 
    }
    prev ->next = temp -> next ;

    free(temp);
    
}
void deleteSpecific(int value){
    struct Node *temp = head, *prev = NULL;
    if (head == NULL){
        printf("list is empty\n");
        return;
    }

    if ( head->data == value){
        deleteFirst();
        return;
    }
    while ( temp != NULL && temp -> data != value){
        prev = temp ;
        temp = temp->next;
    }
    if ( temp == NULL){
        printf("element not in list\n");
        return;
    }
    prev->next = temp -> next;
    free(temp);
}

int main() {
    int n, data, position, choice , value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at First\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Any Position\n");
        printf("5. Display List\n");
        printf("6. Delete from front\n");
        printf("7. delete from last\n");
        printf("8. delete specific element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createLinkedList(n);
                break;
            case 2:
                printf("Enter data to insert at first: ");
                scanf("%d", &data);
                insertAtFirst(data);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);

                scanf("%d", &position);
                insertAtAny(data, position);
                break;
            case 5:
                display();
                break;
            case 6:
                deleteFirst();
                display();
                break;
            case 7:
                deleteLast();
                display();
                break;
            case 8:
                printf("enter value to be deleted:");
                scanf("%d" , &value);
                deleteSpecific(value);
                display();
                break;
                
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}