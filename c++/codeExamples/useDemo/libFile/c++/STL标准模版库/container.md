// c++11总共有以下几种：
```cpp
// 序列容器
1.deque 双向队列与vector类似，但是只能前后插入、删除数据（需要在两端频繁插入、删除和随机访问的，选他）
2.list 双向链表（需要在中间频繁插入删除的、不关心随机访问的，选他，）
3.queue 队列，先进先出，只能尾部排队进，头部一个个出，不能随意删除某个元素，删除了前一个才能删除后一个
4.priority_queue 优先队列,数据放进去后会被排序，默认是按数值从大到小排序，也可以自定义排序方式，之后可以.top()取出优先级最高的值。（当你想实时获得最高优先级的数据，而不考虑随机访问时，选他）
5.stack 栈，后进先出，例如函数递归
6.vector 动态数组的类表示，能自动扩容（需要频繁遍历的，和随机访问的选他）
7.forward_list 单链表，（需要在头部频繁插入时），我们还可以使用单链表实现队列，两者并不冲突

// 关联容器（使用红黑树）
8.map 键值对，键是唯一的,一个键对应一个值
9.multimap 键和值都没有唯一性，一个键可以对应多个值，插入总是成功的
10.set 有序的集合数据结构，不允许相同的元素存在(插入已存在的元素则该操作将被忽略)，默认按升序排序，也可使用第二个参数使用自定义排顺序函数
11.multiset 有序的集合数据结构，允许有多个相同值

// 无序关联容器（使用哈希表，查找速度最快O(1)，旨在关联容器的基础上，提高插入、删除、查找的效率）
12.unordered_map 
13.unordered_multimap
14.unordered_set
15.unorfered_multiset

bitset
```
// 迭代器
```cpp

```
