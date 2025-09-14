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

node *del_from_big(node *head)
{
    if (head == 0)
    {
        printf("THe list is empty..");
        return 0;
    }
    else if (head->next == 0 && head->prev == 0)
    {
        free(head);
        return 0;
    }
    else
    {
        node *temp = head;
        head = temp->next;
        head->prev = 0;
        free(temp);
        return head;
    }
}

node *del_from_end(node *tail)
{
    if (tail == 0)
    {
        printf("List is empty");
        return 0;
    }
    else if (tail->prev == 0 && tail->next == 0)
    {
        free(tail);
        return 0;
    }
    else
    {
        node *temp = tail;
        tail = temp->prev;
        tail->next = 0;
        free(temp);
        return tail;
    }
}

void delete_from_pos(node *head)
{

    if (head == 0)
    {
        printf("List is Empty");
        return;
    }
    else
    {
        int pos;
        printf("Enter the the postion");
        scanf("%d", &pos);
        int length = get_length(head);
        if (pos < 1 && pos > length)
        {
            printf("Invalid position.");
            return;
        }
        else if (pos == 1)
            del_from_big(head); // but it does not work
        else if (pos == length)
            del_from_end(head); // it also does not work
        else
        {
            int i = 1;
            while (i < pos)
            {
                i++;
                head = head->next;
            }
            (head->prev)->next = head->next;
            (head->next)->prev = head->prev;
            free(head);
        }
    }
}

int main()
{
    node *head = 0, *tail = 0;
    create_list(&head, &tail);
    print_list_big(head);
    print_list_end(tail);
    head = del_from_big(head);
    if (head == 0)
        tail = 0;
    print_list_big(head);
    print_list_end(tail);
    tail = del_from_end(tail);
    if (tail == 0)
        head = 0;
    print_list_big(head);
    print_list_end(tail);
    delete_from_pos(head);
    print_list_big(head);
    print_list_end(tail);
}