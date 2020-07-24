#include <iostream>
#include <vector>
#include <cmath>

inline int get_bit(int, int);//获得某数字num的第position位

int main()
{
	std::vector<long> a;
	bool b = false;
	for (auto i = 123; i < 333; ++i)
	{
		for (auto i2 = 0; i2 < 3; ++i2)
			for (auto i3 = 0; i3 < 3; ++i3)
				a.push_back(get_bit(i*(i2 + 1), i3+1));
		for (auto i2 = a.begin(); i2 < a.end(); ++i2)
			for (auto i3 = i2 + 1; i3 < a.end(); ++i3)
				if (*i2 == *i3 || *i2 == 0)
				{
					b = true;
					break;
				}
		if (!b)
			std::cout << i << " "<< i * 2 << " "<< i * 3 << std::endl;
		b = false;
		a.clear();
	}
	std::cin >> b;
	return 0;
}

inline int get_bit(int num, int position)
{
	return ((num - num % (int)pow(10.0, position - 1)) % (int)pow(10.0, position)) / (int)pow(10.0, position - 1);
}
/* Remember position can't be 0*/