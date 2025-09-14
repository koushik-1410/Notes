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

node *insert_at_end(node *tail)
{
    node *newnode = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
    return tail;
}

node *insert_at_big(node *tail)
{
    node *newnode = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
    return tail;
}

int get_length(node *tail)
{
    int count=0;
    if(tail==0)
    return 0;
    else
    {
        node *temp=tail->next;
        do
        {
            count++;
            temp=temp->next;
        } while (temp!=tail->next);
        return count;
    }
}


void insert_at_pos(node *tail)
{
    int pos,length=get_length(tail);
    printf("ENter the position: ");
    scanf("%d",&pos);
    if(pos<1 && pos>length+1)
    {
        printf("Invalid position.");
        return ;
    }
    else if(pos==1)
    {
        insert_at_big(tail);//now this not work bocoz tail,insert_at_big return a value.just a dummy case
    }
    else if(pos==length+1)
    {
        insert_at_end(tail);//now this not work bocoz tail,insert_at_end return a value.just a dummy case
    }
    else
    {
        int i=1;
        node *newnode=(node*)malloc(sizeof(node)),*temp=tail->next;
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        while(i<pos-1)
        {
            i++;
            temp=temp->next;   
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return;
}

int main()
{
    node *head = 0, *tail = 0;
    tail = create_list(tail);
    print_list(tail);
    tail = insert_at_big(tail);
    print_list(tail);
    tail = insert_at_end(tail);
    print_list(tail);
    printf("%d\n",get_length(tail));
    insert_at_pos(tail);
    print_list(tail);
}