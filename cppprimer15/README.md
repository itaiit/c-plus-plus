## C++：OOP

c++语言中，基类必须将它的两种成员函数区分开来：

- 基类希望其派生类进行覆盖的函数；
- 派生类直接继承而不需要改变的函数；

> 因此，在设计c++的类时，需要同时考虑某个成员函数是否允许子类覆盖，从而判断是否需要定义为虚函数。

基类定义的虚函数，关键字`virtual`只能出现在类内的函数声明处，而不能用于类外部的函数的定义。

### **虚函数**

父类中的虚函数在派生类中依然是虚函数，在派生类中，对于虚函数而言`virtual`关键字可写可不写。

#### **虚函数的限制**

构造函数和静态函数不能声明为虚函数。

派生类中对于虚函数的重写：

- 参数须与父类中的虚函数完全一致；
- 派生类中重写的函数的返回值可以是基类中虚函数的子类；

### 派生类

#### **派生类的定义**

```c++
class BaseClass {
public:
    virtual void func();
}
class DeriveClass : [访问说明符] BaseClass {
public:
    (1)virtual void func() (2)override;
}
```

在父类BaseClass中声明了虚函数`func`，子类DeriveClass中，对该虚函数进行覆盖：

- (1)派生类中的virtual关键可写可不写；
- (2)C++11中，新增加了`override`关键字，使得虚函数的覆盖更加的明显；

派生访问说明符对于派生类访问其直接基类的成员没有影响，派生类访问其直接基类的成员只与基类中的<u>访问说明符</u>有关；*派生访问说明符所影响的是派生类用户对于派生类中基类成员的访问*。

#### **派生类对于基类中函数的隐藏**

派生类中定义的同名的成员函数(非对基类中虚函数的覆盖)，将会隐藏基类中的虚函数。考虑一种情况：*基类中存在包含虚函数在内的多个同名成员函数，派生类只想覆盖其中几个，同时需要保证派生类对于基类中的其他同名函数可见？*

使用类内的`using`声明：

```cpp
class BaseClass {
public:
	A1_virtual void func() {

	}
	A2_virtual void func(int i) {

	}
	A3_virtual void func(int i, int j) {

	}
	A4_void func(string str) {

	}
};

class DeriveClass : public BaseClass {
public:
	using BaseClass::func;

	B1_virtual void func() override {

	}
	B2_virtual void func(int i, int j) override {

	}
};

int main()
{
	DeriveClass *dc = new DeriveClass;
	(1)dc->func();
}
```

(1)处可以调用派生类中的版本和基类中未被覆盖的版本，即函数B1，A2，B3，A4

#### **默认派生级别**

- 使用class定义的派生类默认是私有继承的；
- 使用struct定义的派生类默认是公有继承的；

#### **禁止继承**

C++11标准提供了防止继承的方法，即：在类名后面添加关键字`final`。

```cpp
class DeriveClass final : public BaseClass {
    
}
```

上述代码说明：DeriveClass类不允许有子类。

**类型转换：**

存在继承关系的类，其子类的引用或指针，可以绑定到子类的对象，因此当已知一个父类的指针或者引用时，并不清楚引用或者指针指向的对象的真是类型：可能是子类对象，也可能是父类对象。因此引申出`静态类型`和`动态类型`。

类型转换：

- 派生类->父类可以隐式完成；
- 父类->派生类的转换则需要使用`dynamic_cast`/`static_cast`；