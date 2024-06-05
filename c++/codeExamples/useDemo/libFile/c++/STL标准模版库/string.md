// string类，字符串对象,比char数组好用，封装的功能函数也会更多，但是也会牺牲一点点性能。

// 1.length(),获取已存的字符串长度
```cpp
std::string str="123456" // 双引号里面加字符的表达方式，他的本质就是字符数组，c风格的字符串，"123456"相当于该字符数组的第一个元素的指针
std::cout<<str.length() // 5
```

// 2.加法拼接与赋值，这是char数组所没有的。
```cpp
 std::string str1="hello";
 std::string str2="world";
 std::string str3=str1+str2;
 str3+=str2;
```

// 3.可以直接使用==对string类内容进行比较，因为==有string参数的函数重载（比较双方有一个是string对象就行）。
 ```cpp
std::string str1="hello";
std::string str2="world";
bool b=str1==str2
cout<<b; // false
 ```

 // 4. 使用c-风格字符串初始化string
 ```cpp
string str = "hello";

string str2 = "hello";

char chs[]="hello";
string str3 = chs; // string类定义了char*转换为string类的功能。

 ```