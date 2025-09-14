#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *top=0;
void push()
{
    node * newnode=(node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
}
void pop()
{
    if(top==0)
    {
        printf("Underflow Condition.");
    }
    else
    {
        node *temp=top;
        printf("Delete: %d",temp->data);  
        top=top->next;
        free(temp);
    }
}

void peek()
{
    if(top==0)
    {
        printf("Stack is empty.");
    }
    else
    {
        printf("Last data is: %d",top->data);
    }
}

void display()
{
    if(top==0)
    {
        printf("stack is empty.");
    }
    else
    {
        node *temp=top;
        while(temp!=0)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    
}