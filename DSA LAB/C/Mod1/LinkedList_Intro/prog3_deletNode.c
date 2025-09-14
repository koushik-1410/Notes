// Delete node at first last and any position, get length
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;    
} node;

node * del_at_beg(node *head)
{
    if(head==NULL)
    {
        printf("No List Present");
        return 0;
    }
    else
    {
        node *ptr=head;
        head=head->next;
        free(ptr);
        return head;
    }

}

node* del_at_end(node*head)
{
    node *ptr=head,*prev_ptr;
    while(ptr->next!=0)
    {
        prev_ptr=ptr;
        ptr=ptr->next;
    }
    if(ptr==head)
    {
        head=0;
    }
    else
    {
        free(ptr);
        prev_ptr->next=NULL;
    }
    return head;
}

void del_from_pos(node *head,int length)
{
    int pos;
    printf("\nEnter the postion to delete between(%d-%d): ",2,length-1);
    scanf("%d",&pos);
    if(length<pos)
    {
        printf("Invalid Position..");
        return;
    }
    else
    {
        int i = 1;
        node *ptr=head,*prev_ptr;
        while(i<pos)
        {
            prev_ptr=ptr;
            ptr=ptr->next;
            i++;
        }
        prev_ptr->next=ptr->next;
    }

}

node* create_list(node *head,int *length)
{
    int choice;
    node *temp=NULL;
    do
    {
        node *newnode = (node*)malloc(sizeof(node));
        printf("Enter a value: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
            temp=head=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Enter 1 to continue,0 to exit: ");
        scanf("%d",&choice);
        (*length)++;
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
    printf("Null");
}


int get_length(node *head)
 {
    if(head==0)
        return 0;
    else
    {
        int count=0;
        while(head!=0)
        {
            count++;
            head=head->next;
        }   
        return count;
    }
    
 }

int main()
{
        int length=0;
        node* head=0;
        head = create_list(head,&length);
        length=get_length(head);
        printf("THe length of the list is: %d\n",length);
        print_list(head);
        head=del_at_beg(head);
        length=get_length(head);
        printf("\nTHe length of the list is: %d\n",length);
        print_list(head);
        head=del_at_end(head);
        length=get_length(head);
        printf("\nTHe length of the list is: %d\n",length);
        print_list(head);
        del_from_pos(head,length);
        length=get_length(head);
        printf("THe length of the list is: %d\n",length);
        print_list(head);
}