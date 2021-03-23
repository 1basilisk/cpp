/*
number guessing game
5 rounds
user gets points for correct guess:
3 pt: 1st attempt
2 pt: 2nd
1 pt: 3rd
computer gets opposite of user
max score wins!
username is asked
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

int score1 = 0;
int score2 = 0;
int rounds = 1;
int trial =0;
int score()
{
	if (trial == 1)
	{
		score1 = score1 + 3;
	}
	if (trial == 2)
	{
		score1 = score1 + 2;
		score2 = score2 + 2;
	}
	if (trial == 3)
	{
		score2 = score2 + 3;
	}
	if(score1>score2){
		cout << score1;
	}
	else{cout << score2<< endl << "looser" ;
	}
}
int game()
{
//	while (rounds < 3)
	{
		rounds = rounds + 1;
		int number;
		int guess;
		int trial = 1;
		string w("You Guessed It Correct!\n");
		string l("You Are Pointless\n");
		srand(time(0));
		number = rand();
		number = number % 15 + 1;
		cout << number << endl;
		while (trial < 4)
		{
			cin >> guess;
			if (guess > number)
			{
				cout << " It is less than that!" << l;
				++trial;
			}
			if (guess < number)
			{
				cout << " think bigger!";
			}
			if (number == guess)
			{
				cout << w;
			}
		}
		
	}
}
int main()
{if (rounds < 3){
	game();
	score();
}
else{return 0; }
}