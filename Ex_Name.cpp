//构造函数与析构函数的应用
//strcpy()函数的作用【深拷贝与浅拷贝的区别】
#include<iostream>
#include<cstring>
using namespace std;
class CName{
    public:
        CName(){
            strName=NULL;
        }
        //无参构造函数
        CName(char *str){
            strName=(char *)new char [strlen(str)+1];//在堆区申请一块独立的新内存，大小为字符串长度+1
            strcpy(strName,str);//深拷贝，将str的内容复制给strName
        }
        //有参构造函数
        ~CName(){
            if(strName){
                delete []strName;
            }
            strName=NULL;
        }
        char *getName(){
            return strName;
        }
        //成员函数：返回strName
    private:
        char *strName;              //成员变量使用private，利于封装
};
int main(){
    char *p=new char[5];            //开辟五个字节的新内存空间，将首地址赋值给指针p
    strcpy(p,"DING");               //将值“DING”赋值给p的内存中（4+1）
    CName one(p);                   //调用有参构造函数创建类对象，传入指针p
    delete []p;                     //释放p的内存
    cout<<one.getName()<<endl;
    return 0;
}