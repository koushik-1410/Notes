#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

void create_list(node **head, node **tail)
{
    int choice = 1;
    node *temp;
    do
    {
        node *newnode = (node *)malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if ((*head) == 0)
        {
            newnode->prev = 0;
            (*head) = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Enter 1 to continue 0R O to exit: ");
        scanf("%d", &choice);
    } while (choice);
    (*tail) = temp;
}

void reverse(node **head, node **tail)
{
    node *temp=(*head),*temp2;
    while(temp!=0)
    {
        temp2=temp->next;
        temp->next=temp->prev;
        temp->prev=temp2;
        temp=temp2;
    }
    temp=(*head);
    (*head) = (*tail);
    (*tail) = temp;
}

void print_list_big(node *head)
{
    while (head != 0)
    {
        printf("%d>>", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void print_list_end(node *tail)
{
    while (tail != 0)
    {
        printf("%d>>", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}


int main()
{
    node *head = 0, *tail = 0;
    create_list(&head, &tail);
    print_list_big(head);
    print_list_end(tail);
    reverse(&head,&tail);
    print_list_big(head);
    print_list_end(tail);

}
