#include <stdio.h>
#define MAX 5

char stack[MAX];  // Changed to char for consistency
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}
void peek(){
    if ( top == -1 ){
        printf("Stack underflow");
    }
    printf("top element : %c" , stack[top]);

}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    }
    printf("popped element is : %c" , stack[top--] );
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = top; i >= 0; i--) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

int main() {
    int ops;
    char x;

    while (1) {
        printf("\n1 for push\n2 for pop\n3 for display\n4 for peeks\n0 to exit\n");
        printf("Enter operation: ");
        scanf("%d", &ops);

        switch (ops) {
            case 1:
                printf("Enter element: ");
                scanf(" %c", &x); 
                push(x);
                break;
            case 2:
                 pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid operation\n");
        }
    }
}