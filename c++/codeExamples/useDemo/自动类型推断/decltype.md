// 获取表达式类型
```cpp
char c;
short s;
decltype(c+s) i=c+s;

template <typename T>
auto printt(T t1,T t2) ->decltype(t1+t2) {
    return t1+t2;
} // auto是占位符，因为如果将decltype(t1+t2)放到最前面，那t1,t2还未申明，不在其作用域。
```