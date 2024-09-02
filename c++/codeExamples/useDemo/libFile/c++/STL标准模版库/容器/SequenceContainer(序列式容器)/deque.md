### deque 队列
> double-ended queue 两端数组的缩写
<b>优点：</b>  往两端安插元素十分迅速
<b>缺点：</b>  在中间插元素困难，要移动其他元素
<b>适用场景：</b>  
<b>注意事项：</b>

```cpp
#include<deque>
......
deque<float> coll;
for(int i=5;i<=6;i++>){
coll.push_front(i*1.1); // 往前端追加元素
}
```