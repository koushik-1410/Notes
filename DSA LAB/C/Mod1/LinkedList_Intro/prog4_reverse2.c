#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

node* create_list(node *head)
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
    } while (choice);
    return head;
}
// gpt appraoch 
node* reverse_list(node *head) {
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;

    while (next != NULL) {
        next = curr->next;     // store next node
        curr->next = prev;     // reverse current node
        prev = curr;           // move prev forward
        curr = next;           // move curr forward
    }

    return prev; // new head
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


int main()
{
    node* head=0;
    head = create_list(head);
    print_list(head);


}




















