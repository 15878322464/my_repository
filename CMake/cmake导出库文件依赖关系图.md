<div align="center">
<b>cmake导出库文件依赖关系图步骤</b>
</div>

<b><details><summary>📚说明</summary></b>
需安装camke(生成.dot)与graphviz(将dot转换问png)
</details>

## 📑 目录

* [1.graphviz安装](#anzhuang)

<a id="anzhuang"></a>
1.graphviz安装
官网下载对应版本安装即可，地址如下：  
https://graphviz.org/download/  
安装完后记得把bin路径添加到系统环境path中去  
运行dot -version检查  

2.转换命令：
dot -Tpng input.dot -o out.png  