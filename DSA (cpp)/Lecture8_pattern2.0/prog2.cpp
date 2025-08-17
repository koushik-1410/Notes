//     1
//    22
//   333
//  4444
// 55555

#include<iostream>
using namespace std;
int main()
{
    int i,j,n=5;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j<=(n-i))
            {
                cout<<"  ";
            }
            else
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }

}