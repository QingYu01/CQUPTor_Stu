#include<iostream>
using namespace std;
void swap(float a,float b){
    float temp;
    temp=a;a=b;b=temp;
    cout<<"a="<<a<<",b="<<b<<"\n";
}
int main(){
    float x=22,y=98;
    cout<<"x="<<x<<",y="<<y<<"\n";
    
    swap(x,y);

    cout<<"x="<<x<<",y="<<y<<"\n";
    return 0;
}