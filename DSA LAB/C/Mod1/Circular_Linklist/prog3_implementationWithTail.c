#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

node * create_list(node *tail)
{
    int choice;
    do
    {
        node *newnode=(node*)malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(tail==0)
        {
            tail=newnode;
            tail->next=tail;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("Enter 1 to continue,enter O t0 exit: ");
        scanf("%d",&choice);
    }while(choice);
    return tail;
}

void print_list(node *tail)
{
    node *temp=tail->next;
    do
    {
        printf("%d>>",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
    printf("NULL");
}

int main()
{
    node *head=0,*tail=0;
    tail=create_list(tail);
    print_list(tail);
}