#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
	if (argc < 2 || argc > 2)
	{
		printf("Usage: ./caesar key\n");
		return 1;
	}
	string text = argv[1];
	char crack[strlen(text)];

	int cip = 0;
	//looping throu the text
	for (int key = 1; key < 26; key++)
	{
		//printf("code: %s crack: %s\n", text, crack);
		for (int i = 0, n = strlen(text); i < n; i++)
		{
			//deciphering small
			if (text[i] <= 'z' && text[i] >= 'a')
			{
				// printf("key:  %i\n", key);
				cip = (text[i] - key);
				while (cip < 97)
				{
					cip = cip + 26;
				}
				//printf("%i\n", cip);
				crack[i] = (char)cip;
			}
			//deciphering capital
			else if (text[i] <= 'Z' && text[i] >= 'A')
			{
				cip = 0;
				cip = (text[i] - key);
				//printf("%i\n", cip);
				while (cip < 65)
				{
					cip = cip + 26;
				}
				//printf("%i\n", cip);
				crack[i] = (char)cip;
			}
			else
			{
				crack[i] = text[i];
			}
		}
		printf("key: %i plaintext: %s\n", key, crack);
	}
}
