#include<stdio.h>
int main()
{
    int arr[10],n,i,index,num,temp,pos;

    printf("Enter th elength of the array: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);


    printf("Enter the position where to enter,and the number want to enter: ");
    scanf("%d %d",&pos,&num);
    index=pos-1;
    // for(i=n-1;i>=index;i--)
    // {
    //    arr[i+1]=arr[i];
    // }
    // arr[index]=num;

    
    //best algo
    arr[n]=arr[index];
    arr[index]=num;

    for(i=0;i<=n;i++)
    {
    printf("%d ",arr[i]); 
    }


}