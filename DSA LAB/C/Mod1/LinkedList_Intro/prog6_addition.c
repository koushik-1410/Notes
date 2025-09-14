#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int coef,expo;
    struct node *next;
}node;

node * createnode(int coef,int expo)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->coef=coef;
    newnode->expo=expo;
    newnode->next=0;
    return newnode;
}

void insertTerm(node **poly,int coef,int expo)
{
    // int coef, expo;
    // printf("Enter the coefficient: ");
    // scanf("%d", &coef);
    if(coef == 0)
        return;

    // printf("Enter the exponent: ");
    // scanf("%d", &expo);

    node *newnode = createnode(coef, expo);

    // Case 1: Empty list OR insert at beginning
    if (*poly == NULL || (*poly)->expo < expo) {
        newnode->next = *poly;
        *poly = newnode;
    }
    else {
        node *temp = *poly, *prev = NULL;

        // Traverse until right place found
        while (temp && temp->expo > expo) {
            prev = temp;
            temp = temp->next;
        }

        // Case 2: Same exponent exists → add coefficients
        if (temp && temp->expo == expo) {
            temp->coef += coef;
            free(newnode);

            // If coefficient becomes 0 → delete node
            if (temp->coef == 0) {
                if (prev)
                    prev->next = temp->next;
                else
                    *poly = temp->next;
                free(temp);
            }
        }
        // Case 3: Insert new term at correct position
        else {
            newnode->next = temp;
            if (prev)
                prev->next = newnode;
        }
    }
}

void printpoly(node *poly)
{
    if(!poly)
    {
        printf("0\n");
        return;
    }
    else 
    {
        int first=1;
        while(poly)
        {
            if(first)
            {
                printf("%dX^%d",poly->coef,poly->expo);
                first=0;
            }
            else
            {
                if(poly->coef>0)
                    printf("+%dX^%d",poly->coef,poly->expo);
                else
                    printf("%dX^%d",poly->coef,poly->expo);
            }
            poly=poly->next;
        }
    }
    printf("\n");

}

void addpoly(node *poly1,node *poly2,node **add)
{
    while (poly1)
    {
        insertTerm(add,poly1->coef,poly1->expo);
        poly1=poly1->next;
    }
    while (poly2)
    {
        insertTerm(add,poly2->coef,poly2->expo);
        poly2=poly2->next;
    }
    return;
}

void multiplypoly(node *poly1,node *poly2,node **mult)
{
    for(node *i = poly1;i;i=i->next)
    {
        for(node *j = poly2;j;j=j->next)
        {
            insertTerm(mult,i->coef*j->coef,i->expo+j->expo);
        }
    }

}

int main()
{
    node *poly=0,*poly1=0,*poly2=0,*add=0,*mult=0;
    int choice=1,subchoice=1,expo,coef;
    do
    {
        printf("A.enter 1 to Insert a term.\nB:Enter 2 to add.\nC.Enter 3 to multiply.\nD.Enter 4 to print.E.Enter 0 to exit.\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter 1 to insert at polynomial 1.\nEnter 2 to insert into polynomial 2.\nEnter: ");
            scanf("%d",&subchoice);
            if(subchoice==1)
            {
                printf("Enter the coeffcient: ");
                scanf("%d",&coef);
                printf("Enter the exponent: ");
                scanf("%d",&expo);
                insertTerm(&poly1,coef,expo);
            }
            else if(subchoice==1)
            {
                printf("Enter the coeffcient: ");
                scanf("%d",&coef);
                printf("Enter the exponent: ");
                scanf("%d",&expo);
                insertTerm(&poly2,coef,expo);
            }
            else{
                printf("Invalid choice.");
            }
            break;
        case 2:
            addpoly(poly1,poly2,&add);
            break;
        case 3:
            multiplypoly(poly1,poly2,&mult);
        case 4:
            printpoly(poly);
            break;
        case 0:
            choice=0;
            break;
        default:
            printf("Invalid input.");
        }
    } while (choice);
    
}