// 接收类型名以及结果为对象的表达式,返回一个type_info的对象引用
```cpp
include<typeinfo>
int main(){
typeid(object1)=typeid(object2) // type_info重载了=，可以直接比较
typeid(object).name(); // name方法返回该对象的类型，但是不一定是对象的全名，可能是代称，不同编译器代称有不同
}
```
(1)type虽然可以代替虚函数+dynamic_cast,但是后者具有更强的灵活性，代码也更简洁，所以当在if else中看到typeid时，可以考虑是否用虚函数+dynamic_cast代替