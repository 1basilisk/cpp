#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;
int sc1 = 100;
int sc2 = 100;
string l("BETTER LUCK NEXT TIME\n");
int text() //heading
{
	cout << setw(80) << setfill('_') << ".";
	string g("\n I have two things in my mind a number between 1 and 15, and a prediction that you can not guess it.\n Prove me wrong!\n");
	cout << setw(80) << g;
	cout << "There are five rounds in this game. In each round, you have to guess the number in three attempts.\n Both Computer and You start at 100 points. The predecessor of  number of attempts taken will be deducted from your initial 100  and the computer will lose 3 points after each attempt . \n The One with higher score wins! \n LET'S START\n";
	cout << setw(80) << setfill('_') << " ";
}
int score() //prints score
{
	cout << "Your score: " << sc1 << endl;
	cout << "Computer Score: " << sc2 << endl;
}
int game() //main function
{
	int number;
	int trial = 0;
	int guess;

	//string again;
	string s("!!!GUESS THE NUMBER¡¡¡\n");
	string w("!!BINGO!! YOUR GUESS WAS CORRECT¡¡");

	cout << setw(70) << setfill('_') << right << s;
	srand(time(0));
	number = rand();
	number = number % 15 + 1;

	//
			cout << number;

		while (trial < 3)
		{
			cout << "Guess " << trial + 1 << endl;
			cin >> guess;
			if (guess > number)
			{
				cout << "It is less than " << guess << endl;
				trial++;
			}
			if (guess < number)
			{
				cout << "Think big!l\n";
				trial++;
			}
			if (guess == number)
			{
				cout << w << endl;
				if (trial == 0)
				{
					cout << "Good job! you did it in just one try\n";
				}
				if (trial == 1)
				{
					cout << "Two tries are not bad!\n";
				}
				if (trial == 2)
				{
					cout << "That was a close one!!\n";
				}
				cout << number << " was the answer" << endl;

				break;
			}
			if (trial == 3) //prints answer after loosing
			{
				cout << "Correct Number was " << number << endl;
			}
			sc1 = sc1 - 2 * trial;
			sc2 = sc2 - 3;
			score();
			cin.sync();
			cin.clear();
		
	}
}

int main()
{
		string p_again = "y";
	  while(p_again=="y" ){
	text();
	int rounds = 1;
	while (rounds < 4)
	{
		cout << "ROUND " << rounds << endl;
		game();

		++rounds;
	}
	//	cout << "sc1 " << sc1 << endl;
	//	cout <<"sc2" << sc2 <<endl;
	if (sc1 > sc2)
	{
		cout << "You Won! \n";
		//		score();
	}
	else
	{
		cout << " You Lost\n"
			 << l;
		//		score();
	}

	string again;
	cout << "Wanna Try again??. Type y/n\n";
/*	cin >> again;
	if (again == "y")
	{
		sc1 = 100;
		sc2 = 100;
		main();
	}*/
	cin >> p_again;
	if (p_again == "n")
	{
		cout << "Thanks for playing! Looser";
		cin.clear();
	
		
		
		
		return 0;
	}
}
}