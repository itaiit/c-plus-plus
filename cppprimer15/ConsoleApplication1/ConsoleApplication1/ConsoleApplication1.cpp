#include "pch.h"
#include <iostream>
using namespace std;

class BaseClass {
public:
	virtual void func() {

	}
	virtual void func(int i) {
		
	}
	virtual void func(int i, int j) {

	}
	void func(string str) {

	}
private:
	int age;
};

class DeriveClass : public BaseClass {
public:
	using BaseClass::func;

	virtual void func() override {

	}
	virtual void func(int i, int j) override {
		this->age = i; // this指向的对象不能被改变
	}
	int getAge() {
		static int num = 0;
		return age;
	}
private:
	int age;
};

class CopyClass {
public:
	CopyClass() = default;
	CopyClass(CopyClass & cla) = delete;
};

//CopyClass::CopyClass(CopyClass & cla) {
//	cout << "调用拷贝构造函数" << endl;
//}

int main()
{
	/*DeriveClass *dc = new DeriveClass;
	dc->func();

	CopyClass c1, c2(c1);*/
	// c1 = c2;
	DeriveClass dcl1;
	dcl1.func(100, 300);
	cout << dcl1.getAge() << endl;
	
}