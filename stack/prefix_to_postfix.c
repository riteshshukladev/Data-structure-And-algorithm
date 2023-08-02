#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
char infix[MAX];
char postfix[MAX];

int top=-1;

void infix_to_postfix();
int priority(char);
int space(char);
void push(char);
int pop();
int isempty();


int main(){
    printf("Enter the prefix expression: \n");
    gets(infix);
    prefix_to_postfix();
    // printf("The postfix expression is: %s\n",postfix);
    print();
    return 0;
}

void prefix_to_postfix(){
    int i,j=0;
    char symbol;
    char next;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        // if symbol is not an white space
        if( !space(symbol)){
            switch(symbol){
                case '(':
                push(symbol);
                break;
                case ')':
                while((next=pop())!='(')
                postfix[j++]=next;
                break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                while(!isempty() && priority(stack[top])>=priority(symbol))
                postfix[j++]=pop();
                push(symbol);
                break;
                default:
                postfix[j++]=symbol;
            }
        }
    }
    while(!isempty()){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

int priority(char symbol){
    switch(symbol){
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

int space(char symbol){
    if(symbol == ' ' || symbol == '\t' || symbol == '\0'){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char item){
    if(top == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top]=item;
}

int pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isempty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void print(){
    int i;
    printf("The postfix expression is: ");
    for(i=0;i<strlen(postfix);i++){
        printf("%c",postfix[i]);
    }
    printf("\n");
}

