#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

int main(){
    node *head = NULL;
    insertion_at_last(&head, 1);
    insertion_at_last(&head, 2);
    insertion_at_last(&head, 3);
    printf("The linked list is: \n");
    print(head);
    insertion_at_head(&head,4);
    insertion_at_head(&head,5);
    printf("\nThe linked list after insertion at head is: \n");
    print(head);
    insertion(&head,6,3);
    printf("\nThe linked list after insertion at position 3 is:\n ");
    print(head);
    deletion_at_head(&head);
    printf("\nThe linked list after deletion at head is:\n ");
    print(head);
    deletion_at_last(&head);
    printf("\nThe linked list after deletion at last is:\n ");
    print(head);
    deletion(&head,1);
    printf("\nThe linked list after deletion at position 3 is:\n ");
    print(head);
    printf("\n");
}

void insertion_at_last(node **head,int val){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    if( *head==NULL){
        *head = newnode;
        newnode->next = *head;
        return;
    }
    else{
        node *temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = *head;

    }

}

void insertion_at_head(node **head,int val){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    if( *head==NULL){
        *head = newnode;
        newnode->next = *head;
        return;
    }
    else{
        node *temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = *head;
        *head = newnode;

    }

}
void insertion(node **head,int val,int pos){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    if( *head==NULL){
        *head = newnode;
        newnode->next = *head;
        return;
    }
    else{
        node *temp = *head;
        int i=1;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        if(temp->next == *head){
            temp->next = newnode;
            newnode->next = *head;
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

}
void deletion_at_head(node **head){
    if(*head == NULL){
        printf("The linked list is empty\n");
        return;
    }
    else{
        node *temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        node *temp1 = *head;
        *head = (*head)->next;
        temp->next = *head;
        free(temp1);
    }
}
void deletion_at_last(node **head){
    if(*head == NULL){
        printf("The linked list is empty\n");
        return;
    }
    else{
        node *temp = *head;
        while(temp->next->next != *head){
            temp = temp->next;
        }
        node *temp1 = temp->next;
        temp->next = *head;
        free(temp1);
    }
}
void deletion(node **head,int pos){
    if(*head == NULL){
        printf("The linked list is empty\n");
        return;
    }
    else{
        node *temp = *head;
        int i=1;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        if(temp->next->next == *head){
            printf("The position is not valid\n");
            return;
        }
        node *temp1 = temp->next;
        temp->next = temp->next->next;
        free(temp1);
        
    }
}
void print(node *head){
    node *temp = head;
    while(temp->next != head){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d ",temp->data);
}