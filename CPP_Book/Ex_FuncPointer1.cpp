#include<iostream>
using namespace std;
double add(double x,double y){
    return (x+y);
}
double mul(double x,double y){
    return (x*y);
}
int main(){
    double (*func)(double,double);
    double a,b;
    char op;
    cout<<"input two number and style:";
    cin>>a>>b>>op;
    if(op='+'){
        func=add;
    }else{
        func==mul;
    }
    cout<<a<<op<<b<<"="<<func(a,b)<<endl;
    return 0;
}