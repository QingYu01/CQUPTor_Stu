#include<iostream>
using namespace std;
int i=10;

int main(){
    int i=20;
    {
        int i=5;
        int j;
        ::i=::i+4;
        j=::i+i;
        cout<<"::i="<<::i<<",j="<<j<<"\n";
    }
    cout<<"::i"<<::i<<",i="<<i<<"\n";
    return 0;
}