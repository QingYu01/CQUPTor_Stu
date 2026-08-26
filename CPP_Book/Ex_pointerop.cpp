#include<iostream>
using namespace std;
int main(){
    char a[]="wangJianYu";
    char *p1=a; char *p2=a; char temp;
    while(*p2!='\0'){
        p2++;
    }
    p2--;
    while(p1<p2){
        temp=*p1; *p1=*p2; *p2=temp;
        p1++;p2--;
    }
    cout<<a<<endl;
    return 0;
}