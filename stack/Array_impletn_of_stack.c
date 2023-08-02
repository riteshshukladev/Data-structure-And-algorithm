#include<stdio.h>
#include<stdlib.h>

#define MAX 4
int arr_stack[MAX];

int top = -1;

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
        display();
        peek();
        display();
}
void push(int item){
    if(top ==MAX-1){
        isfull();
        printf("Stack is full\n");
    }
    else{
        top = top+1;
        arr_stack[top] = item;
        printf("Pushed item is %d\n",item);
    }
}
int pop(){
    int item;
    if(top == -1){
        isempty();
        printf("Stack is empty\n");
    }
    else{
        item = arr_stack[top];
        top = top-1;
        printf("Popped item is %d\n",item);
    }
}
void isempty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
void isfull(){
    if(top == MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
void peek(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Top element is %d\n",arr_stack[top]);
    }
}
void display(){
    int i;
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements are:\n");
        for(i=top;i>=0;i--){
            printf("%d\n",arr_stack[i]);
        }
    }
}