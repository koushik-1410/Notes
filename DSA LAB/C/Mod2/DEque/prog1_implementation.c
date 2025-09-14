#include<stdio.h>
# define N 5
int deque[N];
int front=-1,rear=-1;

void enqueuefront(int x)
{
    if(front == rear+1 || (front == 0 && rear == N-1))
    {
        printf("Queue is full.");
    }
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        deque[front]=x;
    }
    else if(front==0)
    {
        front=N-1;
        deque[front]=x;
    }
    else
    {
        front--;
        deque[front]=x;
    }
}

void enquerear(int x)
{
    
}

int main()
{
    
}