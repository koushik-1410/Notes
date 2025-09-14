#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *create_list(node *tail)
{
    int choice;
    do
    {
        node *newnode = (node *)malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (tail == 0)
        {
            tail = newnode;
            tail->next = tail;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        printf("Enter 1 to continue,enter O t0 exit: ");
        scanf("%d", &choice);
    } while (choice);
    return tail;
}

void print_list(node *tail)
{
    node *temp = tail->next;
    do
    {
        printf("%d>>", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("NULL\n");
}

node * reverse_list(node *tail)
{
    if(tail==0)//edge case
    {
        printf("List is empty");
        return 0;
    }
    else if(tail->next==tail)//edge case
    {
        return tail;
    }
    else
    {
        node *prev,*curr=tail->next,*next,*temp=tail;
        prev=tail;
        next=curr->next;
        tail=curr;
        while (curr!=temp->next)
        {
        curr->next=prev;
        prev=curr;
        curr=next;
        next=next->next;
        }
        return tail;
    }

}

node * reverse_list_2(node *tail)
{
    if(tail==0)
    {
        printf("LIdt is Empty.");
        return 0;
    }
    else if(tail->next==tail)
    {
        return tail;
    }
    else
    {
        node *curr,*prev,*next;
        curr=tail->next;
        next=curr->next;
        while(prev!=tail )
        {
            // curr->next=prev;
            prev=curr;
            curr=next;
            next=next->next;
            curr->next=prev;
        }
        tail=curr;
        return tail;
    }
}


int main()
{
    node *head = 0, *tail = 0;
    tail = create_list(tail);
    print_list(tail);
    tail=reverse_list_2(tail);
    print_list(tail);
}