#include<iostream>
using namespace std;
#define LI;
int main(){
    #ifdef LI
        cout<<"Hello LI!\n";
    #else
        cout<<"Hello,everyone!\n";
    #endif
        return 0;
}