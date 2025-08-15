#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i=i+1)
    {
        sum=sum+i;
    }
    cout<<"Sum of "<<n<<" Natural number is : "<<sum;


}