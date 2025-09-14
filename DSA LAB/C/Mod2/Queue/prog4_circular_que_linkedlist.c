#include<stdio.h>
// circular linked list only 
typedef struct node
{
    int data;
    struct node *next;
}node;
node *front=0,*rear=0;

void enqueue(int x)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=0; 
    if(front==0 && rear==0)
    {
        front=rear=newnode;
    } 
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    newnode->next=front;

}

void dequeue()
{
    
    if(front==0 && rear==0)
    {
        printf("Underflow condition.");
    }
    else if(front==rear)
    {
        free(front);
        front=rear=0;
    }
    else
    {
        node *temp=front;
        front=front->next;
        free(temp);
        rear->next=front;
    }

}

void peek()
{
    if(front==0 && rear==0)
    {
        printf("Queue is empty.");
    }
    else 
    {
         printf("The first data is: %d",front->data);
    }
}


void display()
{
    if(front==0 && rear==0)
    {
        printf("Queue is empty.");
    }
    else
    {
        node *temp=front ;
        do
        {
            printf("%d>>",temp->data);
            temp=temp->next;
        }while(temp!=front);
    }
}
int main()
{
    
}