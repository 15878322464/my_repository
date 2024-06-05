// 读取文件，与cin和out使用方式一致

// call
```cpp
ifstream ifs;
ifs.open(./test.txt)
if(!ifs.is_open()){ // 检测文件是否打开成功
    cout<<"open file failure!";
    exit(EXIT_FAILURE);
}
char ch[50]
ifs.getline(ch,50);
cout<<ch;
ifs.close();
```