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
    // printf("%dX^%d", poly[index].coef, poly[index].expo);
    for (int i = index - 1; i >= 0; i--)
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
int main()
{
    element poly1[10]={0};
    // printf("%d",poly1[1].coef);
    int index = create_poly(poly1);
    sort(poly1,index);
    print_poly(poly1,index);
    
}