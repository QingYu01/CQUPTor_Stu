#include<iostream>
#include<cstring>
using namespace std;
void change(char str1[20]);
int main(){
    char name[10]="Ding";
    cout<<name<<endl;
    change(name);
    cout<<name<<endl;
    return 0;
}
void change(char str1[20]){
    strcpy(str1,"Zheng");
}