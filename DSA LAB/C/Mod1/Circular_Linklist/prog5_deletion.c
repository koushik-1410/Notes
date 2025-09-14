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

int get_length(node *tail)
{
    int count = 0;
    if (tail == 0)
        return 0;
    else
    {
        node *temp = tail->next;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != tail->next);
        return count;
    }
}

node * delete_from_big(node *tail)
{
    if (tail == 0)
    {
        printf("LIst is empty.");
        return 0;
    }
    else if (tail->next == tail)
    {
        free(tail);
        return 0;
    }
    else
    {
        node *temp = tail->next;
        tail->next = temp->next;
        temp->next = 0; // if you donot write it is fine.
        free(temp);
    }
    return tail;
}

node *delete_from_end(node *tail)
{
    if (tail == 0)
    {
        printf("The list is empty.");
        return 0;
    }
    else if (tail->next == tail)
    {
        free(tail);
        return 0;
    }
    else
    {
        node *temp = tail->next, *temp2;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        // printf("%d",temp->data);
        temp2 = tail;
        temp->next = tail->next;
        tail->next = 0;
        tail = temp;
        free(temp2);
        return tail;
    }
}

node * delete_at_pos(node *tail)
{
    int pos,length=get_length(tail);
    printf("Enter the position where to enter the node: ");
    scanf("%d",&pos);
    if(pos<1 || pos>length)
    {
        printf("Invalid position.");
    }
    else
    {
        if(pos==1)
        {
            tail = delete_from_big(tail);
        }
        else if(pos==length)
        {
            tail = delete_from_end(tail);
        }
        else
        {
            int i=1;
            node *current=tail->next,*prev;
            while(i<pos)
            {
                i++;
                prev=current;
                current=current->next;
            }
            prev->next=current->next;
            current->next=0;
            free(current);
        }
        
    }
    return tail;
}

int main()
{
    node *head = 0, *tail = 0;

    tail = create_list(tail);
    print_list(tail);
    tail = delete_from_big(tail);
    print_list(tail);
    tail = delete_from_end(tail);
    print_list(tail);
    tail = delete_at_pos(tail);
    print_list(tail);
}