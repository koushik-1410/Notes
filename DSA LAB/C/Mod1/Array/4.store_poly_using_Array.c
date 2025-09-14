#include <stdio.h>
int main()
{
    int poly[10] = {0}, max_exponent;
    printf("Enter the maximum exponent: ");
    scanf("%d", &max_exponent);
    for (int i = 0; i <= max_exponent; i++)
    {
        printf("Enter the Co-efficient of X^%d: ", i);
        scanf("%d", &poly[i]);
    }

    for (int i = max_exponent; i >= 1; i--)
    {
        if (poly[i] != 0)
        {
            printf("%dX^%d+", poly[i], i);
        }
    }
    if (poly[0] != 0)
    {
        printf("%d", poly[0]);
    }
}