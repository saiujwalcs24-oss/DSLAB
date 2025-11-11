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

int main() {
    int n, data, position, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at First\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Any Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
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
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtAny(data, position);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}