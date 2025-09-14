#include<stdio.h>
int main()
{
    int a[2][3]={1,2,3,4,5,6};
    int i,j;
    printf("%d",*(*(a+1)));  // It does not give the correct value.
    // printf("%p",*(a+1));
    // for(i=0;i<2;i++)
    // {
    //     for(j=0;j<3;j++)
    //     {
            // printf("%d\n",*(*a+((3*i)+j)));
    //     }
    // }


    // int *p=a;
    // printf("%p\n",a[1]);
    // printf("%p\n",a[1]+1);
    // printf("%p",&a[1]+1);


    // int *p=&a;
    // printf("%d",*(*(&a+1)));






}