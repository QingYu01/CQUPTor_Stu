#include<iostream>
using namespace std;
#define A -1;
int main(){
    #if A>0
        cout<<"a>0\n";
    #elif A<0
           cout<<"a<0\n";
    #else
        cout<<"a=0\n";
    #endif  
        return 0;
}