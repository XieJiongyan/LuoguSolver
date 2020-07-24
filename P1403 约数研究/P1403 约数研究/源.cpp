#include <iostream>
#include "Primernum.h"

using namespace::std;

int main()
{
	long long x = 0;
	cin >> x;
	primernum.generate(x);
	cout << primernum.countdiv(x) << endl;
	system("pause");
	return 0;
}
