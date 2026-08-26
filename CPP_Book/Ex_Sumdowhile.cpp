#include<iostream>
using namespace std;
int main(){
    int  num=1,sum=0;
    do{
        sum+=num;
        num++;
    }
    while(num<=50);
    cout<<"the sum is:"<<sum;
    return 0;
}