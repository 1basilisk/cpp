#include "cs50.h"
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

string toUpper(string str);
float countLetters(string str);
float countWords(string str);
float countSent(string str);
float grade(float l, float w, float s);

float letters = 0;
float words = 0;
float sent = 0;
float index = 0;

int main(void)
{
	//input
	string text = get_string("Text: ");

	//doing all operations
	toUpper(text);
	countLetters(text);
	countWords(text);
	countSent(text);

	//grading
	grade(letters, words, sent);
}

//changing to uppercase
string toUpper(string str)
{
	for (int i = 0, n = strlen(str); i < n; i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

//counting [a-z] and [A-Z]
float countLetters(string str)
{
	for (int i = 0, n = strlen(str); i < n; i++)
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
		{
			letters++;
		}
	}
	//    printf("letters: %f \n", letters);
	return letters;
}

//counting spaces to xount words
float countWords(string str)
{
	int spaces = 0;
	for (int i = 0, n = strlen(str); i < n; i++)
	{
		if (str[i] == ' ')
		{
			spaces++;
		}
	}
	words = spaces + 1;
	//    printf("Words: %f\n", words);
	return words;
}

//.?! marks a sent.
float countSent(string str)
{
	for (int i = 0, n = strlen(str); i < n; i++)
	{
		if (str[i] == '.' || str[i] == '!' || str[i] == '?')
		{
			sent++;
		}
	}
	//   printf("Sentences: %f\n", sent);
	return sent;
}

//grading by Coleman-Liau
float grade(float l, float w, float s)
{
	int grade;
	float L = (letters / words) * 100;
	float S = (sent / words) * 100;
	index = (0.0588 * L) - (0.296 * S) - 15.8;
	grade = round(index);
	//index = (int)index;

	if (index < 1)
	{
		printf("Before Grade 1\n");
	}
	else if (index > 16)
	{
		printf("Grade 16+\n");
	}
	else
	{
		printf("Grade %i\n", grade);
	}

	//  printf("Grade: %f\n", index);
	//    printf("L:   %f\n", L);
	//    printf("S: %f\n", S);

	return index;
}