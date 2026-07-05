#include<iostream>
using namespace std;
void swap(int *x,int *y);

int main(){
    int a=7,b=11;
    swap(&a,&b);
    cout<<"a="<<a<<",b="<<b<<endl;
    return 0;
}
void swap(int *x,int *y){
    int temp;
    temp=*x; *x=*y; *y=temp;
    cout<<"x="<<*x<<",y="<<*y<<"\n";
}