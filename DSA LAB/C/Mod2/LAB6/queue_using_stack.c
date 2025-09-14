#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;


void push(node **top,int x)
{

    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=0;
    newnode->next=(*top);
    (*top)=newnode;

}

int pop(node **top,int *y)
{
    if((*top)==0)
    {
        printf("UNderflow condition.\n");
        return 0;
    }
    // else if((*top)->next==0)
    // {
    //     int y = (*top)->data;
    //     free((*top));
    //     (*top)=0;
    //     return (char)y;
    // }
    else
    {
        (*y)= (*top)->data;
        node *temp=(*top);
        (*top)=(*top)->next;
        free(temp);
        return 1;
    }
    
}


void display(node **top)
{
    node *temp=(*top);
    while(temp!=0)
    {
        printf("%d>>",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int isempty(node **top)
{
    if((*top)==0)
        return 1;
    else
        return 0;
}

int main()
{
    int choice,length=0;
    node *top=0,*top2=0;
    do
    {
        printf("A.Enter 1 to push.\nB.ENter 2 to pop.\nC.Enter 3 to display\nD.Enter 4 to check isempty.\nEnter 5 to exit.\nEnter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                int i;
                printf("Enter the data: ");
                scanf("%d",&i);
                push(&top,i);
                length++;
                break;
            case 2:
                int y,x,loop=length;
                if(top==0)
                {
                    printf("Underflow condition.\n");
                    break;
                }
                while(loop)
                {
                    if(pop(&top,&y));
                        push(&top2,y);
                    loop--;
                }
                if(pop(&top2,&x))
                    printf("Deleted element is: %d\n",x);
                loop=length-1;
                while(loop)
                {
                    if(pop(&top2,&y));
                        push(&top,y);
                    loop--;
                }
                length--;
                // int y;
                // if(pop(&top,&y))
                // printf("The deleted element is: %d\n",y);
                // break;
                break;
            case 3:
                display(&top);
                break;
            case 4:
                if(isempty(&top))
                    printf("The stack is empty\n");
                else
                    printf("The stack is not empty\n");
                break;
            case 5:
                printf("Exiting...");
                choice=0;
                break;
            default:
                printf("Invalid choice.\n");

        }
    } while (choice);

}


