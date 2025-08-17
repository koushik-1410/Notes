// 5
// 54
// 543
// 5432
// 54321

 
#include<iostream>
using namespace std;

int main(){
    int i,j,n=5;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            cout<<(n-j+1)<<" ";
        }
        cout<<endl;
    }

}