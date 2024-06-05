// 一般用于输出打印数据类型
```cpp
typeid(data).name()
```

// 输出的字符代表的含义：
```cpp
bool:                     b

char:                     c
signed char:              a
unsigned char:            h
 
(signed) short (int):     s
unsigned short (int):     t
 
(signed) (int):           i
unsigned (int):           j
 
(signed) long (int):      l
unsigned long (int):      m
 
(signed) long long (int): x
unsigned long long (int): y
 
float:                    f
double:                   d
long double:              e
PNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE表示: string指针类型
NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE表示: string
```