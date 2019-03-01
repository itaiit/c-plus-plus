## 静态对象

静态对象/局部静态对象的作用域与声明位置无关，程序第一次执行经过时执行初始化，一直到程序结束销毁：

```c++
static size_t ctr = 0
```

局部静态对象若没有显示的初始值，则会执行值初始化。

## 列表初始化返回值

c++11允许下面的返回形式：

```c++
vector<string> process()
{
    // str是一个string对象
    ...
    return {"hello", "world", str};
}
```

