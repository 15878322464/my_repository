// new运算符,用于创建动态内存,与静态内存最大的区别就是静态内存需要
```cpp
int *p1=new int;
int *p2=new int(1); // 适用于初始化标准类型
int *p3=new int[3]{1,2,3}; // 列表初始化，适用于初始化结构体和数组
delete p1,p2;
delete [] p3;
```

// 定位new运算符（new开辟内存，并定位到一个开辟好的指定内存地址，而不是新找一个,）
```cpp 
int buffer[20];
  int *p1 = new int;
  int *p2 = new (buffer) int;
  int *p3 = new (buffer + sizeof(int)) int; // 添加偏移量,避免内存重叠
  cout << "&buffer: " << &buffer << endl;   // 0x61fdb0
  cout << "&p1: " << p1 << endl;            // 0x6f1610
  cout << "&p2: " << p2 << endl;            // 0x61fdb0，地址与buffer相同
  cout << "&p3: " << p3 << endl;            // 0x61fdc0
  // delete p2; // 定位new运算符后一定要确保new与delete对应正确，buffer所在内存地址不是在堆上的，不能delete,否则进程卡死
  delete p1;
```

// new失败时
```cpp
try{
    int *p1=new int;
}catch(std::bad_alloc &ex){
    // 处理内存失败的情况
}
```