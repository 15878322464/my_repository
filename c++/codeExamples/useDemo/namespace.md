// 名称空间,可单独开辟一块作用域,不同文件里的相同作用域，也不能直接调用，需要extern声明。除非放在头文件中
```cpp
// 1.cpp
namespace np{
    int i;
    void printt();
}
```

```cpp
// 2.cpp
namespace np{
   void printt(){cout<<"printtt"<<endl;} // 命名空间是开放的，随时随地都能加入新的东西，相当于在一个文件
}
```

// 1.使用作用域解析运算符访问名称空间中的名称
```cpp
np::i;
```

// 2.using声明和using编译命令
```cpp
using namespace np; /// using编译，代表将所有名称加入该区域
using namespace np2; // 可以使用多个using编译,但是如果里面有相同的名称,在用到时将会造成冲突（不用到不会）,或者直接用解析运算符进行区分,

using np::i; //声明过后表示只将i加入该区域域，之后可直接使用
// using np2::i; // 错误，不允许在同一个作用域同时声明两个相同名称

using np::printt; // 导入函数，注意这里只有名称，所以如果函数有重载，那将导入其所有重载函数。

int main(){
cout<<i<<endl; // 0
int i=10;
cout<<i<<endl; // 10，同样的，局部变量会覆盖全局变量
}
```
(1)一般不建议偷懒，直接像using namespace std;这样，把大量名称加进来，如果是大项目，那很可能造成重名混乱，也不便于代码阅读。使用using的原则是大家熟知的，而且是频繁出现的，只使所需名称可用即可，例如using std::cout、using std::endl、suing std::cin这些
(2)将using namespace std 放在所有函数定义前，则所有函数都可使用，放在某个函数定义里，则只有该函数能使用

// 3.嵌套名称空间
```cpp
namespace np{
    int i;
    namespace np2{
        int i2;
    }
}

int main(){
    using np::np2::i2;
}
```

// 4.给名称空间创建别名
```cpp
namespace myNameSpace{}
namespace map=myNameSpace;
```

// 5.未命名的名称空间（链接性为内部的静态变量的替代品）
```cpp
static int i;
namespace {
    int i; // 不冲突
}
```