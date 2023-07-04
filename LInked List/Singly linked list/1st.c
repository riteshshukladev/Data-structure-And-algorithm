#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;

}; 
int main(){
    struct node *head = NULL;
    insertion_at_beginning(&head, 1);
    insertion_at_beginning(&head, 2);
    insertion_at_beginning(&head, 3);
    printf("\nLinked list after insertion at beginning: ");
    display(head);
    printf("\n");
    insertion_at_last(&head,4);
    insertion_at_last(&head,5);
    printf("\nLinked list after insertion at last: ");
    display(head);
    printf("\n");
    printf("\nLinked list after insertion at position 2: ");\
    insertion(&head,2,6);
    display(head);
    printf("\n");
    printf("\nLinked list after insertion at position 3: ");
    insertion(&head,3,7);
    display(head);
    printf("\n");
    deletion_at_beginning(&head);
    printf("\nLinked list after deletion at beginning: ");
    display(head);
    printf("\n");
    deletion_at_end(&head);
    deletion_at_end(&head);
    printf("\nLinked list after deletion at end: ");
    display(head);
    printf("\n");
    return 0;   
}
void insertion_at_beginning(struct node** head, int val){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->data = val;
    if(*head==NULL){
        *head =new_node;

    }
    else{
        new_node->next=*head;
        *head=new_node;
    }
    
}
display(struct node *head){
   struct node *temp =head;
   printf("start->");
    while(temp!=NULL){
        printf("%d ->", temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

insertion_at_last(struct node **head,int val){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->data = val;
    if(*head==NULL){
        *head=new_node;

    }
    else
    {
        struct node *temp = *head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;

    }

}
insertion(struct node **head,int pos,int val){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=val;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        struct node *temp;
        temp=*head;
        int i;
        for(i=1;i<=pos;i++){
            temp=temp->next;
        }
        if(temp->next==NULL){
            temp->next=newnode;
        }
        else{
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}
deletion_at_beginning(struct node **head){
    struct node *temp;
    temp=*head;
    if(*head==NULL){
        printf("\nList is empty");
    }
    else{
        *head=temp->next;
        free(temp);
    }
}
deletion_at_end(struct node **head){
    struct node *temp;
    temp=*head;
    if(*head==NULL){
        printf("\nList is empty");
    }
    else{
     while(temp->next->next!=NULL){
         temp=temp->next;
     }
        free(temp->next);
        temp->next=NULL;
    }
    
}
