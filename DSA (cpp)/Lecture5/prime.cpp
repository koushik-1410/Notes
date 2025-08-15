#include<iostream>
using namespace std;
int main()
{
    int n,is_prime=1;
    cout<<"Enter a number: ";
    cin>>n;
    if(n<2)
    {
        is_prime=0;
    }
    else
    {
        for(int i=2;i<n;i++)
        {
            if(n%i==0)
            {
                is_prime=0;
                break;
            }
        }
    }
    if(is_prime)
    cout<<"Prime number..";
    else
    cout<<"Non prime number..";
}