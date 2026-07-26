#include<iostream>
using namespace std;
int main(){
    int num=1,sum=0;
    while(num<=50){
        sum+=num;
        num++;
    }
    cout<<"the sum is:"<<sum;
    return 0;
}