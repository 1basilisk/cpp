#include <ctype.h>
#include "cs50.h"
#include "cs50.c"
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: %s\n", word1);
    string word2 = get_string("Player 2: %s\n", word2);

    
    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //printf("%s  %s", word1, word2);
    //print winner
    if (score1 > score2)
    {
        printf("Player1 Wins!");
    }
    else if (score1 < score2)
    {
        printf("Player2 Wins!");
    }
    else
    {
        printf("Tie!");
    }
    printf("\n");
}

int compute_score(string word)
{
    int score = 0;
    
    //to upper case and score count
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        word[i] = toupper(word[i]);
        if (word[i] > 'A' && word[i] < 'Z')
        {
        int index = (int)word[i];
        score += POINTS[index - 65];
        }
    }
    
    return score;
    
}