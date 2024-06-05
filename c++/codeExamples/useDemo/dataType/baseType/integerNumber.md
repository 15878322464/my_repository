<div align="center">
<b>c++基本数据类型之——整数类型</b>
</div>

<b><details><summary>📚说明</summary></b>
在c++中，整数类型种类最多，总共15种，其中包括bool、char等等，不同的系统会使用不同的字长模型，所以会导致有些时候sizeof(int)=sizeof(long)官方文档也是说long>=int，详解讲解如下(1-12按照从小到大排列,最后三个的大小取决于他们的实现)：
</details>

## 📑 目录

类型 | 位(字节) | 范围 |
---|---|---|
[bool](#bool)|1|0-1
[char](#char)|1|-128-127或0-255（不同编译器不同，所以不要用它来存数值常量）
[signed char](#schar)|1|-128-127
[unsigned char](#unchar)|1|0-255
[short](#short)|2|-32768-32767
[unsigned short](#unshort)|2|0-65,535
[int](#int)|4|-2147483648-2147483647
[unsigned int](#unint)|4|0-4294967295
[long](#long)|4|-2147483648-2147483647
[unsigned long](#unlong)|8|0-18,446,744,073,709,551,615
[long long](#ll)|8|-9223372036854775808-9223372036854775807
[unsigned long long](#unll)|8|0-18446744073709551615
[wchar_t](#wchar)|2|由于char只能表示256个字符，许多外文字符集所含的字符数目超过256个，所以有了这个宽字符类型。
[char16_t](#char16)|2|-32768-32767
[char32_t](#char32)|4|-2147483648-2147483647

不同数据模型下，各数据类型的位数：

Type\Model | LP32 | IPL32 | LP64 | ILP64 | LLP64 |
---|---|---|---|---|---|
char | 8 |	8 |	8 |	8 |	8
short |	16 | 16	| 16 | 16 | 16
int	| 16 | 32 | 32 | 64 | 32
long | 32 | 32 | 64 | 64 | 32
long long | 64 | 64 | 64 | 64 | 64
pointer | 32 | 32 | 64 | 64 | 64
```cpp
在这张表中，LP32和ILP32是32位平台上的字长模型，LP64，ILP64，LLP64是64位平台上的字长模型。

LP32指long和pointer是32位的，

ILP32指int，long和pointer是32位的，

LP64指long和pointer是64位，

ILP64指int，long，pointer是64位，

LLP64指long long和pointer是64位的。

常见32位环境一般仅涉及"ILP32"数据模型；而64位环境则使用不同的数据模型。现今所有64位的类Unix平台均使用LP64数据模型，而64位Windows使用LLP64数据模型。
```
1.bool
<a id="bool"></a>

2.char
<a id="char"></a>

3.signed char
<a id="schar"></a>

4.unsigned char
<a id="unchar"></a>

5.short
<a id="short"></a>

6.unsigned short
<a id="unshort"></a>

7.int
<a id="int"></a>

8.unsigned int
<a id="unint"></a>

9.long
<a id="long"></a>

10.unsigned long
<a id="unlong"></a>

11.long long
<a id="ll"></a>

12.unsigned long long
<a id="unll"></a>

13.wchar_t
<a id="wchar"></a>
wchar_t  title[]=L"Chief Astrogator";

14.char16_t
<a id="char16"></a>
char16_t name[]=u"Felonia Ripova";

15.char32_t
<a id="char32"></a>
char32_t car[]=U"Humber Super Snipe";

//额外的raw字符串，显示“”中的原文,当需要输出"(符号时，则可以用R"+*(格式,还可以与L、u、U搭配使用。 
16.raw
std::cout<<R"(hello "\n" world!)"; // hello "\n" world!  
std：：cout<<R"+*("(hello,world!)")+*"; // "(hello,world!)"  

