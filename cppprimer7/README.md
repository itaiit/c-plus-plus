# c++中的类

## 类的定义使用class/struct

使用class或者struct定义类的区别仅仅在于二者的默认访问权限不同：

- class：默认的成员的访问权限是private；

- struct：默认的成员访问权限是public；

> 使用这两个方式定义类的时候，还与默认的派生级别息息相关。
>
> - 使用class定义的派生类默认是私有继承于父类的；
> - 使用struct定义的派生类默认是公有继承于父类的；

定义类还有许多不为人知的东西，参考：

https://docs.microsoft.com/en-us/cpp/cpp/class-cpp?view=vs-2019

## 构造函数

先看下面的代码：

```cpp
struct Sales_data
{
	int price;
};

int main()
{
	Sales_data sd;
	std::cout << sd.price << std::endl;
}
```

上面的输出的`sd.price`的值为随机值，而不是0。可见上面的构造函数并未默认初始化该类的数据成员。

我们可以通过*类内初始值*的方式，为数据成员提供默认的初始值：

```cpp
struct Sales_data
{
	int price = 0;
};
```

> TODO：类的构造函数是很复杂的，慢慢再做补充。
>
> 实际上，上面的代码不会自动合成默认构造函数，即使生成了默认的构造函数，也不会默认初始化price。

### 使用初始值列表

初始值列表的初始化顺序，与数据成员的声明顺序相同。

**有些类型的数据成员必须通过列表初始化完成，比例const类型的数据成员，引用类型的数据成员。**

需要理解初始化和赋值的区别：

- 初始化时直接初始化数据成员；
- 赋值是先初始化再赋值；

当构造函数执行完初始值列表后，数据成员的属性已经确定，以const类型的数据成员为例，在执行外初始化列表后，该数据成员的const属性已经确定，因此不能再重新赋值。

```cpp
class InitTest
{
public:
	InitTest(int pno, int &rp) :pno(pno), rp(rp) {
	}
	~InitTest();

private:
	const int pno;
	int &rp;
};
```

## 委托构造函数
``` C++
一、ConstRef::ConstRef(int i, int j) : ConstRef(10, 20, 0)
{
       std::cout << "两个参数的构造函数执行" << std::endl;
}

二、ConstRef::ConstRef(int i, int j, int z)
{
       std::cout << "三个参数的构造函数执行" << std::endl;
}
```
委托构造的执行顺序：
``` C++
 ConstRef ref1(10, 20);

打印：
三个参数的构造函数执行
两个参数的构造函数执行
```
构造函数一委托给了构造函数二，因此当使用构造函数一进行初始化时，将会先执行受委托的构造函数，最后再执行自身的函数体。

## this

this本身就是指向调用该成员函数的那个对象，且this是一个常量指针，即不允许this再指向其他对象。

## const成员函数

成员函数通过名为this的隐式参数表示调用该成员函数的某个对象。

```c++
struct Sales_data
{
	std::string isbn() const { return bookNo; }	// const的作用是修饰隐式this指针的类型，将this变为指向常量对象的指针，因此我们无法通过this修改对象成员的值

	std::string bookNo;
};
```

> 从这一点来看，python的成员函数必须显示的把this作为 成员函数的第一个参数，而c++和java是隐式传入的。

**特别的：**构造函数不能是const的，直到构造函数完成初始化过程，对象才能真正取得其”常量“属性。在const对象的构造过程中可以向其写值。

**考虑一种情况：**有时我们希望修改某个类的数据成员，尽管该函数是const成员函数，则可以这样实现：

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

## 类作用域

假设我们在类中声明了成员函数，而在类外定义它，则需要类作用于运算符：

```cpp
int bookNo;
struct Sales_data
{
    using pos = std:;string;
    
	pos isbn();
    
    std::string bookNo;
}

Sales_data::pos Sales_data::isbn(){
    // 而在此处，我们则可以直接使用bookNo，而无需作用域运算符，这是因为“Sales_data::isbn"已经指明了后面的作用域属于sales_data。
    // 但是对于pos来说，位于类作用域运算符之前，需要明确指定pos的作用域，而pos又是在Sales_data中定义的，因此需要指定。
}
```

> 当我们使用`::bookNo`时，查找的则是最外层作用域的bookNo，即是int类型的bookNo。
>
> 而默认的查找规则是由内向外查找。

## 类中的名字查找

看下面的代码：

```c++
typedef double Money;
string bal;
class Account {
public:
    Money balance() {return bal;}
private:
    Money bal;
}
```

类成员`balance()`声明部分，编译器在查找时只会查找声明之前出现的部分；而成员函数的函数体是在整个类可见后才会被处理，因此，成员函数返回的仍然是`Money bal`而非外面的`string`类型的bal。

## 类内初始值

类内初始值必须使用*=*的初始化形式或者*{}*花括号括起来的直接初始化。

## 未涉及到的部分

友元