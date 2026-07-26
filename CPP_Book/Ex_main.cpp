#include<iostream>
using namespace std;
int main(int argc,char *argv[]){
        cout<<"This Program's name is:"<<argv[0]<<endl;
        if(argc<=1){
            cout<<"NO Parameter!";
           
        } else{
             int  nCount=1;
             while(nCount<argc){
                cout<<"The number "<<nCount<<"Parameter is:"<<argv[nCount]<<"\n";
                nCount++;
             }   
            }
            return 0;
}