#include<iostream>
using namespace std;
int main()
{
    int n,pow;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Enter the power: ";
    cin>>pow;
    int res=1;
    for(int i=1;i<=pow;i++)
    {
        res=res*n;
    }
    cout<<n<<" to the power "<<pow<<" is: "<<res;
}