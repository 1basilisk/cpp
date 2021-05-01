#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
double a, d, n, l, s;
int x,y;
void print() 								 //print sum
{										    						
	cout << "\n Sum of ";	         //sum of n
	cout << n;								//terms of
	cout << " terms of AP: \t\t";  //AP:
	cout << s;
	cout << "\n";
	
}
void printap()							 //prints AP 
{
	cout << "AP is: \t\t\t";
	do
	{
		
		cout << a;
		cout << ", ";
		a = a + d;
		y=++y;
	} while (y<n);
}
void input()         					    // taking input
{
	cout << "Enter The First Term \t\t";
	cin >> a;
	cout << "\n";
	cout << "Enter Number of Terms \t\t";
	cin >> n;
	cout << "\n";
	cout << "Enter Common Difference \n";
	cout << "Or Enter  ";
	srand(time(0));
	x = rand();
	cout << x;
	cout << "  if Common Difference Is Unknown\n\t\t\t\t";           //Switch Input
	cin >> d;
	if (d == x)

	{
		cout << "Enter Last Term \t\t";
		cin >> l;
	}
}
int main()
{
	while (1 > 0)
	{
		cout << "\n  ***************** ARITHMATIC PROGRESSION *****************\n";
		input();
		if (d == x)
		{
			s = n * (l + a) / 2;
			print();
			cout << "Common Difference is: \t\t";
			d = (1 / (n - 1)) * ((2 * s / n) - 2 * a);
			cout << d  << endl;
			printap();
		}
		else
		{
			s = (n * (2 * a + (n - 1) * d)) / 2;
			print();
			l =  a + (n - 1) * d;
		cout << " \n Last Term of AP: \t\t" << l;
		cout << endl;
		   printap();
		}
	}
	return 0;
}
//working.