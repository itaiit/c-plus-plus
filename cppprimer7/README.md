# c++：class

## 引入this与定义const的成员函数

成员函数通过名为this的隐式参数表5示的是调用该成员函数的那个对象。

```c++
struct Sales_data
{
	std::string isbn() const { return bookNo; }	// const的作用是修饰隐式this指针的类型，将this变为指向常量对象的指针，因此我们无法通过this修改对象成员的值

	std::string bookNo;
};
```

> 从这一点来看，python的成员函数必须显示的把this作为成员函数的第一个参数

构造函数不能是const的，直到构造函数完成初始化过程，对象才能真正取得其”常量“属性。在const对象的构造过程中可以向其写值。

特殊的：有时我们希望修改某个类的数据成员，尽管该函数是const的成员函数，则可以这样实现：

*在变量的声明中加入`mutable`关键字*

```c++
struct Sales_data
{
	std::string isbn() const 
	{
		bookNo += "hello";	// 尽管是const成员函数，仍可以修改对象的成员的值
		return bookNo;
	}

	mutable std::string bookNo;
};
```

## 定义类型成员

```cpp
typedef std::string pos；	// 使用typedef

using pos = std::string;	// 使用类型别名
```

上面的两种方式都可以定义在类中，并且也可以用访问控制符修饰。

## 类内初始值

类内初始值必须使用*=*的初始化形式或者*{}*花括号括起来的直接初始化。