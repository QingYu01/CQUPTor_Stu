#include<iostream>
#include<cstring>
using namespace std;
class CName{
    public:
        CName(){
            strName=NULL;
        }
        CName(char *str){
            strName=(char *)new char [strlen(str)+1];
            strcpy(strName,str);
        }
        ~CName(){
            if(strName){
                delete []strName;
            }
            strName=NULL;
        }
        char *getName(){
            return strName;
        }
    private:
        char *strName;
};
int main(){
    char *p=new char[5];
    strcpy(p,"DING");
    CName one(p);
    delete []p;
    cout<<one.getName()<<endl;
    return 0;
}