#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number(greter than 1): ";
    cin>>n;
    int pre_fibo=1,pre_pre_fibo=0,fibo;
    if(n==1)
    {
        cout<<n<<" fibonaci number is 0";
    }
    else if(n==2)
    {
        cout<<n<<" fibonaci number is 1";
    }
    else if(n>2)
    {
        for(int i=3;i<=n;i++)
        {
            fibo=pre_fibo+pre_pre_fibo;
            pre_pre_fibo=pre_fibo;
            pre_fibo=fibo;            
            
        }
        cout<<n<<"Fibonacci number is: "<<fibo;
    }
    else
    cout<<"Enter number less than 1..";

}