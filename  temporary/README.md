## Struct嵌套Enum(无作用域枚举)

struct中的enum，认为是一种新的数据类型，如下：

```cpp
struct OuterStruct
{
	const static int i = 100;

    enum InnerEnum
	{
		APPLE,
		ORIANGE,
		BANANA,
		PICH,
	};
}
```

OuterStruct中拥有4个类型为InnerEnum的常量成员：`APPLE`，`ORIANGE`等。

> 个人理解：
>
> 上面的Enum定义等价于：
>
> ```cpp
> struct OuterStruct
> {
>     --------------
> 	【InnerEnum类型定义部分】，InnerEnum定义为内部类型
>     --------------
>     const static InnerEnum APPLE;
>     const static InnerEnum ORIANGE;
>     const static InnerEnum BANANA;
>     const static InnerEnum PICH;
>     ...
> }
> ```

InnerEnum只在OuterStruct内部有效，类似于内部类的概念，因此在类外部使用该类型需要使用类限定符：`OuterStruct::InnerEnum`。

```cpp
OuterStruct::InnerEnum ie = OuterStruct::APPLE
```

此时枚举值APPLE的作用域与InnerEnum作用域相同，因此不需要再使用InnerEnum进行限定。

此种枚举的局限：

根据上面的解释，因此下面的定义是不允许的：

```cpp
struct OuterStruct
{

	const static int i = 100;

	// 无作用域枚举
	enum InnerEnum
	{
		APPLE,
		ORIANGE,
		BANANA,
		PICH,
	};
	enum InnerEnumTest
	{
		APPLE,
	};
};
```

即，有两个名为`APPLE`的枚举类型。

## 作用域枚举

针对于上面的情况，使用作用域枚举来解决。

```cpp
struct OuterStruct
{

	const static int i = 100;

	// 无作用域枚举
	enum InnerEnum
	{
		APPLE,
		ORIANGE,
		BANANA,
		PICH,
	};
	enum class/struct InnerEnumTest
	{
		APPLE,
	};
};
```

带作用域的枚举就需要使用作用域限定符来使用了：

```cpp
OuterStruct::InnerEnumTest iet = OuterStruct::InnerEnumTest::APPLE;
```

此时枚举值APPLE的作用域包含在InnerEnumTest作用域内，属于是包含关系。