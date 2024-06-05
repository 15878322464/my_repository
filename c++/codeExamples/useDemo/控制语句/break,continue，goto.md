// break、continue和goto通常都用于控制循环的，后者基本不用，前两者略有不同

// 1.break是直接跳出循环

// 2. continue用于循环中，跳过循环体内的剩余语句，直接开始下一次循环

// 3.goto语句，只做展示，不推荐在任何时候使用
```cpp
int x;
int y;
goto paris; // 直接跳到标签处
cout<<x<<endl;
paris : cout<<y<<endl;
```