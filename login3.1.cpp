/*-------------------------------------------------------------//
 usr_name: basilisk									  
 pass1: @#£_&
 pass2: number2
 wrong pass2 would lead to an infinite    loop
 correct pass1 or pass2 would lead to       quadraric equation solver.
//-------------------------------------------------------------*/
#include <iostream>
#include <cmath>

using namespace std;
void crash()
{
	int j = 0;
	while (j != -1)
	{
		cout << j;
	}
}

int myf()
{
	
}
int quad()
{cout << "you are welcome to quadratic equation solver \n" << endl;
	double a, b, c, D, r1, r2;
	cout << "enter cofficient of x²"
		 << "\t"; //this will take coff. of x²
	cin >> a;
	cout << "\n"
		 << "enter cofficient of x"
		 << "\t"; //coff. of x
	cin >> b;
	cout << "\n"
		 << "enter constant term"
		 << "\t"; //constant term
	cin >> c;
	// Finding discriminant.
	D = b * b - 4 * a * c;
	//Putting Conditions.
	if (D < 0)
	{
		cout << "No Real Root. Try Again"
			 << "\n"
				"\n"; /*since D is negative roots are imaginary*/

quad();
}
if (D == 0) // condition for equal root
{
	r1 = -b / 2 / a;
	cout << "\t";
	cout << "The Root Is:";
	cout << "\t" << r1;
	cout << "\n";
}
if (D > 0) /*condition for real and unequal roots*/
{
	r1 = (-b + sqrt(D)) / 2 / a;
	r2 = (-b - sqrt(D)) / 2 / a;
	cout << "Roots are:"
		 << "\t"
		 << r1 << "\t"
		 << "And"
		 << "\t" << r2;
}
return 0;
}

int main()
{
	string username;
	string passcode, c;

	cout << "enter user name";
	cout << "\t"
			"\t";
	cin >> username;
	if (username == "basilisk")
	{
		cout << "enter passcode";
		cout << "\t"
				"\t";
		cin >> passcode;
		if (passcode == "@#£_&")
		{
			myf();
			quad();
		}

		else
		{
			cout << "wrong password";
			cout << "\n";
			cout << "this is your last attempt";
			cout << "\n";
			cout << "enter passcode \t \t";
			cin >> passcode;
			if (passcode == "number2")
			{
				quad();
			}
			else
			{
				cout << "access unauthorized";
				crash();
			}
		}
	}
	else
	{
		cout << "unauthorized username"
			 << "\n";
		main();
		;
	}
	return 0;
}