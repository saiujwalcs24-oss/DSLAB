#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}


int associativity(char op) {
    if (op == '^') return 1;  
    return 0;                
}

void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    char token;

    for (i = 0; i < strlen(infix); i++) {
        token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top != -1) pop(); 
        } else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '^') {
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(token) ||
                   (precedence(stack[top]) == precedence(token) && associativity(token) == 0))) {
                postfix[j++] = pop();
            }
            push(token);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0; 

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}