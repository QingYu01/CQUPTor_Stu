#include<iostream>
#include<cstring>
using namespace std;
class CName{
    public:
            CName(){                //默认构造函数:将指针初始化为 NULL，表示无字符串
                strName=NULL;
            }
            CName(char *str)            //带一个 char* 参数的构造函数
            {
                strName=(char *)new char[strlen(str)+1];//根据传入字符串的长度（strlen(str)）动态分配足够的内存，加 1 用于存放 \0
                strcpy(strName,str);    //使用 strcpy 复制字符串内容
            }
            CName(CName&one){       //拷贝构造函数（深拷贝）:v为目标对象分配独立的新内存，并复制原对象字符串的内容。这样两个对象拥有各自的字符串，互不影响
                strName=(char *)new char[strlen(one.strName)+1];
                strcpy(strName,one.strName);
            }
            CName(CName&one,char*add){  //带两个参数的构造函数
                strName=(char *)new char[strlen(one.strName)+strlen(add)+1];
                strcpy(strName,one.strName);
                strcat(strName,add);//先复制原字符串，再用 strcat 拼接附加字符串
            }
            ~CName(){//析构函数
                if(strName)delete []strName;
                strName=NULL;
            }
            char*getName(){
                return strName;
            }
            private:
                    char * strName;
};
int main(){
    CName o1("DanKING");// 调用 CName(char*) 构造函数
    CName o2(o1); // 调用拷贝构造函数 CName(CName&)
    cout<<o2.getName()<<endl;
    CName o3(o1,"MESSI");
    cout<<o3.getName()<<endl;
    return 0;
}