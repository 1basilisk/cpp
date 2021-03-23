// guess
// 	A simple number guessing game.
//	Current verion: 3.2
//----------------------------------------------
// Author: Utkarsh Sharma
//----------------------------------------------
// Last Modified by: Rohit Mehta
// Last Modified: 10 May 2020 13:08
//-----------------------------------------------
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;
int user_score = 100;
int comp_score = 100;
string l("BETTER LUCK NEXT TIME\n");
void text()          //heading
{
	cout << setw(80) << setfill('_') << left << '\n';
	cout << setw(80) << "\n I have two things in my mind a number between 1 and 15, and a prediction that you can not guess it.\n Prove me wrong!\n";
	cout << "There are five rounds in this game. In each round, you have to guess the number in three attempts.\n" 
	" Both Computer and You start at 100 points. The predecessor of  number of attempts taken will be deducted from your initial 100"
	"  and the computer will lose 3 points after each attempt . \n The One with higher score wins! \n LET'S START\n";
	cout << setw(80) << setfill('_') << " ";
}
void score()              //prints score
{
	cout << "Your score:        " << user_score << endl;
	cout << "Computer's Score:  " << comp_score << endl;
}
void game()           //main function
{
	int number, trial = 1, guess;

	//string again;
	string guess_title("!!!GUESS THE NUMBER!!!\n");
	string win_prompt("!!BINGO!! YOUR GUESS WAS CORRECT!!");

	cout << setw(70) << setfill('_') << right << guess_title;
	
	srand( time(NULL) );		// set the current time as random seed
	number = rand() % 15 + 1;	// the number is b/n 1 - 15 (inclusive)

	//		cout << number;
	while (trial <= 3)
	{
		cout << "Guess " << trial << endl;
		cin >> guess;	cin.sync(); cin.clear();		// sync() input stream and clear error flags(if any)
		if (guess > number)
		{
			cout << "It is less than " << guess << endl;
			trial++;
		}
		else if (guess < number)
		{
			cout << "Think big!l\n";
			trial++;
		}
		else 		// guess == number
		{
			cout << win_prompt << endl;
			switch(trial){
				case 1:	cout << "Good job! Looks like your lucky today.\n";
				break;

				case 2: cout << "Two tries are not bad!\n";
				break;

				case 3: cout << "That was a close one!!\n"
							<< "But you nailed it. Good.\n";
				break;

				default:  cerr << "\nError: This shouldn't have happened.\n\n";
			}
			break;
		}
	}
	user_score -= trial;	// new scores after the trials
	comp_score -= 3;
	score();			// show score
}
int main()
{
	text();
	int rounds = 1;
	while (rounds < 4)
	{
		cout << "ROUND " << rounds << endl;
		game();

		++rounds;
	}
	//	cout << "user_score " << user_score << endl;
	//	cout <<"comp_score" << comp_score <<endl;
	if (user_score > comp_score)
	{
		cout << "You Won! \n";
		//		score();
	}
	else if( user_score < comp_score)
	{
		cout << " You Lost\n"
			 << l;
		//		score();
	}
	else
	{
		cout << "Its a Draw.\n";
	}
	

	char again;
	cout << "Wanna Try again? [y/n: default: n]:        ";
	cin.get(again);	cin.sync();
	if (again == 'y' || again == 'Y')
	{
		user_score = 100;
		comp_score = 100;
		main();
	}
	else
		cout << "Thanks for playing! Looser";

	return 0;
}