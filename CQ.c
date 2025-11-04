#include <stdio.h>
#define SIZE 422
int front = -1 ;
int rear = -1 ;
int queue[SIZE];
void enqueue(int n){
    if( front == -1 && rear == -1 ){
        front = 0 ;
        rear = 0 ;
        queue[rear] = n ;
    } else if ( (rear + 1) % SIZE == front ){
        printf("QUEUE OVERFLOW \n");
    } else {

    rear = (rear + 1) % SIZE ;

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
    front = (front + 1) % SIZE ;
    }
}

void display() {
    if (front == -1) {
        printf("QUEUE IS EMPTY\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
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
