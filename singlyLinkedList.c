#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *head2 = NULL; 

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


void sort() {
    if (!head) {
        printf("Empty list\n");
        return;
    }
    struct Node *temp, *temp1;
    int tempswap;
    for (temp = head; temp->next != NULL; temp = temp->next) {
        for (temp1 = temp->next; temp1 != NULL; temp1 = temp1->next) {
            if (temp->data > temp1->data) {
                tempswap = temp->data;
                temp->data = temp1->data;
                temp1->data = tempswap;
            }
        }
    }
    printf("List sorted\n");
}


void reverse() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed\n");
}

struct Node* concat(struct Node* h1, struct Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;
    struct Node* temp = h1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = h2;
    return h1;
}


void createLinkedList(int n) {
    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(data);
    }
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Deleted first node\n");
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted last node\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Deleted last node\n");
}

// Delete specific value
void deleteSpecific(int value) {
    struct Node *temp = head, *prev = NULL;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->data == value) {
        deleteFirst();
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not in list\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d\n", value);
}

int main() {
    int n, data, position, choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at First\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Any Position\n");
        printf("5. Display List\n");
        printf("6. Delete from front\n");
        printf("7. Delete from last\n");
        printf("8. Delete specific element\n");
        printf("9. Sort linked list\n");
        printf("10. Reverse linked list\n");
        printf("11. Concatenate linked lists\n");
        printf("12. Exit\n");
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
                printf("Enter position: ");
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
                printf("Enter value to be deleted: ");
                scanf("%d", &value);
                deleteSpecific(value);
                display();
                break;
            case 9:
                sort();
                display();
                break;
            case 10:
                reverse();
                display();
                break;
            case 11:
                printf("Enter number of nodes for second list: ");
                scanf("%d", &n);
                head2 = NULL;
                for (int i = 0; i < n; i++) {
                    printf("Enter data for node %d: ", i + 1);
                    scanf("%d", &data);
                    struct Node *newNode = createNode(data);
                    if (head2 == NULL) {
                        head2 = newNode;
                    } else {
                        struct Node *temp = head2;
                        while (temp->next != NULL)
                            temp = temp->next;
                        temp->next = newNode;
                    }
                }
                head = concat(head, head2);
                printf("Concatenated list: ");
                display();
                break;
            case 12:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}