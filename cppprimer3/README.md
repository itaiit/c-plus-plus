## C风格字符串和string标准库
很多c++程序在标准库出现之前就已经写成了，因此肯定没有用到string和vector类型，因此c++为了与
旧代码进行衔接，专门提供了一组功能：混用string和c风格的字符串。

在以string作为参数的方法中可以传入c风格的字符串，反之则不可以将string传给以c风格字符串作为参数的方法。

作为补充，c++提供了将string转换为c风格字符串的方法：`c_str()`，返回的则是一个指向数组的指针，因此考虑如下的代码：

```c++
string s = "hello";
const char *pch = s.c_str();
s = "world";

此时pch则是指向字符串“world”的指针
若想一直使用执行完c_str()返回的数组，最好执行拷贝
```

## 数组

函数内部内置类型的数组的初始值不确定；

数组之间不能直接赋值；

部分总结：https://blog.csdn.net/I_itaiit/article/details/84799164

