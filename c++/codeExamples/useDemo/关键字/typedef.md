// type define的缩写，类型重新定义，为现有类型取别名。也可以用define取别名,但是一般只将define用于字符常量与文本替换。
```cpp
typedef existing_type new_type_name;
typedef 类型 该类型别名;
typedef int in; // 这样你这个文件里的in就可以统一管理,例如统一个更换类型，这种功效与模版类似，但是模版更方便功能也更多
```

// typedef 为函数指针定义别名
```cpp
const double *(*fPtr)(int); //这样就只是声明一个函数指针
fPtr = ......;
typedef const double *(*funcPtr)(int); // 加上typedef就是给后面这一串取了一个简洁名,重新定义了一个类型；
funcPtr p1 = ......;
funcPtr p2 = ......;
```
