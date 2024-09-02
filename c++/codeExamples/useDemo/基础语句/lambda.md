// 拉姆达“^”表达式，以更简洁的方式定义匿名函数。可将其传入函数指针。
```cpp
// declare:
// [externalCaptrue](parameter)->returnTypey{funcBody}
// [外部捕获的变量](函数参数)->返回值{函数体}
// declare and assign:
[this](){}
auto anonymousFunction = [](int a, int b) -> int {return a + b;};
// call:
std::cout<<anonymousFunction();
```