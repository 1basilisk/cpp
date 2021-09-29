/*
 Name: Utkarsh Sharma
Date: 27/09/2021
Purpose: Game of Bingo
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 5 // size of board

void print();
int board[size][size];
int main()
{
    int a = 1; // number to be filled in array;
    // creating board for computer
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++, a++)
        {
          
            board[i][j] = a;
            printf("%.2d  ", board[i][j]);
        }
        printf("\n");
    }

    //randomly eliminating numbers
    int total = 0;
    int tries = 0;
    while (total < 25)
    {
        int x, y; 
        srand(time(0));
        x = rand() % 5;
        y = rand() % 5;
        tries++;

        if (board[x][y] != 0)
        {
            board[x][y] = 0;
        }
        else
        {
            continue;
        }
        total++;
        puts("");
        print();
    }
    printf("%d", tries);
    return 0;
}
void print()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%.2d  ", board[i][j]);
        }
        puts(" ");
    }
}