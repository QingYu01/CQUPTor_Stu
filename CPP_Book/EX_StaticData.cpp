#include<iostream>
using namespace std;
class CSum{
    public :
             CSum(int a=0,int b=0){
                nSum+=a+b;//将 a + b 累加到静态成员变量 nSum 中
             }
             int getSum(){//返回静态变量 nSum 的当前值
                return nSum;
             }
             void setSum(int sum){//将 nSum 设置为指定的值
                nSum=sum;
             }
    public :
             static int nSum;//声明一个静态成员变量 nSum。静态成员属于类本身，而不是某个具体对象。所有对象共享同一个 nSum
};
int CSum::nSum;//这一行定义了 nSum
int main(){
    CSum one (10,2),two;
    cout<<"one:sum="<<one.getSum()<<endl;
    cout<<"two:sum="<<two.getSum()<<endl;
    two.setSum(5);
    cout<<"one:sum="<<one.getSum()<<endl;
    cout<<"two:sum="<<two.getSum()<<endl;
    return 0;
}