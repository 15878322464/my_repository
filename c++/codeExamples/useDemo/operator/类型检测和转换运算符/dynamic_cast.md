// 动态类型转换测试,在运行时进行类型转换
```cpp
class base{}; // 一定要有虚成员函数
class der1:public base{};
class der2:public der1{};

der1 d1=new der1;
base *ba=dynamic_cast<base *>(d1) // 如果可以转换，则返回base对象地址，若不能，则返回空指针，像继承中，只能派生类转换为基类，所以dynamic_cast<base *>(d1)返回base对象地址，如果是dynamic_cast<der1 *>(base),则返回空指针，使用该运算符转换更安全
```