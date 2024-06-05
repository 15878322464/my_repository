// 动态内存管理的库

// 1.智能指针
```cpp
inlude<memory>

// unique_ptr 独占所有权的智能指针，支持数组(使用场景：没有多个指针指向一个对象需求，没有智能指针复制、相互赋值的需求)
unique_ptr<double> pdu(new double);
unique_ptr<double> pdu = make_unique<int>(22); // c++14才有
unique_ptr<double[]> pdu(new double[5]); // 可以使用数组，因为其析构函数有delete[]
unique_ptr<double> pdu2=pdu; // 编译器报错，该智能指针是独享的，不予许进行所有权转让，一旦转让，那原始指针将成为悬挂指针，但是临时右值可以，因为这种值之后没有机会再被访问,例子如下：
unique_ptr<double> pdu3 = unique_ptr<double>(new double); // 像这种临时右值才行，因为没有机会访问这种临时值(当然，这依赖于c++11的移动构造函数和右值引用)

// shared_ptr 共享所有权的智能指针，允许多个 shared_ptr 共享同一个对象的所有权。它使用引用计数来跟踪对象的使用情况，并在引用计数变为零时释放对象，不支持数组
shared_ptr<int> ptr = std::make_shared<int>(42); // c++11就有了，优先使用make_shared初始化，优点在于减少内存分配次数和构造函数调用次数，只用一次即可。而直接new的话，对象内存分配一次，控制块(像引用次数这些变量)内存又要再分配一次，相对应的构造函数也要调用两次。
shared_ptr<double> pds(new double); 

// 弱引用智能指针，用于解决 std::shared_ptr 的循环引用问题。weak_ptr 允许观察一个由 shared_ptr 管理的对象，但不会增加引用计数，示例如下：
class B; // 前向声明
class A {
public:
    std::shared_ptr<B> bPtr;
};
class B {
public:
    std::shared_ptr<A> aPtr;
};
int main() {
    std::shared_ptr<A> a(new A);
    std::shared_ptr<B> b(new B);
    a->bPtr = b; // 此时a中有shared_ptrB,要想释放a就得先释放b，让b的指针引用为0
    b->aPtr = a; // 此时b中有shared_ptrA,要想释放b就得先释放a,让a的指针引用为0，两者造成死循环
    return 0;
}
// 使用weak_ptr解决：
class B; // 前向声明
class A {
public:
    std::weak_ptr<B> bPtr;
};
class B {
public:
    std::weak_ptr<A> aPtr;
};
int main() {
    std::shared_ptr<A> a(new A);
    std::shared_ptr<B> b(new B);
    a->bPtr = b;  // weak_ptr不会增加shared_ptr的引用次数,a到期，引用减为0，可释放
    b->aPtr = a;
    return 0;
}

// auto_ptr 旧版本有使用，c++11已经摒弃
auto_ptr<double> pd(new double);
auto_ptr<double> pd2=pd; // 不会报错，pd指针的所有权会转移到pd2,也就是相当于pd指向的内存会被释放，而且也不会更新pd指针，使其变成了悬挂指针，编译器也不会报错。很容易出错，所以已摒弃，不推荐使用。
// auto_ptr<double> pd(new double); // 错误，auto_ptr也不能使用数组，因为其析构函数没有delete[]

```
(1)智能指针本身就是基于new封装实现的对象，所以其接收的指针一定也应该是new出来的，不然无法delete