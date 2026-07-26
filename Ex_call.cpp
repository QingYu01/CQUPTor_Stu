#include<iostream>
using namespace std;
void printstarts(int row,int col){
    for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
               cout<<"*";
        }
        cout<<"\n";
    }
}

int main(){
    printstarts(3,2);
    return 0;
}


