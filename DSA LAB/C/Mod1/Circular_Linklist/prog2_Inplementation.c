#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

void create_list(node **head,node **tail)
{
    int choice;
    do
    {
        node *newnode=(node*)malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if((*head)==0)
        {
            (*head)=(*tail)=newnode;
            newnode->next=(*head);
        }
        else
        {
            (*tail)->next=newnode;
            (*tail)=newnode;
        }
        printf("Enter 1 to continue,enter 0 to exit");
        scanf("%d",&choice);
    }while(choice);
        (*tail)->next=(*head); 
    
}



int main()
{
    node *head=0,*tail=0;
    create_list(&head,&tail);
}