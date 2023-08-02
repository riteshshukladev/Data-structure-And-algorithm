#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char infix[MAX];
char postfix[MAX];
 int stack[MAX];
int top=-1;

void infix_to_postfix();
int priority(char);
int space(char);
void push(char);
int pop();
int isempty();
int evaluate_postfix();

int main(){
    printf("Enter the postfix expression: \n");
    gets(postfix);
    infix_to_postfix();
    printf("The postfix expression is: %s\n",postfix);

   int ans=evaluate_postfix();
   printf("The value of the postfix expression is: %d\n",ans);
    return 0;
}

void infix_to_postfix(){
    int i,j=0;
    char symbol;
    char next;
    for(i=0;i<strlen(postfix);i++){
        symbol=postfix[i];
        // if symbol is not an white space
        if( !space(symbol)){
            switch(symbol){
                case '(':
                push(symbol);
                break;
                case ')':
                while((next=pop()!='('))
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
    if(symbol==' ' || symbol=='\t' || symbol=='\0')
    return 1;
    else
    return 0;
}

void push(char item){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    top=top+1;
    stack[top]=item;
}

int pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isempty(){
    if(top==-1)
    return 1;
    else
    return 0;
}

int evaluate_postfix(){

    int i,a,b;
    for(i=0;i<strlen(postfix);i++){
        if(postfix[i]>='0' && postfix[i]<='9')
        {
            push(postfix[i]-'0');
        }
        else{
            a=pop();
            b=pop();
            switch(postfix[i]){
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