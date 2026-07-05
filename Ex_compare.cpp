#include<iostream>
using namespace std;
int main(){
    int num1,num2;
    cout<<"input your compared nums:";
    cin>>num1>>num2;
    if (num1!=num2)
    {
        if(num1>num2){
            cout<<num1<<">"<<num2;
        }else{
            cout<<num1<<"<"<<num2;
        }
    }else{
    cout<<num1<<"="<<num2;
    }
    return 0;

}