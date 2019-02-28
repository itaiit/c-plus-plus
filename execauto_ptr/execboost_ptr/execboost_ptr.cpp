#include <iostream>
#include <boost/smart_ptr/shared_ptr.hpp>

int main()
{
	boost::shared_ptr<int> pint(new int(200));
	*pint = 200;
	std::cout << *pint << std::endl;
}