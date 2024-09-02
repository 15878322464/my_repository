// 允许修改，解除const限定
```cpp
struct test {
  int t;
  mutable int i;
};

int main(){
    const test te={1,2};
    // te.t=30; // 无效
    te.i=10; // 有效
}
```