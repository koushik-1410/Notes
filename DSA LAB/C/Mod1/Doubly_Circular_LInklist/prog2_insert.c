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

void insert_at_big(node **head, node **tail)
{

    node *newnode = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    if(head==0 || tail==0)
    {
        (*head)=(*tail)=newnode;
        newnode->next=(*head);
        newnode->prev=(*head); 
    }
    newnode->next = (*head);
    newnode->prev = (*tail);
    (*tail)->next = newnode;
    (*head)->prev = newnode;
    (*head) = newnode;
}

void insert_at_end(node **head, node **tail)
{
    
    node *newnode = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    if(head==0 || tail==0)
    {
        (*head)=(*tail)=newnode;
        newnode->next=(*head);
        newnode->prev=(*head); 
        return ;
    }
    newnode->next = (*head);
    newnode->prev = (*tail);
    (*tail)->next = newnode;
    (*head)->prev = newnode;
    (*tail) = newnode; 
}

void insert_at_pos(node **head,node **tail)
{
    int pos,length=get_length((*head),(*tail));
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos<1 || pos>length+1)
    {
        printf("Position is invalid.");
    }
    else
    {
        if(pos==1)
        insert_at_big(head,tail);
        else if(pos==length+1)
        insert_at_end(head,tail);
        else
        {
            int i=1;
            node *temp1=(*head),*temp2,*newnode;

            while (i<pos-1)
            {
                i++;
                temp1=temp1->next;
            }
            temp2=temp1->next;
            newnode=(node *)malloc(sizeof(node));
            printf("Enter the data: ");
            scanf("%d",&newnode->data);
            newnode->next=temp2;
            newnode->prev=temp1;
            temp1->next=newnode;
            temp2->prev=newnode;            
        }
    }

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



int main()
{
    node *head = 0, *tail;
    create_list(&head, &tail);
    print_list_big(head);
    print_list_end(tail);
    insert_at_big(&head, &tail);
    print_list_big(head);
    print_list_end(tail);
    printf("%d\n", get_length(head, tail));
    insert_at_end(&head, &tail);
    print_list_big(head);
    print_list_end(tail);
    printf("%d\n", get_length(head, tail));
    insert_at_pos(&head,&tail);
    print_list_big(head);
    print_list_end(tail);
}