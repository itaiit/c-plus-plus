8#include <iostream>
#include <memory>

using namespace std;

class Double
{
public:
	Double(double d = 0) : dValue(d) { cout << "constructor: " << dValue << endl; }
	~Double() { cout << "destructor: " << dValue << endl; }
	void setDouble(double d) { dValue = d; }
private:
	double dValue;
};

int main()
{

	
	return 0;
}

void main6()
{
	// 智能指针auto_ptr使用中的问题,auto_ptr已被弃用
	auto_ptr<int> p1(new int());
	cout << "p1:" << p1.get() << endl;
	auto_ptr<int> p2 = p1;
	cout << "p1:" << p1.get() << endl;
	cout << "p2:" << p2.get() << endl;

	// out:
	// p1:000001A287185F60
	// p1:0000000000000000
	// p2:000001A287185F60
}

void main5()
{
	// 使用make_shared创建shared_ptr
	shared_ptr<string> sptr = make_shared<string>("hi");
	for (auto biter = begin(*sptr), eiter = end(*sptr); biter != eiter; biter++)
	{
		cout << "*" << *biter;
	}

	unique_ptr<string> uptr = make_unique<string>(10, 'h');
}

void main4()
{
	// p和p.get()的返回值相同
	shared_ptr<int> p(new int(100));
	cout << "p:" << p << ", p.get():" << p.get() << endl;
}

void main3()
{
	int *p = new int(100);
	cout << *p << endl;
}

void main2()
{
	// 此时不会执行dou的析构函数，会造成内存泄漏
	// 需要显示的执行delete dou
	Double *dou = new Double(9.0);

	// delete dou;
}

void main1()
{
	// auto_ptr会强制执行class的析构函数
	auto_ptr<Double> ptr(new Double(3.14));
	(*ptr).setDouble(6.28);
}