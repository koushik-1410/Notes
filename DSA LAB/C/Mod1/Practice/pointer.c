#include<stdio.h>
int main()
{
    int arr[]={4,5,8,2,9};
    int *q=arr;
    for(int i=0;i<5;i++)
    {
        printf("%d %p\t",arr[i],&arr[i]);
    }
    printf("\n");
    for(int i=0;i<5;i++)
    {
        printf("%d %p\t",q[i],&q[i]);
    }
    
    // printf("%d",arr[2]);
    // printf("%d",2[arr]);




    // int b = 10;
    // int* p=&b;
    // int* q=p;
    // printf("%d",*q);



    // int b = 10;
    // int* p= &b;
    // int** q=&p;
    // printf("B=%d,P=%p,Q=%p/address of p=%p,P points to %d,Q points to %p,",b,p,q,&p,*p,*q);


}