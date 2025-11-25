#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;


struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void enqueue(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void dequeue() {
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head == NULL) { 
        tail = NULL;
    }
    free(temp);
}

void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("| %d | ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Example usage
int main(void) {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();   
    dequeue();
    display();   
    
}