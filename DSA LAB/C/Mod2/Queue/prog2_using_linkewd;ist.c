#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
}node ;
node *front=0,*rear=0;

void enqueue (int n)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=n;
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

}

void dequeue()
{
    if(front==0 && rear==0)
    {
        printf("Enter the queue is empty");
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
        while(temp!=0)
        {
            printf("%d>>",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{

    
}