// 枚举,创建有关联的符号常量集合，默认是从0开始，依次递增,枚举只能相同类型之间相互赋值，不能做其他任何运算。
```cpp
// define  
enum color{  
    red, // 0  
    yellow, // 1  
    green, // 2  
    blue // 3 
};

```

// 1.枚举在取值时只能取枚举内已有的变量，其余一概不合法(c++11扩充了),枚举值可以隐式转换为整数，整数不能转换为枚举。
```cpp
color cr1 = red; // valid  
color cr1 = 0; // invalid  
color cr1 = "red" // invalid  
```

// 匿名枚举（用的较多)
```cpp
enum{  
    red,  
    orange,  
    yellow,  
    green,  
    blue  
}; 
int color=red;
```

// 自定义枚举量的值，最常用的是int,也可用long,甚至
longlong。
```cpp
enum{red=4,orange,yellow=3,blue}; // orang=5,blue=4  
enum{red,orang=4};  // 创建多个值相同的枚举量 
```
 
// c++11对枚举的扩充，使得可以将任何数值赋给枚举变量（即使不是枚举值），但是要在取值范围内。
```cpp
enum color{  
    red = 1  ,
    yellow= 2 ,  
    green = 4,  
    blue = 6  
};
color cr1 = color(3); // 取值范围，找到枚举值中最大值，拿去与2的多少次幂比较，找到2的幂中大于该最大值中的最小值减一，就是能取的最大值了，在没有负数的时候最小值是0，有负数时则和最大值一个求法，加个负号而已。
```

// 搭配typedef将枚举名放在后面(相当于将该匿名enum类型重定义为color)
```cpp
typedef enum{
      red,  
    orange,  
    yellow,  
    green,  
    blue  
}color; // 如果没有typedef直接enum {}name;那会造成语法错误
```

// 枚举类
```cpp
enum class name{ // 也可以用struct代替class,但是一般默认用class
    red
}; 
name::red; // c++11引进的，由于枚举是全局的，所以很容易造成名称冲突，使用枚举类,增加了域名空间，即使是在同一个cpp文件，也能取两个相同名称的枚举值。
```