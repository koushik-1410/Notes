// a b c d e
// a b c d e
// a b c d e
// a b c d e
// a b c d e

#include<iostream>
using namespace std;

int main(){
    int i,j;
    char ch='a';
    for(i=1;i<=5;i++)
    {
        ch='a';
        for(j=1;j<=5;j++)
        {
            ch='a'+(j-1);
            cout<<ch<<" ";

        }
        cout<<endl;
    }



}
    // char ch;
    // for(i=1;i<=5;i++)
    // {
    //     for(ch='a';ch<='e';ch++)
    //     {
    //         cout<<ch<<" ";

    //     }
    //     cout<<endl;
    // }
