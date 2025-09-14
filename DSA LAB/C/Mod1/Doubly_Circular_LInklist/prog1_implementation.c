#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;
void create_list(node **head,node **tail)
{
    node *temp,*newnode;
    int choice;
    do
    {
        newnode=(node*)malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        newnode->prev=0;
        if((*head)==0)
        {
            (*head)=temp=newnode;
            // newnode->prev=newnode;
            // newnode->next=head;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        newnode->next=(*head);
        printf("Enter 1 to continue,O t0 exit: ");
        scanf("%d",&choice);
    } while (choice);
    (*head)->prev=temp;
    (*tail)=temp;
}

void print_list_big(node *head)
{
    if(head==0)
    {
        printf("NULL");
        return;
    }
    node *temp = head;
    do
    {
        printf("%d>>", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("NULL\n");
}
 void print_list_end(node *tail)
 {
    if(tail==0)
    {
        printf("NULL");
        return;
    }
    
    node *temp = tail;
    do
    {
        printf("%d>>",temp->data);
        temp=temp->prev;
    } while (temp!=tail);
    printf("NULL");
 }

int main()
{
    node *head=0,*tail;
    create_list(&head,&tail);
    print_list_big(head);
    print_list_end(tail);

}