// 函数指针,用来接收和传递函数对象。它是实际函数的地址，与std::function不同，std::function是一个类，可以容纳任何类型的可调用对象。
```cpp
// definition:
returnType (*funcName)(parameterType);
returnType (A::*funcName)(parameterType);

// declare and assign:
int (*func_ptr)(int, int) = nullptr;

int add(int a,int b){return a+b}
func_ptr=add; // func_ptr=&add;

// call:
(*func_ptr)(2,3); // 也可以直接func_ptr，但是这不利于代码阅读。
```
(1)参数列表和返回类型必须严格匹配。
(2)函数不能嵌套定义

// 1. 函数指针作为函数参数
```cpp
void call(void (*func_ptr)(int)){
    （*func_ptr)(1);
}
void prt(int i){cout<<"num is :"<<i<<endl;}

int main(){
    call(prt); // num is 1
}
```