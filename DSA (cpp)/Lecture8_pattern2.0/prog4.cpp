//     1
//    21
//   321
//  4321
// 54321

#include<iostream>
using namespace std;
int main()
{
    int i,j,n=5,num=5;
    for(i=1;i<=n;i++)
    {
        num=5;
        for(j=1;j<=n;j++)
        {
            if(j<=(n-i))
            {
                cout<<"  ";
            }
            else
            {
                cout<<num-(n-i)<<" ";
                num--;
            }
        }
        cout<<endl;
    }

}