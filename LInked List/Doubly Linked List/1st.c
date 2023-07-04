#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} node;
int main(){
    node *head = NULL;
    insertion_at_beginning(&head, 1);
    insertion_at_beginning(&head, 2);
    insertion_at_beginning(&head, 3);
    printf("\nLinked list after insertion at beginning: \n");
    display(head);
    insertion_at_end(&head, 4);
    insertion_at_end(&head, 5);
    printf("\nLinked list after insertion at end: \n");
    display(head);
    insertion(&head, 2, 6);
    printf("\nLinked list after insertion at position 2: \n");
    display(head);
    insertion(&head, 3, 7);
    printf("\nLinked list after insertion at position 3: \n");
    display(head);
    deletion_at_beginning(&head);
    printf("\nLinked list after deletion at beginning: \n");
    display(head);
    deletion_at_end(&head);
    printf("\nLinked list after deletion at end: \n");
    display(head);
    return 0;
 }
 void insertion_at_beginning(node **head,int val){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        newnode->next = *head;
        (*head)->prev=newnode;
        *head=newnode;
    }
 }
    void insertion_at_end(node **head,int val){
        node *newnode=(node*)malloc(sizeof(node));
        newnode->data=val;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(*head==NULL){
            *head=newnode;
        }
        else{
            node *temp=*head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;

        }
    }
    void insertion( node **head, int pos ,int val){
        node *newnode=(node*)malloc(sizeof(node));
        newnode->data=val;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(*head==NULL){
            *head = newnode;
        }
        if(pos==1){
            insertion_at_beginning(head,val);
        }
        
        else{
            node *temp=*head;
            int i;
            for(i=1;i<pos-1;i++){
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next->prev=newnode;
            temp->next=newnode;
            newnode->prev=temp;

        }
    }

 void deletion_at_beginning(node **head){
        node *temp=*head;
        *head=(*head)->next;
        (*head)->prev=NULL;
        temp->next=NULL;
        free(temp);
 }

 void deletion_at_end(node **head){
    node *temp=*head;
    node *temp1=temp->next;
    while(temp1->next!=NULL){
        temp=temp->next;
        temp1=temp1->next;
    }
    temp->next=NULL;
    temp1->prev=NULL;
    free(temp1);
 }

 void deletion_at_position(node **head,int pos){
    node *temp=*head;
    node *temp1=temp->next;
    if(pos==1){
        deletion_at_beginning(head);
    }
    int i;
    for(i=1;i<pos-1;i++){
        temp=temp->next;
        temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next->prev=temp;
    temp1->next=NULL;
    temp1->prev=NULL;
    free(temp1);
 }
    void display(node *head){
        node *temp=head;
        printf("start->");
        while(temp!=NULL){
            printf("%d ->", temp->data);
            temp=temp->next;
        }
        printf("end");
    }



    