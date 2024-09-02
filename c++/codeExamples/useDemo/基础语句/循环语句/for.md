// for循环,在确定知道循环多少次的情况下用for循环
// define
```cpp
for(int i=num;i<=max;i++) // i<=max叫做测试表达式，他并不限制只能为真或假，可以使用任意表达式，c++会自动强制转换为bool，值为0则转为false,为1则转为true。
    cout<<"......";
// 多条语句使用花括号
for(int i=num;i<=max;i++){
    cout<<"......";
    cout<<"......";
}
```

// 1.花括号内代表是新的代码块，该代码块内声明的普通变量作用域就是该花括号范围，如果外部和代码块内部声明相同的变量，则优先使用内部变量，不会影响代码块外部变量。
```cpp
int y=10;
for(int x=9;x<10;x++)
{
    cout<<y<<endl; // 10
    y=y+1; // 使用的是外部y
    int y=11;
    cout<<y<<endl; // 使用内部y
    int y=y+3;
    cout<<<y<<endl; // 14
}
cout<<y; // 11
```

// 2.逗号运算符还能将多个表达式合并为一个，将其运用在for循环中
```cpp
int x,y;
for(x=0,y=10;x<y<10;x++,y--)
{
    cout<<x<<endl<<y;
}
```
// 3.for循环的测试语句可以留空省略,默认为true。但一般不用，想要条件式停止的无限循环可以用while。
```cpp
for(;;){
    cout<<1;
}
```

// 基于范围的for循环(range-based for)
```cpp
int arr[5]={1,2,3,4,5}
for(int x : arr){ // x是深拷贝，独立副本，要修改arr元素需要用&x，还可直接（int x ： {1,2,3,4,5}），用作初始化列表。
    cout<<x; // 1-5
}
```