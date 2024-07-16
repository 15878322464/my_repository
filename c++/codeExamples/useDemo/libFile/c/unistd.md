// unix #include <unistd.h>头文件通常在类Unix系统（如Linux，macOS）上可用。在Windows上也有对应的windows.h替代品

1.sleep
```cpp
#include <unistd.h>
 sleep(5); // 暂停5秒

// 循环暂停，起到挂起进程的效果
 for (;;)
 {
    sleep(100);
 }
```