// 请不要把函数定义与全局变量声明放在头文件!这些都是全局的，在所有文件中共享，多次定义或声明会导致重复，无法编译
// 不要在头文件中使用using编译
#ifndef HEAD_H
#define HEAD_H
#include <iostream> // 如果是<>则编译器会从标准库去查找，如果是""，则会先从当前文件去寻找
void printt();      // 函数原型

#define A 90      // #定义的符号常量
const int a = 90; // const定义的符号常量
// extern int i1;    // 外部变量声明
struct headstr // 结构声明
{
  /* data */
};

class head // 类声明
{
private:
  /* data */
public:
  head(/* args */);
  ~head();
};

template <typename T> void printt(T t); // 模版声明

inline void pri(int i) {
  std::cout << i << std::endl;
} // 内联函数，可以有多个定义，但是必须保证每个定义一致。

#endif