#include "pch.h"
#include <iostream>

using namespace std;

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
	enum class InnerEnumTest
	{
		APPLE,
	};
};

/*
	enum分为有作用域枚举和无作用域枚举


	enum更显得是一种新的数据类型，拿上面为例，
	enum里面的值也都是"InnerEnum类型"，理解为一次性声明了4个struct的类型为InnerEnum的属性成员，并且都具有默认值

	未指明enum中元素的类型时，则默认是int类型

*/
class EClass
{
public:
	// 有作用域枚举
	enum struct ClaEnum {
		ONE,
		TWO,
		THREE,
		FOUR,
	};
};


int main()
{
	OuterStruct::InnerEnum ie = OuterStruct::InnerEnum::APPLE;

	OuterStruct os;

	int p = os.i;
	int pp = OuterStruct::i;

	cout << ie << endl;

	OuterStruct::InnerEnumTest iet = OuterStruct::InnerEnumTest::APPLE;
}