#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

int game()
{
	int number;
	int trial = 1;
	int guess;
	//string again;
	string s("!!!GUESS THE NUMBER¡¡¡\n");
	string w("!!BINGO!! YOUR GUESS WAS CORRECT¡¡");
	string l("BETTER LUCK NEXT TIME");
	cout << setw(70) << setfill('*') << right << s;
	srand(time(0));
	number = rand();
	while (number > 15)
	{
		number = number % 15 + 1;
	}
	string g("guess the number.it is between 1 and 15\n");
	cout << g;
	//	cout << number;
	while (trial < 4)
	{
		cout << "guess " << trial << endl;
		cin >> guess;
		if (guess > number)
		{
			cout << "Too Big. Try again\n"
				 << endl;
			trial++;
		}
		if (guess < number)
		{
			cout << "too small\n";
			trial++;
		}
		if (guess == number)
		{
			cout << w << endl;
			cout << "answer is :" << number << endl;
			break;
		}
		if (trial == 4)
		{
			cout << "answer is :" << number << endl;
		}
	}
	cin.sync();
	cin.clear();
}
int main()
{
	string again;
	game();
	cout << "Wanna Try again??. Type y/n\n";
	cin >> again;
	if (again == "y")
	{
		main();
	}
	if (again == "n")
	{
		cout << "Thanks for playing! Looser";
		cin.clear();
		return 0;
	}
}