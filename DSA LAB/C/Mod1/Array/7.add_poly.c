#include<stdio.h>

typedef struct element 
{
    int coef;
    int expo;
}element;

int create_poly(element poly[10])
{
    int choice = 1,i=0;
    do
    {
        printf("Enter the coefficient: ");
        scanf("%d",&poly[i].coef);
        printf("Enter the power of the X: ");
        scanf("%d",&poly[i].expo);
        i++;
        printf("Want to add element-(1/0): ");
        scanf("%d",&choice);
    } while (choice && i<10);
    printf("Ploynomial created\n");
    return i;
}

void sortPoly(element poly[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (poly[j].expo < poly[j+1].expo) {
                // swap terms
                element temp = poly[j];
                poly[j] = poly[j+1];
                poly[j+1] = temp;
            }
        }
    }
}

void print_poly(element poly[10],int index)
{
// if (poly[max_exponent])
//     {
//         printf("%dX^%d", poly[max_exponent], max_exponent);
//     }
    printf("%dX^%d", poly[0].coef, poly[0].expo);
    for (int i = 1; i < index; i++)
    {
        if (poly[i].coef != 0)
        {
            if (poly[i].coef > 0)
                printf("+%dX^%d", poly[i], poly[i].expo);
            else
                printf("%dX^%d", poly[i], poly[i].expo);
        }
    }
    printf("\n");

}

int addpoly(element poly1[10],element poly2[10],element res[10],int term1,int term2)
{
    int i=0,j=0,k=0;
    while(i<term1 && j<term2)
    {
        if(poly1[i].expo>poly2[j].expo)
        {
            res[k++]=poly1[i++];
        }
        else if(poly1[i].expo<poly2[j].expo)
        {
            res[k++]=poly2[j++];
        }
        else
        {
            int s = poly1[i].coef+poly2[j].coef;
            if(s)
            {
                res[k].coef=s;
                res[k].expo=poly1[i].expo;
                k++;
            }
            i++,j++;
        }
    }
    while(i<term1)
        res[k++]=poly1[i++];
    while(j<term2)
        res[k++]=poly2[j++];

    return k;
}

int main()
{
    element poly1[10],poly2[10],res[10];
    int term1= create_poly(poly1);
    sortPoly(poly1,term1);
    print_poly(poly1,term1);
    int term2=create_poly(poly2);
    sortPoly(poly2,term2);
    print_poly(poly2,term2);
    int term3=addpoly(poly1,poly2,res,term1,term2);
    print_poly(res,term3);


}