// 实用的类、功能函数

// 1. forward 模版，在函数内将参数完美转发到其他函数（例如递归调用），避免不必要的拷贝
```cpp
// 1.将未知类型或者右值引用传递给其他参数
template<typename T>
void printt(T &&t){
    printt2(forbard<T>(t));
}
// 搭配可变参数和递归，可以实现可变参数模版
void printt(){} // args...一直展开一直减少，等args为空时就是调用printt();所以一定要有这个空参函数来终止递归，不然会编译报错，说没有匹配的函数定义。
template<typename T,typename ... Args>
void printt(T&& arg,Args&&... args){
    cout<<arg<<endl;
    printt(foreard<Args>(args)...);
}
```