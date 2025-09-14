#include <stdio.h>

int poly(int poly[10])
{
    int max_exponent;
    printf("Enter the maximum exponent: ");
    scanf("%d", &max_exponent);
    for (int i = 0; i <= max_exponent; i++)
    {
        printf("Enter the Co-efficient of X^%d: ", i);
        scanf("%d", &poly[i]);
    }
    return max_exponent;
}

void printpoly(int poly[10], int max_exponent)
{

    if (poly[max_exponent])
    {
        printf("%dX^%d", poly[max_exponent], max_exponent);
    }
    for (int i = max_exponent - 1; i >= 1; i--)
    {
        if (poly[i] != 0)
        {
            if (poly[i] > 0)
                printf("+%dX^%d", poly[i], i);
            else
                printf("%dX^%d", poly[i], i);
        }
    }
    if (poly[0] != 0)
    {
        if (poly[0] > 0)
            printf("+%d", poly[0]);
        else
            printf("%d", poly[0]);
    }
    printf("\n");
}

int add_poly(int poly1[10],int poly2[10],int result[10],int max_exponent1,int max_exponent2)
{
    int index = max_exponent1>max_exponent2?max_exponent1:max_exponent2;
    for(int i=index;i>=0;i--)
    {
        result[i]=poly1[i]+poly2[i];
    }
    return index;
}

int main()
{
    int poly1[10]={0}, poly2[10]={0},result[10]={0};
    printf("Enter the details of polynomial: \n");
    int max_exponent1 = poly(poly1);
    printf("Enter the details of polynomial: \n");
    int max_exponent2 = poly(poly2);
    printf("polynomial 1: \n");
    printpoly(poly1, max_exponent1);
    printf("polynomial 2: \n");
    printpoly(poly2, max_exponent2);
    int max_exponent_result=add_poly(poly1,poly2,result,max_exponent1,max_exponent2);
    printpoly(result,max_exponent_result);


    
}