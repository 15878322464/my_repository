// 外部变量声明
```cpp
// 1.cpp
int i=10;
```

```cpp
// 2.cpp
extern int i; // 声明i是使用的外部文件的变量
cout<<i<<endl; // 10
```

// extern "c"的用法
```cpp
// c和c++使用的函数名修正方法不同，所以我们在c++想要c中预编译函数，那就得指明是c语言链接性
extern "C" {
    #include "c_code.c" // 该头文件中的所有函数名都按c的修正方案去找
}
```