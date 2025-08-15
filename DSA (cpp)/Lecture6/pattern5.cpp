// a a a a a
// b b b b b
// c c c c c
// d d d d d
// e e e e e


#include<iostream>
using namespace std;

int main(){
    int i,j;
    char ch='a'-1;
    for(i=1;i<=5;i++)
    {
        ch=ch+1;
        for(j=1;j<=5;j++)
        {
            cout<<ch<<" ";
        }
        // ch=ch+1;
        cout<<endl;
    }

}



