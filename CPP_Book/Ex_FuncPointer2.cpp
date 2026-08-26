#include<iostream>
using namespace std;
double add(double x,double y){
    return (x+y);
}
double mul(double x,double y){
    return (x*y);
}
void op(double (*func)(double,double),double x,double y){
    cout<<"x="<<x<<",y="<<y<<",result="<<func(x,y)<<endl;
}
int main(){
    cout<<"use add function:";
    op(add,3,9);
    cout<<"use mul function:";
    op(mul,8,9);
    return 0;
}