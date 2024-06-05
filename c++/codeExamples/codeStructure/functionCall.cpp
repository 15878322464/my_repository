#include "head.h"
using namespace std;
// 所谓的跨文件调用是指cpp文件之间的调用，没有include导入关系，
// include导入就相当于复制被导入的内容到本文件，那么他们都是属于同一个文件域的

// 全局变量：
//  int externVar; static int externVar;
//  两个文件不能同时声明或者定义同一个外部全局变量，加上一个static变为内部静态变量才行
extern const int externVar2; // 全局常量
extern int externVar;        // 使用外部全局变量
void printt() {
  int externVar = 20;
  cout << externVar
       << endl; // 20,函数内部的自变量与全局变量不冲突，但是会覆盖掉全局变量
  cout << ::externVar << endl; // 使用作用域解析解析运算符来访问全局变量
}

// 全局函数
extern void globalFunc(); // 只做了解，一般是引用文件实现此功能

// 命名空间的跨文件调用
namespace np {
extern int nameSp;
extern void nameFunc();
} // namespace np

int main() {
  printt();
  globalFunc();
}