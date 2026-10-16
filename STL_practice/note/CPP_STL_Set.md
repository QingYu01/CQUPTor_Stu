# CPP\_STL\_Set

## 目录

* [set/multiset 容器简介](#setmultiset-容器简介)
* [set/multiset 容器对象的默认构造](#setmultiset-容器对象的默认构造)
* [set 容器插入与迭代器](#set-容器插入与迭代器)
* [set 容器拷贝构造与赋值](#set-容器拷贝构造与赋值)
* [set 容器的大小](#set-容器的大小)
* [set 容器的删除](#set-容器的删除)
* [set 容器的元素排序](#set-容器的元素排序)
* [set 容器的查找](#set-容器的查找)

## set/multiset 容器简介

* set `是一个集合容器，其中所包含的元素是唯一的，集合中的元素按一定的顺序排列。元素插入过程是按排序规则插入，所以不能指定插入位置`。
* set `采用红黑树变体的数据结构实现，红黑树属于平衡二叉树。在插入操作和删除操作上比 vector 快`。
* set `不可以直接存取元素（不可以使用 at(pos) 与 [] 操作符）`。
* **multiset 与 set 的区别：set 支持唯一键值，每个元素值只能出现一次；而 multiset 中同一值可以出现多次**。
* 不可以直接修改 set 或 multiset 容器中的元素值，因为该类容器是自动排序的。如果希望修改一个元素值，必须先删除原有的元素，再插入新的元素。
* `#include <set>`

## set/multiset 容器对象的默认构造

```cpp
set<int> setInt;                    // 一个存放 int 的 set 容器。
set<float> setFloat;                // 一个存放 float 的 set 容器。
set<string> setString;              // 一个存放 string 的 set 容器。
multiset<int> mulsetInt;            // 一个存放 int 的 multiset 容器。
multiset<float> multisetFloat;      // 一个存放 float 的 multiset 容器。
multiset<string> multisetString;    // 一个存放 string 的 multiset 容器。
```

## set 容器插入与迭代器

* `set.insert(elem);` // 在容器中插入元素。
* `set.begin();` // 返回容器中第一个数据的迭代器。
* `set.end();` // 返回容器中最后一个数据之后的迭代器。
* `set.rbegin();` // 返回容器中倒数第一个元素的迭代器。
* `set.rend();` // 返回容器中倒数最后一个元素的后面的迭代器。

### 示例代码

```cpp
set<int> setInt;
setInt.insert(3);
setInt.insert(1);
setInt.insert(5);
setInt.insert(2);
for(set<int>::iterator it=setInt.begin(); it!=setInt.end(); ++it)
{
    int iItem = *it;
    cout << iItem;      // 或直接使用 cout << *it
}
// 这样子便顺序输出 1 2 3 5。
```

## set 容器拷贝构造与赋值

* `set(const set &st);` // 拷贝构造函数
* `set& operator=(const set &st);`
* `set.swap(st);` // 交换两个集合容器

### 示例代码

```cpp
set<int> setIntA;
setIntA.insert(3);
setIntA.insert(1);
setIntA.insert(7);
setIntA.insert(5);
setIntA.insert(9);

set<int> setIntB(setIntA);  // 1 3 5 7 9
set<int> setIntC;
setIntC = setIntA;         // 1 3 5 7 9

setIntC.insert(6);
setIntC.swap(setIntA);     // 交换
```

## set 容器的大小

* `set.size();` // 返回容器中元素的数目
* `set.empty();` // 判断容器是否为空

### 示例代码

```cpp
set<int> setIntA;
setIntA.insert(3);
setIntA.insert(1);
setIntA.insert(7);
setIntA.insert(5);
setIntA.insert(9);

if (!setIntA.empty()) {
    int iSize = setIntA.size(); // 5
}
```

## set 容器的删除

* `set.clear();` // 清除所有元素
* `set.erase(pos);` // 删除 pos 迭代器所指的元素，返回下一个元素的迭代器。
* `set.erase(beg,end);` // 删除区间 \[beg,end) 的所有元素
* `set.erase(elem);` // 删除容器中值为 elem 的元素。

### 删除区间内的元素

setInt 是用 set\ 声明的容器，现已包含按顺序的 1,3,5,6,9,11 元素。

```cpp
set<int>::iterator itBegin=setInt.begin();
++itBegin;
set<int>::iterator itEnd=setInt.begin();
++itEnd;
++itEnd;
++itEnd;
setInt.erase(itBegin,itEnd);
//此时容器setInt包含按顺序的1,6,9,11四个元素。
```

### 删除容器中第一个元素

`setInt.erase(setInt.begin());` //6,9,11

### 删除容器中值为 9 的元素

`setInt.erase(9);`

### 删除 setInt 的所有元素

`setInt.clear();` //容器为空

## set 容器的元素排序

* 要解决如上两个问题，需要了解容器的函数对象，也叫伪函数，英文名叫 functor。

```cpp
set<int, less<int>> setIntA; // 该容器是按升序方式排列元素。
set<int, greater<int>> setIntB; // 该容器是按降序方式排列元素。
set<int> 相当于 set<int, less<int>>。
```

* `less<int>` 与 `greater<int>` 中的 `int` 可以改成其它类型，该类型主要需与 set 容纳的数据类型一致。

## set 容器的查找

* `set.find(elem);` // 查找 elem 元素，返回指向 elem 元素的迭代器。
* `set.count(elem);` // 返回容器中值为 elem 的元素个数。对 set 来说，要么是 0，要么是 1。对 multiset 来说，值可能大于 1。
* `set.lower\_bound(elem);` // 返回第一个 >=elem 元素的迭代器。
* `set.upper\_bound(elem);` // 返回第一个 >elem 元素的迭代器。
