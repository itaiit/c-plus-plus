#include "pch.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	/*
		1. map
		2. 使用pair初始化map
		3. pair的public成员first和second
	*/
	map<string, int> mp;
	pair<string, int> pp("pairKey", 100);
	mp.insert(pp);

	cout << mp["pairKey"] << endl;
	
	cout << mp.at("pairKey") << endl;

	cout << "pair.first:" << pp.first << endl;
	cout << "pair.second:" << pp.second << endl;

	map<string, int>::iterator iter = mp.find("pairKey");
	cout << "first:" << iter->first << ", second:" << iter->second << endl;

}