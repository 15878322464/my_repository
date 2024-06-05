// algorithm 是一个算法库，应用于容器类,可分为三大类（旧版还有muneric,不过c++11已经将其单独摘离algorithm）。

 一.非修改式序列操作  
// 1.for_each for循环的替代品
```cpp
void printt(const double db){cout<<db;} // 用于for_each的函数是不能修改容器内元素的，因为它只将元素值复制传递。
vector<double> pd={1.10,1.20,1.30};
for_each(pd.engin(),pd.end(),printt) //第一第二参数都是迭代器参数，表示要遍历的区域，第三个是是函数名表示要执行的函数，其参数必须是容器元素类型,并且只能是一个参数
```
// 2.基于范围的for循环(适用于一切数组、容器)
```cpp
for(auto x:pd){cout<<x;} // 
for(auto x:pd)printt(x); // 也可以直接在后面跟函数
```

 二.修改式序列操作  
// 1.randmon_shuffle 给容器内元素打乱顺序，随机排列（新版更倾向于shuffle,因为它可以使用自定义的随机引擎函数）
```cpp
#include<random>
randmon_shuffle(pd.begin(),pd.end()); // 这将使用默认的伪随机函数,每次结果都是固定的，并不友好
    std::random_device rd;
    std::mt19937 gen(rd()); // 随机数引擎
randmon_shuffle(pd.begin(),pd.end()，gen);
shuffle(pd.begin(),pd.end()，gen); // 听说shuffle效果会更好，也支持自定义的随机数引擎
```

 三.排序和相关操作  
// 1.short 排序函数
```cpp
short(pd.begin(),pd.endl()) // 默认按照升序排序
short(pd.begin(),pd.endl(),functionName) // 也可以直接自己指定自定义的函数名,以自己的方式排顺序
// 如果元素是自定义对象，则必须自定义重载<或者>，该类运算符
```

