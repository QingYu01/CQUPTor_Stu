#include<iostream>
#include<cstring>
using namespace std;
struct Person{
    int age;
    char sex;
    float weight;
    char name[25];
};
int main(){
    struct Person one ;
    struct Person *p;
    p=&one;
    p->age=32;              p->sex='M';     p->weight=(float)80.2;
    strcpy(p->name,"LingMing");
    cout<<"The name is:"<<p->name<<endl
        <<"The sex is:"<<p->sex<<endl
        <<"The weight is:"<<p->weight<<endl
        <<"The age is:"<<p->age<<endl;
    return 0;
}