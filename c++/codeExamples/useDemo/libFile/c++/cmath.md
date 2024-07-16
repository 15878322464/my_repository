// 数学函数，数学运算库

// 1. 在计算机中，现实中的角度多用弧度表示，所以在使用角度相关函数时要记得转化为弧度
```cpp
double radToDeg = 57.29577951; // 180/pai
double angle = 45.3 // 45.3度
double radian = angle/radToDeg;
angle = radian*radToDeg;
```

// 2. sqrt() 开根号
```cpp
sqqrt();
```

// 3. atan2 反正切函数,根据直角坐标系x,y转化为极坐标的角度。还有一个atan()函数，但是其不能区分180度之内和之外的角度，所以并不受欢迎，很少使用。
```cpp
double x,y;
double radian;
radian = atan2(y,x); // 当然，这里求出来的单位也是弧度，一般要显示出来，与人交互时才转换为角度
```

// 4. 