// final 最终的，一般用修饰类，代表该类是最终的类，不能再继承
// 禁止类继承
```cpp
class Base final {
    // ...
};
// Error: Derived cannot inherit from final class Base
class Derived : public Base {
    // ...
};
```
// 禁止虚函数重写覆盖
```cpp
class Base {
public:
    virtual void foo() final {
        // ...
    }
};

class Derived : public Base {
public:
    // Error: cannot override final function Base::foo
    void foo() override {
        // ...
    }
};
```
// 禁止虚继承
```cpp
class Base {
    // ...
};

class Derived final : public virtual Base {
    // ...
};

// Error: cannot inherit from final Derived class
class AnotherDerived : public Derived {
    // ...
};
```