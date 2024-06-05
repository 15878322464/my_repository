// 用于从大型列中进行选择，选项大于等于3个，用switch,否则用if_else

// define
```cpp
switch(label)
{
    case label1 : statement();
                    // ......
                    break;
    case label2 : statement();
                    // ......
                    break;
    default : statement(); // 可省略

}
```
（1）break;不能省略，如果没有break跳出，则会继续执行下面的case。当然也可以将多个case合并起来，一起运行完再break;
（2）label必须是整数类型，包括char，label1,2必须是常量。

// 1. 最合适的搭配，枚举作为标签
```cpp
enum {red,orange,yellow,green,blue};
int main(){
    int color;
    cin>>color;
    switch(color)
    {
        case red : cout<<red;break;
        case orange : cout<<orange;break;
        default : cout<<"default";break;            
    }
}
```