# 光源的移动性
> 光源的移动性可以设置，分别为静态、固定、可移动，不同的移动性的效果不同，开销也不同。
## 静态光源（static）
> 将移动性（Mobility）设置为 静态（Static） 的光源是在运行时无法改变或移动的光源。它们在执行光照构建时使用Lightmass进行预计算。静态光源会将数据存储在称为光照贴图的纹理中，这些纹理应用于关卡中的几何体。光照构建完成后，这些光源不会对性能产生进一步影响。

## 固定光源（stationary）


## 可移动光源（movable）