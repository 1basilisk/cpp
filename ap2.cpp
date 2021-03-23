#include <iostream>
#include "aph2.h"
using namespace std;
int main()
{
	float a, n, d;

	cout << "enter first number";
	cin >> a;
	cout << "enter number of terms";
	cin >> n;
	cout << "enter common difference";
	cin >> d;
	//finding nth term
	int Term = a + (n - 1) * d;
	cout << "Nth term of the AP is:";
	cout << Term;

	//finding sum of n terms
	int sum;
	cout << endl
		 << "Sum of n terms is:";
	sum = (n * (2 * a + (n - 1) * d)) / 2;
	cout << sum;

	printap();
}