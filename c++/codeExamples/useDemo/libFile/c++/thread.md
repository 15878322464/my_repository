// thread线程库

1. this_thread
```cpp
#include <thread>
#include <chrono>

 std::this_thread::sleep_for(std::chrono::seconds(5)); // 暂停5s
```