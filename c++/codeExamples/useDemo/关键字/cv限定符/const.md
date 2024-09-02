// 常量，不可修改,他都链接性是内部的，只在本文件使用，所以放在头文件也不会冲突

// 1. 不能将const修饰的变量赋给不是const的变量，const只能const接收
```cpp
//
const int i;
int* pt=&i; // 错误
char int*="hello"; // 错误，""是字符串常量
```

// 2. 指针只有一层间接关系时才可以将非常量地址赋值给const指针，否则也有const被修改的风险。例如二维数组就不能用const修饰。
```cpp
const int **ptr;
int *i;
const int n=2;
ptr = &i // 
*ptr=&n; // 等同于i=&n;利用双层指针ptr做媒介，将const地址给了非const对象，出现了漏洞。
*i=10; // 此时可根据i任意更改n。
```

// 3. 尽可能使用const，一是避免错误更改，二是const参数即可以接受const参数，也可以接受非const,而非const就只能接受非coonstt。

// 4. const修饰指针的几种场景
```cpp
// 修饰普通指针，使其指向的值不能改
int const* a; // 与const int* a；等效，*之前都可以相互换位置,表示不能更改指针指向的数值，也就是不能更改*a，但是能更改a,因为const是修饰*a的。不存在const* int a这种写法

// 自身是const的指针,不能改本体，但是能改*a
int * const a;

// const修饰自身是const的指针，使其本体不能改以及指向的数值也不能改。
const int* const a; 
```

// 5. const 在创建时一定要初始化，因为只有在创建时才能赋值，之后都不能改变。

// 6.const修饰成员函数,保护对象状态。
```cpp
class base{
private:
    int i;
public:
base(){}
    int geti() const{
        return i;
        // i=10; 不合法，conmst成员函数不能对成员变量有任何修改
        }
    void printi(){
        cout<<i;
        i=10; // 合法
        }
}

int main(){
const base cba; // 常量对象
ba.geti(); // 合法
// ba.printi();  不合法
base ba; // 普通对象都能调常量或者非常量成员函数
ba.geti(); ba.printi(); // 合法
}
```