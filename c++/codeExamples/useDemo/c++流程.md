## c++流程，也可以说是大多数语言从我们编写的源代码到打包好，可以在自己本地计算机运行的程序之间的步骤流程
### 编译预处理
在预编译过程中主要处理源代码中的预处理指令，比如引入头文件（#include），去除注释，处理所有的条件编译指令（#ifdef, #ifndef, #else, #elif, #endif），宏的替换（#define），添加行号，保留所有的编译器指令；
### 编译
针对预处理后的文件进行词法分析、语法分析、语义分析、符号汇总、生成汇编代码，并针对程序的结构或者特定的 
CPU 平台进行优化，其中涉及的过程较为复杂。简单来说编译的过程即为将 .cpp 源文件翻译成 .s 的汇编代码；

### 汇编
将汇编代码 .s 翻译成机器指令 .o 文件，一个 .cpp 文件只会生成一个 .o 文件；

### 链接
汇编程序生成的目标文件即为 .o 文件，单独的 .o 文件可能无法执行。因为一个程序可能由多个源文件组成，此时就存在多个 .o 文件。文件 A 中的函数引用了另一个文件 B 中定义的符号或者调用了某个库文件中的函数，这就需要链接处理。那链接的目的就是将这些文件对应的目标文件连接成一个整体，从而生成一个可被操作系统加载执行的程序文件