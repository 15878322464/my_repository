# 光源
## 定向光源（Directional Lights） 
> 大光源，是主要的室外光源，是有向的，模拟从无限远的源头处发出的光线。这意味着此光源投射出的阴影均为平行，因此适用于模拟太阳光

他与放置位置无关，调节y轴旋转是上下移动，可调节成不同时间段的光照，调节z轴是左右移动，具体属性如下：
### <b>light</b>
#### Source Angle（光源角度）
·光源对着的角度，以度数为单位。默认为0.5357，这是太阳的角度，数值越大光源越大。  
具体效果是在阴影里表现，是硬直过度阴影还是柔化过度阴影  
当使用距离场阴影时，此参数会决定距离场阴影的边缘软度。  

#### Source Soft Angle（光源软角度）
影响光源的柔化程度

#### User Temperature（使用温度）
黑体光源的色温，以开氏度为单位。白色是6500K。不勾选的话光照颜色就是白色，与“Light Color”有较为相似的效果，但其不能呈现多彩的颜色，以冷暖色调为主。

#### Affects World（影响场景）
意思是是否对该场景产生影响，如果取消勾选，则会造成禁用该光源的效果

#### Cast Shadows（投射阴影）
是否投射阴影

#### Indirect Lighting Intensity（间接光照强度）
缩放光源发出的间接光照贡献。数值越大阴影处越亮

#### Volumetric Scattering Intensity（体积散射强度）
光源在体积雾中的体积光散射强度，数值越大散射越强，远能见度越低。

#### Intensity（强度）
默认太阳强度为110000.0 lux

#### Light Color（光源颜色）
这个不用过多介绍了

#### <b>Advanced</b>
Shadow Cascade Bias Distribution（阴影级联偏差分布）  
动态阴影精度

Cast Modulated Shadows（投射调制阴影）  
专用于移动设备上支持来自定向光源的动态调制的角色阴影，只有在目标是移动平台上才能勾选

Modulated Shadow Color（调制阴影颜色）  

Shadow Amount（阴影量）  

Specular Scale（镜面规模）  
Specular scale 这个是控制高光的，高光往往会带来一个白色的高光点或者高光区域，如果我们改成0的话，就不会有这个点或者区域出现了。
这里要把它去掉的原因是，有些类型的光源，基本上不会产生什么高光点，比如聚光灯这种，所以这种类型的灯光就可以改成0。所以这个选项是根据光源类型来说的。

Shadow Resolution Scale（阴影分辨率缩放）   
改变动态阴影贴图的分辨率。注意：阴影贴图的分辨率仍由 r.Shadow.MaxResolution 限制

Shadow Bias（阴影偏差）  
动态阴影精度

Shadow Slope Bias（阴影倾斜偏差）  
动态阴影精度

Shadow Filter Sharpen（阴影过滤锐化）  
控制动态阴影边缘的锐化程度

Contact Shadow Length（接触阴影长度）  
可以添加阴影细节，同时也会增加噪点

Contact Shadow Length In World Space Units（世界空间单位的接触阴影长度）
是否使用世界空间单位作为接触阴影长度

Cast Translucent Shadows

Cast Shadows from Cinematic Objects Only

Dynamic Indirect Lighting

Force Cached Shadows for Movable Primitives

Lighting Channels

Cast Static Shadows

Cast Dynamic Shadows

Affect Translucent Lighting

Transmission

Cast Volumetric Shadow

Cast Deep Shadow

Cast Ray Traced Shadows

Affect Ray Tracing Reflections

Affect Ray Tracing Global Illumination

Deep Shadow Layer Distribution

### <b>Rendering</b>
Visible  
Actor Hidden In Game  
Editor Billboard Scale  

#### Advanced
Use Attach Parent Bound  

#### Lightmass
Light Source Angle  
Indirect Lighting Saturation  
Shadow Exponent  
Use Area Shadows for Stationary Light  


#### Light Shafts
Light Shaft Occlusion: Occlusion Mask Darkness &nbsp; | &nbsp; Occlusion Depth Range    
Light Shaft Bloom: Bloom Scale &nbsp; | &nbsp; Bloom Threshold &nbsp; | &nbsp; Bloom Max Brightness  
Bloom Tint  
Advanced  

#### Cascaded Shadow Maps
Num Dynamic Shadow Cascades  
Distribution Exponent  
Transition Fraction  
Distance Fadeout Fraction  
Dynamic Shadow Distance MovableLight  
Dynamic Shadow Distance StationaryLight  
Advanced: Inset Shadows For Movable Objects &nbsp; | &nbsp; Far Shadow Cascade Count &nbsp; | &nbsp; Far Shadow Distance  

#### Distance Field Shadows
DistanceField Shadow Distance  
Distance Field Shadows  
Advanced: DistanceField Trace Distance &nbsp; | &nbsp; Ray Start Offset Depth Scale  

#### Ray Tracing
Shadow Source Angle Factor  
Samples Per Pixel  

#### Atmosphrer and Cloud
Atmosphere Sun Light  
Cast Shadows on Clouds  
Cast Shadows on Atmosphere  
Cast Cloud Shadows  
Cloud Scattered Luminance Scale  
Advanced: Atmosphere Sun Light Index  

#### Performance
Max Draw Distance  
Max Distance Fade Range  

#### Light Function
Light Function Material  
Light Function Scale  
Fade Distance  
Disabled Brightness  

#### Tags
Component Tags  

#### Cooking
Is Editor Only  
Advanced: Is Editor Only Actor  

#### HLOD
Include Actor in HLOD  

#### Actor
Can be Damaged  
Initial Life Span  
Spawn Collision Handling Method  
Actor Guid  
1 selected in  
Convert Actor  
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

