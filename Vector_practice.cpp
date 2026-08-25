#include <iostream>
#include <vector>
using namespace std;

/*vector<T> vecT;//用于存放T类型对象的vector容器
vector<int> vecInt;//用于存放int类型对象的vector容器
vector<float> vecFloat;//用于存放float类型对象的vector容器
vector<string> vecString;//用于存放string类型对象的vector容器

class CA{};
vector<CA> vecCA;//用于存放CA对象的vector容器
vector<CA*> vecpCA;//用于存放CA对象指针的vector容器

vector(begin,end);//用于将begin和end之间的元素拷贝到vector容器中
vector(n,element);//用于将n个element拷贝到vector容器中
vector(const vector &vec);//用于将另一个vector容器中的元素拷贝到当前vector容器中*/

//vector(begin,end)实例
// int main()
// {
//     int arr[5] = {1, 2, 3, 4, 5};
//     vector<int> vecInt(arr, arr + 5);//将数组arr中的元素拷贝到vector容器vecInt中
//     for(int i = 0; i < vecInt.size(); i++)
//     {
//         cout << vecInt[i] << " ";
//     }
//     return 0;
// }

//vector(n,element)实例
// int main(){
//     vector<int> vecInt(5, 10);//将5个10拷贝到vector容器vecInt中
//     vector<int> v3(vecInt);//将vecInt中的元素拷贝到vector容器v3中
//     for(int i = 0; i < v3.size(); i++)
//     {
//         cout << v3[i] << " ";
//     }
//     return 0;
// }

//vector.assign(begin,end)//将begin和end之间的元素赋值给当前vector容器,左闭右开区间
//vector.assign(n,element)//将n个element赋值给当前vector容器
//vector.assign(const vector &vec)//将另一个vector容器中的元素赋值给当前vector容器
//vector.swap(vec)//将当前vector容器中的元素与vec容器中的元素交换

int main(){
    vector<int> v1,v2,v3,v4;
    int arr[5] = {1, 2, 3, 4, 5};
    v1.assign(arr, arr + 5);//将数组arr中的元素赋值给v1
    v2.assign(v1.begin(), v1.end());//将v1中的元素赋值给v2
    v3.assign(5, 10);//将5个10赋值给v3
    vector <int> v5;
    v5=v1;
    v4.swap(v5);//将v4中的元素与v5中的元素交换
    for(int i = 0; i < v4.size(); i++)
    {
        cout << v4[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " ";
    }
    return 0;
}
