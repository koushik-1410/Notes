#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;
int get_length(node *head, node *tail)
{
    if (head == 0 || tail == 0)
        return 0;
    int count = 1;
    while (head->next != tail)
    {
        count++;
        head = head->next;
    }
    return count+1;
}
void create_list(node **head, node **tail)
{
    node *temp, *newnode;
    int choice;
    do
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        newnode->prev = 0;
        if ((*head) == 0)
        {
            (*head) = temp = newnode;
            // newnode->prev=newnode;
            // newnode->next=head;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        newnode->next = (*head);
        printf("Enter 1 to continue,O t0 exit: ");
        scanf("%d", &choice);
    } while (choice);
    (*head)->prev = temp;
    (*tail) = temp;
}

void print_list_big(node *head)
{
    if (head == 0)
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
    if (tail == 0)
    {
        printf("NULL");
        return;
    }

    node *temp = tail;
    do
    {
        printf("%d>>", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("NULL\n");
}

void delete_from_beg(node **head,node **tail)
{
    if((*head)==0 || (*tail)==0)
    {
        return;
    }
    else if((*head)==(*tail))
    {
        free((*head));
        (*head)=(*tail)=0;
    }
    else
    {
        node * nextnode=(*head)->next;
        nextnode->prev=(*tail);
        (*tail)->next=nextnode;
        free((*head));
        (*head)=nextnode;
    }
}

void delete_from_end(node **head,node **tail)
{
    if((*head)==0 || (*tail)==0)
    {
        return;
    }
    else if((*head)==(*tail))
    {
        free((*head));
        (*head)=(*tail)=0;
    }
    else
    {
        node *prevnode=(*tail)->prev;
        prevnode->next=(*head);
        (*head)->prev=prevnode;
        free((*tail));
        (*tail)=prevnode;
    }
}

void delete_from_pos(node **head,node **tail)
{
    int pos,length=get_length((*head),(*tail));
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos<1 || pos>length)
    {
        printf("Invalid position.");
    }
    else if(pos==1)
    {
        delete_from_beg(head,tail);
    }
    else if(pos==length)
    {
        delete_from_end(head,tail);
    }
    else
    {
        int i=1;
        node *temp=(*head),*temp2;
        while(i<pos-1)
        {
            i++;
            temp=temp->next;
        }
        temp2=temp->next;
        temp->next=temp2->next;
        (temp2->next)->prev=temp2->prev;
        free(temp2);
    }
}

int main()
{
    node *head = 0, *tail;
    create_list(&head, &tail);
    print_list_big(head);
    print_list_end(tail);
    delete_from_beg(&head,&tail);
    print_list_big(head);
    print_list_end(tail);
    delete_from_end(&head,&tail);
    print_list_big(head);
    print_list_end(tail);    
    delete_from_pos(&head,&tail);
    print_list_big(head);
    print_list_end(tail); 
}