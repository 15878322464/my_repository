// 用于输出显示到控制台,要注意的是其默认是只输出到6位数的浮点数，要想显示其他多位数要设置对应输出格式。
// call:
std::cout<<"要输出的内容/变量/表达式......"

// 设置cout的输出精度:
#include<iomanip>
std::cout<<fixed<<setprecision(位数);

// cout.setf() 设置浮点数输出格式

// cout.unsetf() 取消所有格式标志，恢复默认格式