

#include<stdio.h>
int main()
{
    int arr[10],n,i,index,num,temp,pos;

    printf("Enter th elength of the array: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);


    printf("Enter the position where to Delete: ");
    scanf("%d",&pos);
    index=pos-1;

    arr[index]=arr[n-1];
    arr[n-1]=0;
    
    for(i=0;i<n-1;i++)
    {
    printf("%d ",arr[i]); 
    }


}