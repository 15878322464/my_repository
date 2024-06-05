// c中用来获取时间的库


1.时钟周期是计算机系统中的最小的一个时间单位，表示处理器执行一次时钟信号的时间.是计算机最小的时间单位。频率的单位是赫兹（Hz）,也表示每秒所发生的时钟周期数。现代计算机大多都是以GHz(千兆赫兹，10^9)，2.4GHz就是每秒钟发生24亿次振荡。


// 2.clock()函数，他输出的是时钟周期数。
```cpp
double start,end,cost;
int i=0;
start=clock();;
while(i<10000000){
    i++;
}
end=clock();
cost = (end-start)/CLOCKS_PER_SEC; // CLOCKS_PER_SEC代表该计算机一秒的时钟周期数,clock()获得的周期数与其相除，即可得秒数
cout<<cost;
```
