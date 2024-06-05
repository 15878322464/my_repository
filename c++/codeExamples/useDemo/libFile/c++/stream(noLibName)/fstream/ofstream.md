// 用于文件输入

// call
```cpp
ofstream ofs;
ofs.open("test.txt"); // 文件不存在将会创建，已存在将会删除原有内容，重新输入。
string str;
cin>>str;
ofs<<str;
ofs.close(); // 记得有open就要由close
```