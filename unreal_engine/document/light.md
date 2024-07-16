# 光源
## 定向光源（Directional Lights） 
> 大光源，是主要的室外光源，是有向的，模拟从无限远的源头处发出的光线。这意味着此光源投射出的阴影均为平行，因此适用于模拟太阳光

> 他与放置位置无关，调节y轴旋转是上下移动，可调节成不同时间段的光照，调节z轴是左右移动，具体属性如下：
### <b>light（光源）</b>
#### Source Angle（光源角度）
> 光源对着的角度，以度数为单位。默认为0.5357，这是太阳的角度，数值越大光源越大。  
具体效果是在阴影里表现，是硬直过度阴影还是柔化过度阴影  
当使用距离场阴影时，此参数会决定距离场阴影的边缘软度。  

#### Source Soft Angle（光源软角度）
> 影响光源的柔化程度

#### User Temperature（使用温度）
> 黑体光源的色温，以开氏度为单位。白色是6500K。不勾选的话光照颜色就是白色，与“Light Color”有较为相似的效果，但其不能呈现多彩的颜色，以冷暖色调为主。

#### Affects World（影响场景）
> 意思是是否对该场景产生影响，如果取消勾选，则会造成禁用该光源的效果

#### Cast Shadows（投射阴影） 
> 是否投射阴影

#### Indirect Lighting Intensity（间接光照强度）
> 缩放光源发出的间接光照贡献。数值越大阴影处越亮

#### Volumetric Scattering Intensity（体积散射强度）
> 光源在体积雾中的体积光散射强度，数值越大散射越强，远能见度越低。

#### Intensity（强度）
> 默认太阳强度为110000.0 lux

#### Light Color（光源颜色）
> 光源颜色调节

#### <b>Advanced</b>
Shadow Cascade Bias Distribution（阴影级联偏差分布）  
> 动态阴影精度

Cast Modulated Shadows（投射调制阴影）  
> 专用于移动设备上支持来自定向光源的动态调制的角色阴影，只有在目标是移动平台上才能勾选

Modulated Shadow Color（调制阴影颜色）  
> 调制阴影颜色

Shadow Amount（阴影量）  
> 阴影深度

Specular Scale（镜面规模）  
> 这个是控制高光的，高光往往会带来一个白色的高光点或者高光区域，如果我们改成0的话，就不会有这个点或者区域出现了。
这里要把它去掉的原因是，有些类型的光源，基本上不会产生什么高光点，比如聚光灯这种，所以这种类型的灯光就可以改成0。所以这个选项是根据光源类型来说的。

Shadow Resolution Scale（阴影分辨率缩放）   
> 改变动态阴影贴图的分辨率。注意：阴影贴图的分辨率仍由 r.Shadow.MaxResolution 限制

Shadow Bias（阴影偏差）  
> 动态阴影精度

Shadow Slope Bias（阴影倾斜偏差）  
> 动态阴影精度

Shadow Filter Sharpen（阴影过滤锐化）  
> 控制动态阴影边缘的锐化程度

Contact Shadow Length（接触阴影长度）  
> 可以添加阴影细节，同时也会增加噪点

Contact Shadow Length In World Space Units（世界空间单位的接触阴影长度）  
> 是否使用世界空间单位作为接触阴影长度

Cast Translucent Shadows（投射半透明阴影）  
> 是否允许透过半透明Object投射动态阴影

Cast Shadows from Cinematic Objects Only（仅从过场动画对象投射阴影）  
> 光源是否应该仅从标记为bCastCinematicShadows的组件投射阴影。这适合用于设置对准角色的过场动画可移动聚光源，并避免背景的阴影深度开销。
此选项仅适用于动态阴影贴图，而不适用于静态投影或光线追踪的距离场阴影。

Dynamic Indirect Lighting（动态间接光照）  
> 该光源是否应注入 光源传播体积（Light Propagation Volume）

Force Cached Shadows for Movable Primitives（为可移动图元强制缓存阴影）  
是否为可移动图元强制缓存阴影

Lighting Channels（光源影响的通道）  
R  
G  
B  

Cast Static Shadows（投射静态阴影）  
> 投射静态阴影

Cast Dynamic Shadows（投射动态阴影）  
> 是否投射动态阴影

Affect Translucent Lighting（影响半透明光照）
> 光源是否会影响半透明度

Transmission（传播）  
> 是否透过具有次表面散射轮廓的表面传播

Cast Volumetric Shadow（投射体积阴影）  
> 是否对体积雾投影

Cast Deep Shadow（投射深阴影）  
> 是否投射高质量的发束自投影。

Cast Ray Traced Shadows（投射光线追踪的阴影）  
禁用  
使用项目设置  
启用  

Affect Ray Tracing Reflections（影响光线追踪反射）
> 在启用光线追踪的反射时是否影响反射中的对象。 

Affect Ray Tracing Global Illumination（影响光线追踪全局光照）  
> 在启用光线追踪的全局光照时是否影响全局光照。

Deep Shadow Layer Distribution（深阴影层分布）  
> 更改深阴影层分布。值为0时表示线性分布（均匀层分布），为1时表示指数分布。

### <b>Rendering（渲染）</b>
Visible（可见性）  
> 取消勾选即不可见该光源

Actor Hidden In Game（隐藏在游戏中的该Actor）  
> 隐藏在游戏中的该Actor

Editor Billboard Scale（编辑Billboard缩放）  
> 控制该光源本身的大小缩放，Billboard就是我们创建蓝图时那个包裹物体的白色球

#### Advanced（高级选项）
> Use Attach Parent Bound（使用父节点绑定）  
网格体的连接方式

### Lightmass（全局光照）
Light Source Angle（光源角度）  
> 定向光源的自发光表面相对于接收物而延展的角度，影响半影尺寸。

Indirect Lighting Saturation（间接光照饱和度）  
> 数值为0时将完全去除此光照在Lightmass中的饱和度，为1时则保持不变

Shadow Exponent（阴影指数）  
> 控制阴影半影的衰减。

Use Area Shadows for Stationary Light（将区域阴影用于固定光源）  
> 数值为0时将完全去除此光照在Lightmass中的饱和度，为1时则保持不变

### Light Shafts（光束）  
#### Light Shaft Occlusion（光束遮挡）
> 确定此光源是否会对雾气和大气之间的散射形成屏幕空间模糊遮挡。
Occlusion Mask  Darkness（遮挡遮罩暗度）  
> 控制遮挡遮罩的暗度，值为1则无暗度。

Occlusion Depth Range（遮挡深度范围）  
> 和相机之间的距离小于此距离的物体均会对光束构成遮挡。

#### Light Shaft Bloom（光束泛光）  
> 确定是否渲染此光源的光束泛光。

Bloom Scale（泛光缩放）  
> 缩放叠加的泛光颜色。

Bloom Threshold（泛光阈值）  
> 场景颜色必须大于此阈值，方可在光束中形成泛光。

Bloom Max Brightness（泛光最高亮度）  
> 应用曝光之后，此值将约束场景颜色亮度。

Bloom Tint（泛光着色）  
> 对光束发出的泛光效果进行着色时所使用的颜色。

Advanced  

### Cascaded Shadow Maps（级联阴影贴图）
Num Dynamic Shadow Cascades（动态阴影级联数）  
> 为整个场景将视锥体拆分成的级联数。

Distribution Exponent（分布指数）  
> 控制级联是分布在更靠近摄像机（指数较大）还是更远离摄像机（指数较小）的位置。

Transition Fraction（过渡部分）  
> 级联之间消退区域的比例。

Distance Fadeout Fraction（距离淡出部分）  
> 控制动态阴影影响远端淡出区域的大小。

Dynamic Shadow Distance MovableLight（可移动光源动态阴影距离）  
> 可移动光源 级联阴影贴图（Cascaded Shadow Map） 动态阴影将覆盖的距离，从摄像机位置开始测量。

Dynamic Shadow Distance StationaryLight（固定光源动态阴影距离）  
> 固定光源 级联阴影贴图（Cascaded Shadow Map） 动态阴影将覆盖的距离，从摄像机位置开始测量。

#### Advanced
Inset Shadows For Movable Objects（可移动对象的内嵌阴影）  
> （仅限固定光源）是否为可移动组件使用逐对象内嵌阴影，即使启用了级联阴影贴图也同样如此。  
Far Shadow Cascade Count（远距离阴影级联计数）  
> 值为0时表示没有远距离阴影级联。  
Far Shadow Distance（远距离阴影距离）  
> 远距离阴影级联应结束的距离。

### Distance Field Shadows（距离场阴影）
DistanceField Shadow Distance（）  
> 
Distance Field Shadows（）  
> 
Advanced: DistanceField Trace Distance（）  
> 
Ray Start Offset Depth Scale（）  
> 

#### Ray Tracing（）
Shadow Source Angle Factor（）  
> 
Samples Per Pixel（）  
> 

### Atmosphrer and Cloud（大气和云层）
Atmosphere Sun Light（大气日光）  
> 定向光源是否能够与大气及云层相互作用并生成视觉上的日轮——这些共同组成了视觉上的天空。  
Cast Shadows on Clouds（在云层上投射阴影）  
> 光源是否应该将不透明对象的阴影投射在云层上。如果场景中存在第二个定向光源（比如太阳或月亮），并且启用了 大气日光（Atmosphere Sun Light） 以及将 大气日常索引（Atmosphere Sun Light Index） 设置为 1，则该选项会被禁用。  
Cast Shadows on Atmosphere（在大气上投射阴影）  
> 使用SkyAtmosphere时，光源是否应该将不透明网格体的阴影投射到大气中。  
Cast Cloud Shadows（投射云层阴影）  
> 是否应该将云层的阴影投射到大气和其他场景元素上。
Cloud Scattered Luminance Scale（云层散射亮度比例）  
> 调整光线散射在云测参与介质（cloud participating media）中的光线贡献。有助于修正我们当前多重散射方案只是一种近似效果的问题。  
#### Advanced
Atmosphere Sun Light Index（大气日光索引）  
> 引擎支持在任何时候显示两个大气光源来表示太阳和月亮，或者是两个太阳。使用此索引来设置主光源和副光源。例如，太阳是0，月亮是1。  
Atmosphere Sun Disk Color Scale（大气日轮色标）  
> 日轮亮度相乘的色标  
Per Pixel Atmosphere Transmittance（逐像素大气透射）  
> 是否在不透明网格体上应用逐像素大气透射，而非使用全局透射。  
Cloud Shadow Strength（云层阴影强度）  
> 阴影的强度。数值越高，光线阻挡越多。  
Cloud Shadow on Atmosphere Strength（云层在大气上的阴影强度）
> 大气上阴影的强度。设置为0时，会禁用大气上的阴影。  
Cloud Shadow on Surface Strength（云层在表面上的阴影强度）  
> 阴影在不透明和半透明表面上的强度。设置为0时，会禁用阴影在不透明和半透明表面上的强度。  
Cloud Shadow Depth Bias（云层阴影深度偏移）  
> 控制应用于体积云阴影贴图的前阴影深度的偏差。  
Cloud Shadow Extent（云层阴影范围）  
> 摄像机周围云层阴影贴图的世界空间半径。单位为千米（km）。  
Cloud Shadow Map Resolution Scale（云层阴影贴图分辨率比例）  
> 调整云层阴影贴图的分辨率。该分辨率受 r.VolumetricCloud.ShadowMap.MaxResolution 的限制。  
Cloud Shadow Ray Sample Count Scale（云层阴影射线取样数比例）  
> 调整用于阴影贴图追踪的取样数。该参数受到 r.VolumetricCloud.ShadowMap.RaySampleMaxCount 的限制。  

### Performance（）
Max Draw Distance（）  
> 
Max Distance Fade Range（）  
> 

### Light Function（）
Light Function Material（）  
> 
Light Function Scale（）  
> 
Fade Distance（）  
> 
Disabled Brightness（）  
> 

### Tags（）
Component Tags（）  
> 

### Cooking（）
Is Editor Only（）  
> 
Advanced: Is Editor Only Actor（）  
> 

### HLOD（）
Include Actor in HLOD（）  
> 

### Actor（）
Can be Damaged（）  
> 
Initial Life Span（）  
> 
Spawn Collision Handling Method（）  
> 
Actor Guid（）  
> 
1 selected in（）  
> 
Convert Actor（）  
> 
Advanced: Find Camera Component when View Target &nbsp; | &nbsp; Ignores Origin Shifting &nbsp; | &nbsp; Can be in Cluster

#### 

#### 

#### 



## 天空光照（Sky Light） 
> 大光源，捕捉场景的背景并将其应用于关卡的几何体。

## 点光源（Point Lights） 
> 小光源，就像一个灯泡，从一个点向各个方向发出光亮。

## 聚光源（Spot Lights） 
> 小光源，从单个点沿着由一组椎体限制的方向发射光。

## 矩形光源（Rect Lights） 
> 小光源，从矩形表面沿一个方向发光。

## 光源的移动性
> 光源的移动性可以设置，分别为静态、固定、可移动，不同的移动性的效果不同，开销也不同。
### 静态光源（static）
将移动性（Mobility）设置为 静态（Static） 的光源是在运行时无法改变或移动的光源。它们在执行光照构建时使用Lightmass进行预计算。静态光源会将数据存储在称为光照贴图的纹理中，这些纹理应用于关卡中的几何体。光照构建完成后，这些光源不会对性能产生进一步影响。

### 固定光源（stationary）


### 可移动光源（movable）

