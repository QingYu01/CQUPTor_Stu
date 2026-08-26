#include<iostream>
using namespace std;
struct Person
{
    int age;
    float weight;
    char name[25];

};
void print (Person one){
    cout<<one.name<<"\t"
        <<one.age<<"\t"
        <<one.weight<<"\n";
}
Person all[4]={
    {20,87.76,"ZhangSan"},
    {33,34.77,"XiaoMing"},
    {76,900,"WangHaiJian"},
};
int main(){
    for (int i=0;i<3;i++){
        print(all[i]);
     
    }
       return 0;
}
