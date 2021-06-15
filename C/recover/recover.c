#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//function protocols;bool jpgFound(BYTE)
int main(void/*int argc, char *argv[]*/)
{
	//fair Use;
/*	if (argc != 2)
	{
		printf("usage: ./recover [source]\n");
		return 1;
	}*/
	typedef uint8_t BYTE;
	char *input;
	printf("Enter file name:  ");
	scanf("%s", &input);
	//opening sdcard
	FILE *sdcard = fopen(&input/*argv[1]*/, "r");
	if (sdcard == NULL)
	{
		printf("couldn't access file\n");
		return 1;
	}

	bool jpgFound = false;
	FILE *img;

	BYTE sample[512];
	int n = 0;
	while (fread(sample, sizeof(BYTE), 512, sdcard) != 0)
	{
		//chexking for jpeg signature;
		if (sample[0] == 0xff && sample[1] == 0xd8 && sample[2] == 0xff && (sample[3] & 0xf0) == 0xe0)
		{
			if (jpgFound == true)
			{
				fclose(img);
				n++;
				//jpgFound = false;
			}
			jpgFound = true;

			char file[8];
			sprintf(file, "%03i.jpg", n);
			//opening jpeg;
			img = fopen(file, "w");
			if (img == NULL)
			{
				printf("image file not made\n");
				return 2;
			}
			fwrite(sample, sizeof(BYTE), 512, img);
		}
		else if (jpgFound == true)
		{
			fwrite(sample, sizeof(BYTE), 512, img);
		}
	}
	fclose(img);
}