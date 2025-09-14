#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;    
} node;

int main()
{
    int choice;
    struct node *head=0,* newnode,*temp;
    do
    {
        newnode=(node *)malloc(sizeof(node));
        printf("ENter the value: ");
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

        printf("Do you want to Continue(Y/N) press(1/0): ");
        
        scanf("%d",&choice);
    } while (choice!=0);
    temp=head;
    while(temp!=0)
    {
        printf("%d>>",temp->data);
        temp=temp->next;
    }
    printf("NULL");


}