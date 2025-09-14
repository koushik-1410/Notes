// display a list create a list insert any position at linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

node* create_list(node *head)
{
    int choice;
    node *temp=NULL;
    do
    {
        node *newnode = (node*)malloc(sizeof(node));
        printf("Enter a value: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
            temp=head=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Enter 1 to continue,0 to exit: ");
        scanf("%d",&choice);
    } while (choice);
    return head;
}


void print_list(node *head)
{
    while(head!=0)
    {
        printf("%d>>",head->data);
        head=head->next;
    }
    printf("Null");
}


int main()
{
        node* head=0;
        head = create_list(head);
        print_list(head);
}