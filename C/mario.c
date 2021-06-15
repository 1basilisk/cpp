#include <stdio.h>

int main(void)
{
	//taking height

	int height = 10;
	while (height < 1)
	{
		printf("Height:  ");
		scanf("%i", &height);
	}
	//building blocks

	//printf("%i", height);
	for (int i = 1; i <= height; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (j < height - i)
			{
				printf("~", j);
			}
			else
			{
				printf("#");
			}
		}
		printf("\n");
	}
}
