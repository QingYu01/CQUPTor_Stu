#include<iostream>
using namespace std;
long factorial(int n);
int main(){
    cout<<factorial(4)<<endl;
    return 0;
}
long factorial(int n){
    long result=0;
    if(n==0){
        result=1;
    }else{
        result=n*factorial(n-1);
    }
    return result;
}