#include<iostream>
using namespace std;
void add(double x,double y){
    cout<<x<<"+"<<y<<"="<<x+y<<endl;
}
void sub(double x,double y){
    cout<<x<<"-"<<y<<"="<<x-y<<endl;
}
void mul(double x,double y){
    cout<<x<<"*"<<y<<"="<<x*y<<endl;
}
void div(double x,double y){
    cout<<x<<"/"<<y<<"="<<x/y<<endl;
}
void (*func[4])(double,double)={add,sub,mul,div};
int main(){
    double x=3,y=7;
    char op;
    do{
        cout<<"+       -------add\n"
           << "-       -------sub\n"
            <<"*       -------mul\n"
            <<"/       -------div\n"
            <<"0       -------esc\n";
        cin>>op;
        switch (op)
        {
        case '+':  func[0](x,y);
            break;
        case '-':  func[1](x,y);
            break;
        case '*':  func[2](x,y);
            break;
        case '/':  func[3](x,y);
            break;
        case '0': cout<<"now quit the exe!"<<endl;
        return 0;
        }
    }
    while (1);
    return 0;
    
}