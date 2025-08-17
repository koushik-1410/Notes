//     A
//    AB
//   ABC
//  ABCD
// ABCDE



#include<iostream>
using namespace std;
int main()
{
    int i,j;
    int n=6;
    char ch='A';
    for(i=1;i<=n;i++)
    {
        ch='A';
        for(j=1;j<=n;j++)
        {
            if(j<=n-i)
            {
                cout<<"  ";
            }
            else
            {
                cout<<ch<<" ";
                ch++;
            }
        }
        cout<<endl;
    }

}