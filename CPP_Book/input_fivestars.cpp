#include<iostream>
using namespace std;
void showfivestars(int num);

int main(){
    showfivestars(5);
    return 0;
}
void showfivestars(int num){
    for(int i=0;i<num;i++){
        for (int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}