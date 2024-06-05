// 结构体
```cpp
// define
struct person  
{  
    std::string name;  
    int age;  
};
```

// 1.结构体数组
```cpp
person student[]=  
{  
    {"xiaoming",16},  
    {"xiaohong",15}  
};
```

// 2.位字段,允许你在一个数据结构中以位为单位控制和分配存储空间,一般用于节省空间、位操作、硬件编程。跨平台开发中谨慎使用，在高级编程我们一般用整型+按位运算符代替.。
```cpp
struct person
{
    unsigned int age : 3;
    unsigned int : 4; // 使用没有名称的字段提供间距
    bool marry : 1;
}
```