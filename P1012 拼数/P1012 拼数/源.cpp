#include <iostream>
#include <vector>
#include <string>

using namespace::std;

int main()
{
	int n = 0;
	cin >> n;
	vector<string> v(n);
	for (auto i = v.begin(); i < v.end(); ++i)
		cin >> *i;
	 