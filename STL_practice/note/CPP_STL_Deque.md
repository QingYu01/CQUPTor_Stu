# CPP\_STL\_Deque

## deque容器简介

* deque是“double-ended queue”的缩写，和vector一样都是STL的容器
* deque是双端数组而vector是单端的。
* deque在接口上和vector非常相似，在许多操作的地方可以直接替换。
* deque可以随机存取元素（支持索引值直接存取，用`[]`操作符或`at()`方法）
* deque头部和尾部添加或移除元素都非常快速。但是在中部安插元素或移除元素比较费时。
* `#include <deque>`

## deque容器的操作

* deque与vector在操作上几乎一样，deque多两个函数
  * `deque.push_front(elem);` //在容器头部插入一个数据
  * `deque.pop_front();` //删除容器第一个数据
