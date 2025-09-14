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
    // node *head=*h,*tail=*t;
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

node *insert_at_big(node *head)
{
    node *newnode = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    newnode->prev = 0;
    head->prev = newnode;
    return newnode;
}

node *insert_at_end(node *tail)
{
    node *newnode = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->prev = tail;
    tail->next = newnode;
    return newnode;
}

int get_length(node *head)
{
    int count = 0;
    if (head == 0)
        return 0;
    else
    {
        while (head != 0)
        {
            count++;
            head = head->next;
        }
    }
    return count;
}

void insert_at_pos(node *head)
{

    int pos, length = get_length(head);
    printf("Enter the position where to enter (%d-%d): ", 2, length);
    scanf("%d", &pos);
    if (pos < 1 && pos > length)
    {
        printf("Invalid Index..");
        return;
    }
    else if(pos==1)
    {
        insert_at_big(head);//head is not global so it does not work
    }
    else
    {
        int i = 1;
        while (i < pos)
        {
            i++;
            head = head->next;
        }
        // printf("%d",head->data);
        node *newnode = (node *)malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->prev=head->prev;
        newnode->next=head;
        (head->prev)->next=newnode;
        head->prev=newnode;
    }
}

void insert_after_pos(node *head)
{
        int pos, length = get_length(head);
    printf("Enter the position where to enter (%d-%d): ", 1, length-1);
    scanf("%d", &pos);
    if (pos < 1 && pos > length)
    {
        printf("Invalid Index..");
        return;
    }
    // else if(pos==length)
    // {
    //     insert_at_end(tail);//tail is not global so it does not work
    // }
    else
    {
        int i = 1;
        while (i <= pos)//here head goes to the next position,becoz i is now pos+1,head is also at pos+1
        {
            i++;
            head = head->next;
        }
        // printf("%d",head->data);
        node *newnode = (node *)malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->prev=head->prev;
        newnode->next=head;
        (head->prev)->next=newnode;
        head->prev=newnode;
    }
    

}

int main()
{
    node *head = 0, *tail = 0;
    create_list(&head, &tail);
    print_list_big(head);
    print_list_end(tail);
    head = insert_at_big(head);
    print_list_big(head);
    print_list_end(tail);
    tail = insert_at_end(tail);
    print_list_big(head);
    print_list_end(tail);
    insert_at_pos(head);
    print_list_big(head);
}