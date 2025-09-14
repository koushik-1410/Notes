#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

node * create_list(node *head)
{
    int choice=1;
    node *temp;
    do
    {
        node *newnode=(node*)malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Enter 1 to continue,enter 0 to exit: ");
        scanf("%d",&choice);
    } while (choice);
    temp->next=head;
    return head;
}

void print_list(node *head)
{
    node *temp= head;
    do
    {
        printf("%d>>",temp->data);
        temp=temp->next;
    } while (temp!=head);
    printf("NULL");

}

int main()
{
    node *head=0;
    head=create_list(head);
    print_list(head);
}




