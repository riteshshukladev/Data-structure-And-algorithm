#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;

int main(){
    node *head = NULL;
    insertion_at_head(&head, 1);
    insertion_at_head(&head, 2);
    insertion_at_head(&head, 3);
    printf("Linked list after insertion at head: \n");
    print_list(head);
    printf("\n");
    insertion_at_last(&head, 4);
    insertion_at_last(&head, 5);
    insertion_at_last(&head, 6);
    printf("Linked list after insertion at last: \n");
    print_list(head);
    printf("\n");
    insertion(&head, 7, 2);
    insertion(&head, 8, 5);
    printf("Linked list after insertion at position: \n");
    print_list(head);
    printf("\n");
    deletion_at_head(&head);
    deletion_at_head(&head);
    printf("Linked list after deletion at head: \n");
    print_list(head);
    printf("\n");
    deletion_at_last(&head);
    printf("Linked list after deletion at last: \n");
    print_list(head);
    printf("\n");
    deletion(&head, 1);
    printf("Linked list after deletion at position: \n");
    print_list(head);
    return 0;   
}
void insertion_at_head(node **head, int data){
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    if(*head == NULL){
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;

    }
        else{
            node *temp = *head;
            while(temp->next != *head){
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
            new_node->next = *head;
            (*head)->prev = new_node;
            *head = new_node;
        }
}
void insertion_at_last(node **head , int data){
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    if(*head == NULL){
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
    }
    else{
        node *temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = *head;
        (*head)->prev = new_node;
    }

}
void insertion(node **head,int data,int pos){
   node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    if(*head == NULL){
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
    }
    else{
        node *temp = *head;
        int i = 1;
        while(i < pos-1){
            temp = temp->next;
            i++;
        }
        if(temp->next == *head){
            temp->next = new_node;
            new_node->prev = temp;
            new_node->next = *head;
            (*head)->prev = new_node;
        }
        else{
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next->prev = new_node;
        temp->next = new_node;
        }
    }
}
void deletion_at_head(node **head){
    if(*head == NULL){
        printf("Linked list is empty\n");
    }
    else{
        node *temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        node *temp1 = *head;
        *head = (*head)->next;  
        temp->next = *head;
        (*head)->prev = temp;
        free(temp1);

    }
}
void deletion_at_last(node **head){
    if(*head == NULL){
        printf("Linked list is empty\n");
    }
    else{
        node *temp = *head;
        while(temp->next->next != *head){
            temp = temp->next;
        }
        node *temp1 = temp->next;
        temp->next = *head;
        (*head)->prev = temp;
        free(temp1);
    }
}
void deletion(node **head, int pos){
    if(*head == NULL){
        printf("Linked list is empty\n");
    }
    else{
        node *temp = *head;
        int i = 1;
        while(i < pos-1){
            temp = temp->next;
            i++;
        }
        if(temp->next->next == *head){
            node *temp1 = temp->next;
            temp->next = *head;
            (*head)->prev = temp;
            free(temp1);
        }
        else{
            node *temp1 = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            free(temp1);
        }
    }
}

void print_list(node *head){
    node *temp = head;
    while(temp->next != head){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

