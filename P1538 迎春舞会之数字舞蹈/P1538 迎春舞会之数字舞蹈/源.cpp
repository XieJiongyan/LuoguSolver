#include <iostream>
#include <string>

using namespace::std;

int main()
{
	int n = 0;
	cin >> n;
	string s;
	cin >> s;
	for (auto i = s.begin(); i < s.end(); ++i)
	{
		switch (*i)
		{
		case '0': case '2': case '5': case '6': case '8': case '9': case '3': case '7':
			cout << ' ';
			for (auto i = 0; i < n; ++i)
				cout << '-';
			cout << ' ';
			break;
		case '4': case '1':
			for (auto i = 0; i < n + 2; ++i)
				cout << " ";
			break;
		}
		cout << ' ';
	}
	cout << endl;
	for (auto i = 0; i < n; i++)
	{
		for (auto i = s.begin(); i < s.end(); ++i)
		{
			switch (*i)
			{
			case '0': case '4': case '8': case '9':
				cout << '|';
				for (auto i = 0; i < n; ++i)
					cout << ' ';
				cout << '|';
				break;
			case '2': case '3': case '1': case '7':
				for (auto i = 0; i < n + 1; ++i)
					cout << ' ';
				cout << '|';
				break;
			case '5': case '6':
				cout << '|';
				for (auto i = 0; i < n + 1; ++i)
					cout << ' ';
				break;
			}
			cout << ' ';
		}
		cout << endl;
	}
	for (auto i = s.begin(); i < s.end(); ++i)
	{
		switch (*i)
		{
		case '0': case '1': case '7':
			for (auto i = 0; i < n + 2; ++i)
				cout << ' ';
			break;
		case '2': case '3': case '4': case '5': case '6': case '8': case '9':
			cout << ' ';
			for (auto i = 0; i < n; ++i)
				cout << '-';
			cout << ' ';
			break;
		}
		cout << ' ';
	}
	cout << endl;
	for (auto i = 0; i < n; i++)
	{
		for (auto i = s.begin(); i < s.end(); ++i)
		{
			switch (*i)
			{
			case '0': case '8': case '6': 
				cout << '|';
				for (auto i = 0; i < n; ++i)
					cout << ' ';
				cout << '|';
				break;
			case '3': case '1': case '7': case '4': case '5':  case '9':
				for (auto i = 0; i < n + 1; ++i)
					cout << ' ';
				cout << '|';
				break;
			case '2': 
				cout << '|';
				for (auto i = 0; i < n + 1; ++i)
					cout << ' ';
				break;
			}
			cout << ' ';
		}
		cout << endl;
	}
	for (auto i = s.begin(); i < s.end(); ++i)
	{
		switch (*i)
		{
		case '1': case '7': case '4':
			for (auto i = 0; i < n + 2; ++i)
				cout << ' ';
			break;
		case '2': case '3': case '5': case '6': case '8': case '9': case '0': 
			cout << ' ';
			for (auto i = 0; i < n; ++i)
				cout << '-';
			cout << ' ';
			break;
		}
		cout << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}