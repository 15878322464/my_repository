// 常量与volatile(易变量)之间的相互转换，虽然通用的圆括号转换也可以，但是const_cast更安全
```cpp
base ba;
const base *baptr=&ba;
base *b=const_cast<base*>(baptr); // const_cast只接收对象指针或引用，或者成员指针。这里需要注意的是，只是指针的const被解除了，如果是const base ba;那指针指向的值*b还是不能更改的
```