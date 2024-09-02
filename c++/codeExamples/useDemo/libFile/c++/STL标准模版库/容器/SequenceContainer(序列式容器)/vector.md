### vector 动态数组
> 
<b>优点：</b>  允许随机访问，可在尾部添加元素
<b>缺点：</b>  在中间段或者起始段安插元素费时费力，因为安插时必须移动后面的元素，来保持秩序
<b>适用场景：</b>  
<b>注意事项：</b>

```cpp
#include<vector>
......

vecotr<int> coll;
for(int i=1;i<=6;i++)
{
    coll.push_back(i);
}
```