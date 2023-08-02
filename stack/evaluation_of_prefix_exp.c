#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#define MAX 100

int stack[MAX];
char infix[MAX];
char prefix[MAX];
int top = -1;

void infix_to_prefix();
int priority(char);
int space(char);
void push(int);
char pop();
int isempty();
int evaluate_prefix();

int main() {
    printf("Enter the infix expression: \n");
    fgets(infix, MAX, stdin);

    infix_to_prefix();
    printf("Prefix expression: %s\n", prefix);
    printf("Evaluation of prefix expression: %d\n", evaluate_prefix());

    return 0;
}

void infix_to_prefix() {
    int i, j = 0;
    char symbol, next;

    strrev(infix);
    printf("Reversed infix: %s\n", infix);

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        if (!space(symbol)) {
            switch (symbol) {
                case ')':
                    push(symbol);
                    break;

                case '(':
                    while ((next = pop()) != ')')
                        prefix[j++] = next;
                    break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while (!isempty() && priority(stack[top]) >= priority(symbol))
                        prefix[j++] = pop();
                    push(symbol); // Push the symbol onto the stack
                    break;

                default:
                    prefix[j++] = symbol;
                    break;
            }
        }
    }

    while (!isempty())
        prefix[j++] = pop();

    prefix[j] = '\0';
    strrev(prefix);
}


int priority(char symbol) {
    switch (symbol) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int space(char symbol) {
    if (symbol == ' ' || symbol == '\t' || symbol == '\0') {
        return 1;
    } else {
        return 0;
    }
}

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isempty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

#include <math.h>

int evaluate_prefix() {
    strrev(prefix);
   int i,a,b;
   for (i=0;i<strlen(prefix);i++){
    if(prefix[i]>=0 && prefix[i]<=9){
        push(prefix[i]);
    }
    else{
        b=pop();
        a=pop();
        switch(prefix[i]){
             case '+':
                push(a+b);
                break;
                case '-':
                push(a-b);
                break;
                case '*':
                push(a*b);
                break;
                case '/':
                push(a/b);
                break;
                case '%':
                push(a%b);
                break;
                case '^':
                push(a^b);
                break;
        }
    }
}
return pop();
}




