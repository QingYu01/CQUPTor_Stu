#include<iostream>
using namespace std;
int main(){
    char Grade;
    cout<<"input your grade (A~E):";
    cin>>Grade;
    switch (Grade)
    {
    case 'A':
    case 'a' :    cout<<"Your grade between 90 and 100"<<endl;
        break;
    case 'B':
    case 'b':  cout<<"Your grade between 80 and 90"<<endl;
    break;

    case 'C':
    case 'c':  cout<<"Your grade between 70 and 80"<<endl;
    break;

    case 'D':
    case 'd':  cout<<"Your grade between 60 and 70"<<endl;
    break;

    case 'E':
    case 'e':  cout<<"Your grade between 0 and 60"<<endl;
    break;
    
    default: 
        cout<<"Your grade is invalid"<<endl;
        break;
    }
    return 0;
}