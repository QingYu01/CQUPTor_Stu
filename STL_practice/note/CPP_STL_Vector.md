# CPP\_STL\_Vector

***

## 10.2.2 vector 容器

### 1、vector 容器简介

* vector 是将元素置于一个动态数组中加以管理的容器。
* vector 可以随机存取元素（支持索引值直接存取，用 \[] 操作符或 at() 方法，这个等下会详讲）。
* vector 尾部添加或移除元素非常快速。但是在中部或头部插入元素或移除元素比较费时。

### 2、vector 对象的默认构造

vector 采用模板类实现，vector 对象的默认构造形式：

```cpp
vector<T> vecT;

vector<int> vecInt;        // 一个存放int的vector容器。
vector<float> vecFloat;    // 一个存放float的vector容器。
vector<string> vecString;  // 一个存放string的vector容器。
...                        // 尖括号内还可以设置指针类型或自定义类型。

class CA{};
vector<CA*> vecpCA;        // 用于存放CA对象的指针的vector容器。
vector<CA> vecCA;          // 用于存放CA对象的vector容器。由于容器元素的存放是按值复制的方式进行的，
                           // 所以此时CA必须提供CA的拷贝构造函数，以保证CA对象间拷贝正常。
```

### 3、vector 对象的带参数构造

#### 理论知识

* `vector(beg, end);` // 构造函数将 `[beg, end)` 区间中的元素拷贝给本身。注意该区间是左闭右开的区间。
* `vector(n, elem);` // 构造函数将 `n` 个 `elem` 拷贝给本身。
* `vector(const vector &vec);` // 拷贝构造函数

```cpp
int iArray[] = {0,1,2,3,4};
vector<int> vecInt(iArray, iArray+5);
// //用构造函数初始化容器vecIntB
vector<int> vecIntB(vecIntA.begin(), vecIntA.end());
vector<int> vecIntB(vecIntA.begin(), vecIntA.begin()+3);
vector<int> vecIntC(3,9); // 此代码运行后，容器vecIntB就存放3个元素，每个元素的值是9。
vector<int> vecIntD(vecIntA);
```

​

### 4、vector 的赋值

#### 理论知识

* `vector.assign(beg, end);` // 将\[beg, end)区间中的数据拷贝赋值给本身。注意该区间是左闭右开的区间。
* `vector.assign(n, elem);` // 将n个elem拷贝赋值给本身。
* `vector& operator=(const vector &vec);` // 重载等号操作符
* `vector.swap(vec);` // 将vec与本身的元素互换。

```cpp
vector<int> vecIntA, vecIntB, vecIntC, vecIntD;
int iArray[] = {0,1,2,3,4};
vecIntA.assign(iArray, iArray+5);
// 用其它容器的迭代器作参数。
vecIntB.assign(vecIntA.begin(), vecIntA.end());
vecIntB.assign(vecIntA.begin(), vecIntA.begin()+3);
vecIntC.assign(3,9); // 此代码运行后，容器vecIntB就存放3个元素，每个元素的值是9。
vector<int> vecIntD;
vecIntD = vecIntA;
vecIntA.swap(vecIntD);
```

（注：代码中 `vector<int> vecIntD;` 重复声明，实际应保留一处；注释中“容器vecIntB”应为“vecIntC”，此处按原文提取未修正。）

### 5、vector 的大小

#### 理论知识

* vector.size(); //返回容器中元素的个数
* vector.empty(); //判断容器是否为空
* vector.resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
* vector.resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。

> 例如 vecInt是vector 声明的容器，现已包含1,2,3元素。
>
> int iSize = vecInt.size(); //iSize == 3;
>
> bool bEmpty = vecInt.empty(); // bEmpty == false;
>
> 执行vecInt.resize(5); //此时里面包含1,2,3,0,0元素。
>
> 再执行vecInt.resize(8,3); //此时里面包含1,2,3,0,0,3,3,3元素。
>
> 再执行vecInt.resize(2); //此时里面包含1,2元素。

### 6、vector 末尾的添加移除操作

* vector \ vecInt;
* vecInt.push\_back(1); //在容器尾部加入一个元素
* vecInt.pop\_back();//删除一个末尾元素

### 7、vector 的数据存取

#### 理论知识

* `vec.at(idx);` //返回索引idx所指的数据，如果idx越界，抛出out\_of\_range异常。
* `vec[idx];` //返回索引idx所指的数据，越界时，运行直接报错

```cpp
vector<int> vecInt;      //假设包含1,3,5,7,9
vecInt.at(2) == vecInt[2]       ;            //5
vecInt.at(2) = 8;  或  vecInt[2] = 8;
vecInt 就包含 1,3,8,7,9值

int iF = vector.front();        //iF==1
int iB = vector.back(); //iB==9
vector.front() = 11;  //vecInt包含{11,3,8,7,9}
vector.back() = 19;   //vecInt包含{11,3,8,7,19}
```

***

### 8、vector 的插入

#### 理论知识

* `vector.insert(pos,elem);` //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
* `vector.insert(pos,n,elem);` //在pos位置插入n个elem数据，无返回值。
* `vector.insert(pos,beg,end);` //在pos位置插入\[beg,end)区间的数据，无返回值

**简单案例**

```cpp
vector<int> vecA;
vector<int> vecB;

vecA.push_back(1); 
vecA.insert(vecA.begin(), 1); //第一个形参必须是指针！！！
vecA.insert(vecA.begin()+1,2,33);
vecA.insert(vecA.begin() , vecB.begin() , vecB.end()); 
```

​

***

## vector 容器的 iterator 类型

* &#x20;vector\::iterator iter; //变量名为iter
* &#x20;vector容器的迭代器属于“随机访问迭代器”：迭代器一次可以移动多个位置

| **成员函数**            | **功能**                                                                       |
| ------------------- | ---------------------------------------------------------------------------- |
| begin()             | 返回指向容器中第一个元素的正向迭代器；如果是 const 类型容器，在该函数返回的是常量正向迭代器。                           |
| end()               | 返回指向容器最后一个元素之后一个位置的正向迭代器；如果是 const 类型容器，在该函数返回的是常量正向迭代器。此函数通常和 begin() 搭配使用。 |
| rbegin()            | 返回指向最后一个元素的反向迭代器；如果是 const 类型容器，在该函数返回的是常量反向迭代器。                             |
| rend()              | 返回指向第一个元素之前一个位置的反向迭代器。如果是 const 类型容器，在该函数返回的是常量反向迭代器。此函数通常和 rbegin() 搭配使用。   |
| cbegin()            | 和 begin() 功能类似，只不过其返回的迭代器类型为常量正向迭代器，不能用于修改元素。                                |
| cend()              | 和 end() 功能相同，只不过其返回的迭代器类型为常量正向迭代器，不能用于修改元素。                                  |
| crbegin()           | 和 rbegin() 功能相同，只不过其返回的迭代器类型为常量反向迭代器，不能用于修改元素。                               |
| crend()             | 和 rend() 功能相同，只不过其返回的迭代器类型为常量反向迭代器，不能用于修改元素。                                 |
| erase(iterator pos) | 删除指定迭代器位置的元素                                                                 |

​
