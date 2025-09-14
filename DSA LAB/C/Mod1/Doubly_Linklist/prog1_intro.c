#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

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
            newnode->prev=0;
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        printf("Enter 1 to continue 0R O to exit: ");
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
    printf("NULL");
}


int main()
{
    node *head=0;
    head=create_list(head);
    print_list(head);

}