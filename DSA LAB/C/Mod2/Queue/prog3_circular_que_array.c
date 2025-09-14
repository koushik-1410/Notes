#include<stdio.h>
# define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int n)
{
    if((rear+1)%N==front)
    {
        printf("Overflow condition.");
    }
    else if(front==-1 && rear ==-1)
    {
        front++;
        rear++;
        queue[rear]=n;
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=n;
    }

}

void dequeue()
{
    if(rear==-1 && front==-1)
    {
        printf("UNderflow condition");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        printf("Deleted element is: %d",queue[front]);
        front=(front+1)%N;
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty.");
    }
    else
    {
        int i;
        for(i=front;i!=rear;i=(i+1)%N)
        {
            printf("%d ",queue[i]);
        }
        printf("%d ",queue[rear]);
    }
}

void peek ()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty.");
    }
    else
    {
        printf("Front element is: %d",queue[front]);
    }
}

int main()
{
     

}