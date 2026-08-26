#include<iostream>
using namespace std;
int main(){
    int a[6]={1,2,3,4,5,6};
    int *p=a;
    int sum=0;
    for (int i=0;i<6;i++){
        sum+=*p;
        p++;
    }
    cout<<sum<<endl;
    return 0;
}