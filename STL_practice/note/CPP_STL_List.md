# CPP\_STL\_List

## 一、list 容器概述

### 1.1 容器简介

* list是一个双向链表容器，可高效地进行插入删除元素。

### 1.2 核心特点

* list不可以随机存取元素，所以不支持at.(pos)函数与\[]操作符。

It++(ok)

it+5(err)

### 1.3 头文件引入

* \#include \

## 二、构造与赋值

### 2.1 默认构造

◎ list采用模板类实现,对象的默认构造形式: list \ lst 如:

```cpp
list<int> lstInt;         //定义一个存放int的list容器。
list<float> lstFloat;     //定义一个存放float的list容器。
list<string> lstString;   //定义一个存放string的list容器。
```

### 2.2 带参数构造

◎ list(n,elem); //构造函数将n个elem拷贝给本身。

◎ list(beg,end); //构造函数将\[beg,end)区间中的元素拷贝给本身(左闭右开)

◎ list(const list \&lst); //拷贝构造函数。

### 2.3 赋值操作

◎ list.assign(beg,end); //将\[beg, end)区间中的数据拷贝赋值给本身。注意该区间是左闭右开的区间。

◎ list.assign(n,elem); //将n个elem拷贝赋值给本身。

◎ list& operator=(const list \&lst); //重载等号操作符

◎ list.swap(lst); // 将lst与本身的元素互换。

示例代码：

```cpp
cpp
list<int> lstIntA, lstIntB, lstIntC, lstIntD;
lstIntA.push_back(1);
lstIntA.push_back(3);
lstIntA.push_back(5);
lstIntA.push_back(7);
lstIntA.push_back(9);

lstIntB.assign(lstIntA.begin(), lstIntA.end()); //1 3 5 7 9
lstIntC.assign(5,8); //8 8 8 8 8
lstIntD = lstIntA; //1 3 5 7 9
lstIntC.swap(lstIntD); //互换
```

## 三、迭代器

### 3.1 迭代器类型与特性

◎ list 容器的迭代器是“双向迭代器”：双向迭代器从两个方向读写容器。除了提供前向迭代器的全部操作之外，双向迭代器还提供前置和后置的自减运算。

### 3.2 常用迭代器接口

```
list.begin(); //返回容器中第一个元素的迭代器。
list.end(); //返回容器中最后一个元素之后的迭代器。
list.rbegin(); //返回容器中倒数第一个元素的迭代器。
list.rend(); //返回容器中倒数最后一个元素的后面的迭代器。
```

## 四、元素访问与容量

### 4.1 数据存取

* `list.front()` 用于获取链表中第一个元素的值。
* `list.back()` 用于获取链表中最后一个元素的值。

### 4.2 大小操作

* `list.size();` //返回容器中元素的个数
* `list.empty();` //判断容器是否为空
* `list.resize(num);` //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
* `list.resize(num, elem);` //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。

```cpp
list<int> lstIntA;
lstIntA.push_back(1);
lstIntA.push_back(3);
lstIntA.push_back(5);

if (!lstIntA.empty())
{
int iSize = lstIntA.size(); //3
lstIntA.resize(5); //1 3 5 0 0
lstIntA.resize(7,1); //1 3 5 0 0 1 1
lstIntA.resize(2); //1 3
}
```

## 五、增删操作

### 5.1 头尾添加与移除

* `list.push_back(elem);` //在容器尾部加入一个元素
* `list.pop_back();` //删除容器中最后一个元素
* `list.push_front(elem);` //在容器开头插入一个元素
* `list.pop_front();` //从容器开头移除第一个元素

### 5.2 插入

* `list.insert(pos,elem);`//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
* `list.insert(pos,n,elem);`//在pos位置插入n个elem数据，无返回值。
* `list.insert(pos,beg,end);`//在pos位置插入\[beg,end)区间的数据，无返回值。

### 5.3 删除

◎ list.clear(); //移除容器的所有数据

◎ list.erase(beg,end); //删除\[beg,end)区间的数据，返回下一个数据的位置。

◎ list.erase(pos); //删除pos位置的数据，返回下一个数据的位置。

◎ list.remove(elem); //删除容器中所有与elem值匹配的元素。

示例代码：

```cpp
cpp
list<int>::iterator itBegin=lstInt.begin();
++itBegin;
list<int>::iterator itEnd=lstInt.begin();
++itEnd;
++itEnd;
++itEnd;
lstInt.erase(itBegin,itEnd);
//此时容器lstInt包含按顺序的1,6,9三个元素。

lstA.push_back(3);
lstA.push_back(3);
lstA.remove(3); //将list中所有的3删除
```

## 六、其他操作

### 6.1 反序排列

* `lst.reverse();` //反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素

示例代码：

```cpp
cpp
list<int> lstA;
lstA.push_back(1);
lstA.push_back(3);
lstA.push_back(5);
lstA.push_back(7);
lstA.push_back(9);

lstA.reverse(); //9 7 5 3 1
```

​
