// 共用体,允许在同一内存位置存储不同的数据类型。与结构体不同，共用体中的各个成员共享相同的内存空间，因此共用体的大小等于其最大成员的大小，当赋值第二个成员时，第一个被赋值就会被覆盖，多数用于节省内存。
```cpp
// define  
union myUnion  
{  
    int intValue;  
    bool boolValue;  
};

  myUnion u;
  u.intValue = 2;
  std::cout << u.intValue << endl; // 2
  u.boolValue = true;
  std::cout << u.intValue << endl;  // 1
  std::cout << u.boolValue << endl; // 1
```

// 1.在结构体或者类中使用共用体
```cpp
struct person
{
    int age;
    union id{
        int intID;
        char charID;
    }idValue;
    int type;
}
// ......
if(person.type=1){
std::cout<<person.idValue.intID;
}
```

// 2.也可以直接使用匿名共用体，这样相当于共用体的成员直接变为结构体的成员。
```cpp
struct person
{
    int age;
    union {
        int intID;
        char charID;
    };
    int type;
}
// ......
if(person.type=1){
std::cout<<person.intID;
}
```