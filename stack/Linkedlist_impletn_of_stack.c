#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *top = NULL;

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    pop();
    pop();
    display();
    peek();
    display();
    size();
}
void push(int item){
    node *newnode;
    newnode = (node *)malloc(sizeof(node)); 
    newnode->data = item;
    if(top == NULL){
        newnode->next = NULL;
    }
    else{
        newnode->next = top;
    }
    top = newnode;
}
void pop(){
    node *temp;
    if(top == NULL){
        isempty();
        printf("Stack is empty\n");
    }
    else{
        temp = top;
        top = top->next;
        printf("Popped item is %d\n",temp->data);
        free(temp);
    }
}
void isempty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void peek(){
    if(top == NULL){
        isempty();
        printf("Stack is empty\n");
    }
    else{
        printf("Peek item is %d\n",top->data);
    }
}

void display(){
    node *temp;
    if(top == NULL){
        isempty();
        printf("Stack is empty\n");
    }
    else{
        temp = top;
        while(temp != NULL){
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}   

void size(){
    node *temp;
    int count = 0;
    if(top == NULL){
        isempty();
        printf("Stack is empty\n");
    }
    else{
        temp = top;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        printf("Size of stack is %d\n",count);
    }
}