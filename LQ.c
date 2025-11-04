#include <stdio.h>
#define SIZE 5
int front = -1 ;
int rear = -1 ;
int queue[SIZE];
void enqueue(int n){
    if( front == -1 && rear == -1 ){
        front = 0 ;
        rear = 0 ;
        queue[rear] = n ;
    } else if ( rear == SIZE - 1){
        printf("QUEUE OVERFLOW \n");
    } else {

    rear++;

    queue[rear] = n ;
   
    }
}

void dequeue(){
    if ( front == -1 && rear == -1){
        printf("QUEUE UNDERFLOW\n");
    }
    else if ( front == rear ){
        front = rear = -1;
    } else {
    front++;
    }
}

void display() {
    if (front == -1) {
        printf("QUEUE IS EMPTY\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main (){
    int ops ;
    int val ;
    while(1){
        printf("enter 1 or 2 or 3 or 4 for ( enqueue , dequeue , display ,exit ) respectively ");
        scanf("%d" , &ops );
        switch(ops){
        case 1:
            printf("enter value to be enqueued ");
            scanf("%d" , &val );
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid operation\n");
            break;
        }
    }
}
