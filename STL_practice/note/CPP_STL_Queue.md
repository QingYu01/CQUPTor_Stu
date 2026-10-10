# CPP\_STL\_Queue

## queue 容器简介

* queue 是队列容器，是一种"先进先出"（FIFO）的容器。
* 使用时需包含头文件：`#include <queue>`

## queue 对象的默认构造

queue 采用模板类实现，默认构造形式为 `queue<T> q;`，例如：

```cpp
queue<int> queInt;       // 一个存放 int 的 queue 容器
queue<float> queFloat;   // 一个存放 float 的 queue 容器
queue<string> queString; // 一个存放 string 的 queue 容器
```

## queue 容器的 push() 与 pop() 方法

* `queue.push(elem);` // 往队尾添加元素
* `queue.pop();` // 从队头移除第一个元素

示例代码：

```cpp
queue<int> queInt;
queInt.push(1);
queInt.push(3);
queInt.push(5);
queInt.push(7);
queInt.push(9);
queInt.pop();
queInt.pop();
// 此时 queInt 存放的元素是 5, 7, 9
```

## queue 对象的拷贝构造与赋值

* `queue(const queue &que);` // 拷贝构造函数
* `queue& operator=(const queue &que);` // 重载等号操作符

示例代码：

```cpp
queue<int> queIntA;
queIntA.push(1);
queIntA.push(3);
queIntA.push(5);
queIntA.push(7);
queIntA.push(9);

queue<int> queIntB(queIntA); // 拷贝构造
queue<int> queIntC;
queIntC = queIntA;           // 赋值
```

## queue 容器的数据存取

* `queue.back();` // 返回最后一个元素
* `queue.front();` // 返回第一个元素

示例代码：

```cpp
queue<int> queIntA;
queIntA.push(1);
queIntA.push(3);
queIntA.push(5);
queIntA.push(7);
queIntA.push(9);

int iFront = queIntA.front(); // 1
int iBack = queIntA.back();   // 9

queIntA.front() = 11; // 11
queIntA.back() = 19;  // 19
```

## queue 容器的大小

* `queue.empty(); // 判断队列是否为空`
* `queue.size(); // 返回队列的大小`

示例代码：

```cpp
queue<int> queIntA;
queIntA.push(1);
queIntA.push(3);
queIntA.push(5);
queIntA.push(7);
queIntA.push(9);

if (!queIntA.empty())
{
    int iSize = queIntA.size(); // 5
}
```

​
