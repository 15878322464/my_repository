# 函数

(1). 函数的返回值和参数都不能是数组，但是可以是结构体和对象，所以我们想返回多个值，可以将其包装为对象，传参一般也是传数组名，也就是第一个元素的地址，可以用指针接收。

(2). 函数要想调用必须提供原型，或者将函数定义在要调用的代码之前（头文件的引用就是提供了原型）。

(3). 函数原型的标识符可以省略（函数定义与函数指针的声明不能省略！）
(4). 对于给定的函数名总共有三大版本，非模版函数（常规函数）、具体化模版函数和模版函数以及他们各自的重载版本，优先级从左到右。
## main函数
``` cpp
int main(int argc,char* argv[]) // main函数传参时的固定搭配，使用字符指针数组接收参数是为了兼顾c语言，argc是参数个数，注意，argv[0]永远是main程序名路径,例如："D:\\\\e\\\\c++\\test\\test.exe"，所以argc至少为1，多个传参用空格分隔，如果参数内有空格等特殊字符记得用引号引起来
```
1. 函数参数的传递方式
```cpp
// 1. 按值传递（会发生拷贝）
void function(int param,int* params){ // 也可以将int*替换为int params[]
}
int main(){
    int arg=1;
    function(arg);
    int args[];
    function(args);
}
//（1）数组参数也是按值传递，不过，复制的不是数组元素而是数组地址，所以也能修改数组内元素。

// 2. 引用传递(多用于较大的对象)
void function(int & param){
}
int main(){
    int arg=1;
    function(arg);
}

// 3. 按指针传递（本质上还是按值传递，修改函数里面的指针不会影响到函数外指针本身，但是如果用指针里存储的地址去修改对应地址里的值，那函数外的指针存的地址指向的值也会被修改。因为他们按值传递只是复制的地址，这样就有比较大的风险，如果函数内的指针delete了，那函数外的指针就存的是一个空地址，此时再使用函数外的指针会造成错误，我们可以将指针改成指针引用int *& ptr，让函数内外的指针统一）

void function(int* params){
}
int main(){
    int arg=1;
    function(&arg);
    int args[];
    function(args);
}

// 4. 按常量引用传递
void function(const int& param){
}
int main(){
    int arg=1;
    function(arg); // 实参不要求一定也是常量
}
```
使用原则总结：数据对象很小，例如内置数据类型，小型结构，使用值传递；数组只能用指针；较大结构时用指针或者引用；类对象则用引用；


// 2. 有返回值的函数需要注意的事项
```cpp
// 1. 不要返回临时变量的引用以及指针，因为他们会随着函数的结束而销毁，他们的引用与指针也随之销毁，编译也会报错。
int& function(){
    int i=1;
    return i; // or return int *i;
}
```

// 3.函数默认参数
```cpp
void default(int i=1);
void  function(int i,int n=2,int t=3); // 正确，默认参数必须从右向左添加默认值
void  function(int i,int n=1,int t); // 无效，没有默认参数的的必须要传参，但传参是从左到右，不能跳过，所以还是得传三个参数，默认参数失去意义
void  function(int i=1,int n,int t)；// 无效
```
(1)必须从右向左添加默认值，是因为实参对形参的赋值顺序是从左到右，不能有跳过，具体示例看第4点。  
(2)原型声明时写了默认参数，那函数定义时就不用再写了，与无默认参数时的定义一样即可。

// 4.实参对形参的赋值顺序是从左到右的
```cpp
void  function(int i,int n,int t){}
function(1,2,3);
function(1, ,3); // 错误，不能有跳过
```

// 5.函数重载,不同的参数类型干不同的事，只使用一个函数名
```cpp
void printt(double b); // #1
// void printt(double &b2); // #1,类型引用与类型本身视为同一个特征标
// void printt(const double b); // #1,与上面的一样，const与非const都是同一个特征标

// 以下三种可以接受相同的参数，但是确可以是重载,有多者时，将调用最匹配的那一个，这可以使得我们根据参数时左值、const还是右值去定制函数行为
// void printt(double &b);
// void printt(double &&b);
// void printt(const double &b);

// int printt(double b); // 这不是重载，要记住是特征标可以进行函数重载，而不是函数类型，返回值不同不算重载

void printt(float f);   // #2
void printt(char *str); // #3

int main() {
  double b = 1.01;
  float f = 2.02;
  char str[] = "hello";
  printt(b);   // #1
  printt(f);   // #2
  printt(str); // #3
}

void printt(double b) { cout << "#1: " << b << endl; } // #1

void printt(float f) { cout << "#2: " << f << endl; } // #2

void printt(char *str) { cout << "#3: " << str << endl; } // #3
```
(1)当函数有重载时则不会再进行标准类型转换来强制匹配，因为编译器不知道转换适配到哪一个重载上。所以有重载时，只奥类型不匹配就报错。

// 6.内联函数(代码行数小于等于10再使用)，以空间换时间，直接将代码复制过去，省去了代码跳转的时间。
```cpp
// 在函数声明前加inline
inline void function(int);
// 或者在函数的定义前加inline(一般更倾向于这一种，因为内联函数一般体量小，一行就能解决，直接将定义放到前面即可)
inline void fuction(int i){return i;}
```
(1)内联函数不能递归  
(2)使用内联函数必须满足两个特征：函数体量小，调用次数多。  
(3)即使你声明了内联函数，编译器也不一定会执行，他有自己的判断。  
(4)在类中定义的函数会被隐式的视为内联函（因为能直接定义在类声明中，那说明函数体量小）
(5)最好不要内联析构函数，因为它往往有隐含的成员和基类的析构函数被调用，比表面看起来的更长
(6)内联那些包含循环或 switch 语句的函数常常是得不偿失
(7)虚函数和递归函数就不会被正常内联. 通常, 递归函数不应该声明成内联函数
```cpp
class base{
private:
    int i;
public:
    int geti(){return i;}

}
```

// 7.函数模版，将同一种算法应用于不同类型的函数
```cpp
template <typename T, typename T2> // c++98比较旧的版本是使用class关键字，而不是typename,两者等效。
void printt(T a, T2 b，int i) {
  cout << "a: " << a << endl << "b: " << b << endl;
}
int main() {
  int i = 1;
  double b = 1.01;
  printt(i, b); // 隐式实例化，根据传参自行推断(不推荐，明确用模版就老老实实用<>，避免混乱)
  printt<>(i,b); // 指定优先用模版
  printt<int,double>(i,b); // 显式实例化，直接指定，类型不匹配时会发生标准类型自动转换，注意class指定的泛型一定是要传类型名，而不能是变量，它推断不出来，非类型参数可以自动转换
}

// 函数模版的非类型参数（适用于所有模版）
template<class T,int N> void printt(N){} // 只能是整型、枚举、引用、指针（浮点数不行）
int main(){
printt(1);
const int i=1;
printt(i); // 实参必须是常量
}

```

// 8.显式具体化模版，为某一特定类型重写函数模版
```cpp
template <typename T, typename T2> void printt(T a, T2 b) {
  cout << "a: " << a << endl << "b: " << b << endl;
}

template <> void printt(int a, double b) {
  cout << "explicit a: " << a << endl << "explicit b: " << b << endl;
}
```
(1)有模版之后才能进行对应的显式具体化模版定义  
(2)隐式实例化、显式实例化、显式具体化,统称为具体化，不要搞混
(3)显示具体化函数模版>函数模版

// 9.函数模版的重载，实现同一个模版，多种参数，多种算法的应用
```cpp
template <typename T>
void printt(T a);

template <typename T>
void printt(T A, T b);
```

// 10. 编译器选择使用函数的优先级(正常函数>函数模版(包括显示具体化模版)、以及各自的重载版本)
```cpp
// 第一肯定是选择参数类型完全匹配的,只要是完全匹配，那函数就优先于模版,反之模版优先，
  //完全匹配的情况下又有一个最佳匹配
  void printt(int &i); // #1
  void printt(int i); // #2
  int main(){
    int i=1;
    printt(i); // 此时的#1、#2都是完全匹配，但#1是最佳匹配，优先选
  }

// 如果没有完全匹配则模版优先，那么就意味着剩下需要比较的是重载函数里的隐式转换，那么按照隐式转换的优先级：小转大>大转小，无符号>有符号,如果都是大转小，那就是选差距最小的
```

// 11. 函数的链接性

```cpp

```