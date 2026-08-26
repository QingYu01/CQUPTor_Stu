#include<iostream>
using namespace std;
int sum(int x,int y);
int sum(int x,int y,int z);
double sum(double x,double y);
double sum(double x,double y,double z);
int main(){
    cout<<sum(2,5)<<endl;
    cout<<sum(2,5,7)<<endl;
    cout<<sum(1.2,5.0,7.5)<<endl;
    return 0;
}
int sum(int x,int y){
    return x+y;
}

int sum(int x,int y,int z){
    return x+y+z;
}

double sum(double x,double y){
    return x+y;
}

double sum(double x,double y,double z){
    return x+y+z;
}

