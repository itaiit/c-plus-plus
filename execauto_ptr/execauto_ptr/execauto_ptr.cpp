#include <iostream>
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