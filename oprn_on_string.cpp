#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	string s("your name!"), name, total;
	cout << s;
	getline(cin, name);
	total = s + "is " + name;
	cout << uppercase << total;
	int x = name.length();
	double y = sqrt(x);
	cout << endl
		 << x;
	cout << endl
		 << y;
	cout << endl
		 << pow(y, 2);
}
