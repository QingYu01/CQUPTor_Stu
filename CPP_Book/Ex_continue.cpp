#include<iostream>
using namespace std;
int main(){
    cout<<"In 1~100,能被7乘除的数有:";
    for(int i=1;i<=100;i++){
        if(i%7!=0){
            continue;
        }else{
            cout<<i<<" ";
        }
    }
}