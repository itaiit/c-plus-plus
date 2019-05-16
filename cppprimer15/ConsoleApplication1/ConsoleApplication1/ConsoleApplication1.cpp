#include "pch.h"
#include <iostream>

class MyClass
{
public:
	MyClass();
	~MyClass();

private:
	static int i;
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int main()
{
    std::cout << "Hello World!\n";
}