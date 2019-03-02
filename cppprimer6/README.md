> 在实际的场景中，一般都使用vector代替数组。

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

## 函数的参数

考虑下面的情况：

这两种情况的参数都会限制参数中数组的大小

1. 参数为数组的引用

   ```c++
   int func(int (&arr)[2])
   {
       // sizeof(arr)	错误，sizeof的参数必须为一个对象，而引用不是对象
   	return arr[0];
   }
   int main()
   {
   	// 形参为数组的引用，此时也限制了数组参数的个数
   	int arr[] = { 1,2 };
   	cout << func(arr) << endl;
   }
   ```

   获得引用数组的大小，考虑使用模板，以后补充。

2. 参数为数组的指针

   ```c++
   // 参数为数组的指针
   int func(int(*arr)[2])
   {
   	cout << sizeof(*arr) / sizeof(int) << endl;	// 获得数组的size
   	return (*arr)[0];
   }
   
   int main()
   {
   	// 形参为数组的引用，此时也限制了数组参数的个数
   	int arr[] = { 1,2 };
   	cout << func(&arr) << endl;
   }
   ```

## 简单提及

1. 函数的返回值为数组的指针：

   ```c++
   // 返回值为数组的指针
   int (*func1(int(*arr)[2]))[2]
   {
   	return arr;
   }
   ```

2. 函数的返回值为数组的引用：

   ```c++
   int (&func2(int(&arr)[]))[]
   {
   	return arr;hb
   }
   ```

1和2中的形式可以使用c++11中的`尾置返回类型`：

```c++
// 使用尾置返回类型
auto func(int(*arr)[])->int(*)[]
{

}
```

看下面的代码片段(`const_cast与重载`)

```c++
const string &shorterString(const string & str1, const string &str2)
{
	return str1;
}

string &shorterStringNoConst(string &str1, string &str2)
{
	auto &r = shorterString(const_cast<const string&>(str1), const_cast<const string&>(str2));	// 此处的r前面必须要写&，具体原因待补充
	// r = "hello World";
	//return const_cast<string&>(r);
}

int main()
{
	string s1 = "today";
	string s2 = "monday";
	string s3 = shorterStringNoConst(s1, s2);
	cout << s3 << endl;
	return 0;
}
```

## 重载与作用域问题的产生

重载函数声明的不同位置，产生了重载作用域的问题，写在某一个函数内部的重载函数䣌声明，会隐匿掉该函数之外的同名函数：

```c++
void printa(const string &)
{
	cout << "A" << endl;
}
void printa(double)
{
	cout << "B" << endl;
}
void printa(int)
{
	cout << "C" << endl;
}
void fooBar()
{
	void printa(int); // 会隐匿掉其他的重载函数
	printa("");	// 编译报错
    printa(10); // 编译通过
}
```

