#include "head.h"
using namespace std;

// 全局变量示例：
int externVar = 10; // 全局变量
extern const int ezternVar2 =
    10; // 全局常量，一定要加extern，这是与普通全局变量不同的点

// 静态函数，原型和定义都需要static修饰(内部链接性)
static void staticFunc();
static void staticFunc() { cout << "static function" << endl; }

// 全局函数
void globalFunc() { cout << "global function" << endl; }

// 名称空间的跨文件调用
namespace np {
int nameSP;
void nameFunc() { cout << "nameFunc" << endl; }
} // namespace np
