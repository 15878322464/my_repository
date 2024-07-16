// 包含了许多用于函数对象（functors）、函数绑定、函数包装器和一些常见的函数适配器的工具

1.function类模板
```cpp 
std::function<int(int,int)> func;
int add(inta ,int b){return a+b};
func=add; 
// call:
func(2,3);
```

2.bind
```cpp

```