#include <iostream>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/scoped_ptr.hpp>

int main()
{


	return 0;
}

void main1()
{
	boost::shared_ptr<int> pint(new int(200));
	*pint = 200;
	std::cout << *pint << std::endl;
}