// STL容器之vector,模版类，动态数组，长度可变，其原理就是基于new与delete,所以内存在堆上。
```cpp
#include<vector>
// declare
vetor<typeName> param;
vector<typeName> param(nElem); // nElem，元素数量，可以是变量或常量。
vector<vector<......>> pds; // 多维数组

// 也会有数组越界情况，但可以用at方法访问元素。
```

// 1. 容器中有很多通用的概念和方法，这里以vector为例一一列举
```cpp
// (1) size 输出容器所存元素数量
vector<double> pd={1.02,1.03};
cot<<pd.size(); // 2
// (2) swap 交换两个容器的内容
pd.swap(pd2);
// (3) 迭代器，行为就像指针,不同的容器类型，迭代器的实现也不同，但我们无需知道它是怎么实现的，因为他们的借口都相同，提供的功能也都相同。迭代器只是一种概念，具体实现称为模型。
vector<double>::iterator pdi; 
*pd=1,02;
++pd;
vector<double> pd;
auto pdi=pd.begin(); // begin、end都会返回迭代器
auto pdi=pd.end; // end返回的迭代器是指向最后一个元素的下一个元素的指针，有点类似于c风格字符串中最后的0/空字符

// (4) push_back 将元素添加到末尾
double db;
pd.push_back(db);

// (5) erase 删除给定区间的元素,接收迭代器参数
pd.erase(pd.begin(),pd.end()+2); // 可加减,这里的区间是[begin,end）,不包括end

// (6) insert 与erase相反，插入区域元素
pd.insert(pd.begin(),pd2.begin(),pd2.end()); // 第一个参数是要插入的位置，begin的话那就是插入到第一个元素前面，第二和第三个参数是要插入的其他vector的元素区域，同样也是[)
// (7) assgin 分配，赋值，相当于将原本的所有东西回收，重新初始化
assign(size,value); // 重新分配大小以及给所有元素的初始值value
assign(pd.begin()+2,pd.end()); // 还可以用迭代器初始化
assign({1.01,1.02,1.03}); // initiallizer_list成员函数

// (8) rbegin和rend,他们返回一个逆向函数迭代器，其他的都没变，*rbegin是最后一个元素，加一就是倒数第二个，*(rend-1)是第一个
cout<<*pd.rbegin(); // 1.03
cout<<*(pd.rend()-1); // 1.01

// (9) 获取常量迭代器
const vector<double> cpd; pd.begin(); pd.cbegin() // 常量vector直接调用begin就能返回常量迭代器
pd.cbegin(); // 普通的vector对象要调用cbegin

// (10) size 获取已存在的元素个数
pd.size();

// (11) max_size 获取当前系统与编译器下，vector可以存储的最大元素个数

// (12) resize 重新调整vector大小,注意，当resizr做缩减时只是挪动迭代器，用size()查看元素个数确实是减少了，但是其值还在，依然可以pd[6];用capacity获取的才是其真实容量
pd.resize(5); // 如果原本的元素个数小于5，则扩充，扩充出来的元素将默认是0,如果原本的数量大于5，则缩减，从最后一个开始删除，直至个数等于5
pd.resize(5,1.08); // 第二个参数就是赋予扩充出来的元素的默认值

// (13) shrink_to_fit 缩减到合适大小,这只是常识性操作，可以会无效
pd.shrink_to_fit();

// (14) capacity 获取vector真实容量
pd.capacity();

// (15) empty 判断该容器里的元素个数是否为空，不是判断容量的，与容量无关
pd.empty(); // flase或者true

// (16) resever 在已经确定所需元素数量时可以提前预设好容量，避免来回的扩充导致的效率低下
pd.resever(6); // 如果pd原来的容量大于6，则不受影响，如果小于6则容量扩充为6

// (17) at 访问vector内的元素，也是使用索引，但是它会提供索引是否越界的检查，可以使用try-catch触发和接收错误，比pd[index]更安全
double db=pd.at(2); // 与pd[2]同效

// (18) fornt和back 获取第一个元素和最后一个元素，就是*begin()和*(end()-1)
cout<<pd.front()<<pd.back();

// (19) data 返回一个指针，有点像数组里的数组名，当vector不为空时，data()=&front()
cout<<pd.data(); // *(pa.data())就是第一个元素值

// (20) push_back 在末尾添加元素
pd.push_back(1.02); 
pd.push_back(1.02+1.08); // 还有对应的移动函数版本，直接调用emplace()

// (21) emplace_back 移动函数，传入构造函数参数构造元素，并添加元素到末尾，支持右值参数，可以避免不必要的拷贝行为
pd.emplace_back(1.02); // 注意！一次只能添加一个元素，与push_back一样.
class base {
  int num;
  string name;
public:
  base(int n, string str) : num(n), name(str) {} // 使用emplace添加自定义类型时，该类型一定要有对应的初始化构造函数
};
vector<base> bas;
bas.emplace_back(5,"jony"); // emplace里的可变参数版本是用来添加自定义类型的,...args是要传递给构造函数的参数

// (22) pop_back() 删除最后一个元素,也是只移动迭代器，其容量不变
pd.pop_back();

// (23) emplace 与emplace_back相似，但是emplace可以在任意位置插入元素,对于vector来说随机位置添加元素是很耗资源的，所以不能频繁使用，要频繁进行这种操作建议用list容器
auto it=pd.emplace(pd.begin(),7); // 会在begin之前插入7这个元素,也是一次只能添加一个,返回的是用户指定的迭代器位置，这里从begin插入，则返回的就是begin

// (24) insert 在任意位置添加元素，这里的参数是直接传元素对象，而不是emplace那种传构造函数参数
pd.insert(pd.begin(),1.09);
pd.insert(pd.begin(),1.09+1.20); // 也有右值引用版本
pd.insert(pd.begin(),{1.07,1.08,1.09}); // initialliaer_list版本
pd.insert(pd.begin(),5,1.09); // 将5个1.09插入到pd中
pd.insert(pd.begin(),pd2.begin(),pd.end()); // 将另一个vector的一定迭代器范围内的元素插入到任意位置

// (25) erase 删除元素,容量还是不变
pd.erase(pd.begin()); // 删除该迭代器下的元素
pd.erase(pd.begin(),pd.end()); // 删除迭代器范围内的元素

// (26) swap 两个vector之间交换元素
pd.swap(pd2);

// (27) clear 清楚全部元素，同样，容量还在
pd.clear();
```

// vector的构造函数
```cpp
// 模版参数
vector<typename,allocator=...> // 必传一个typename,可选传一个自定义的内存分配器
// 空参
vector<double> pd;

// 一元，无符号整型,指定vector大小
vector<double> pd(8);
// 一元，复制构造函数，将会把pd的值覆盖到pd2上（因为vector就是用new分配内存的，所以要显示定义复制构造函数）
vector<double> pd2(pd); // 联合了移动构造函数，支持右值引用
// 一元，initializer_list<typename>模版作为参数的构造函数。
vector<double> pd{1.02,1.04,1.07}; // 一定要用{}才能调用到initializer_list构造函数,

// 二元，无符号整型、传入typename类型(所有元素的统一初始值)
vector<double pd(8,1.09); // pd[0]=pd[1]......=1.09
// 二元，输入型迭代器,讲区域内元素拷贝过来
vector<double> pd{1.01, 1.02, 1.03};
vector<double> pd2(pd.begin() + 1, pd.end());
```