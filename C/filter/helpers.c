#include "helpers.h"
#include <stdio.h>
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
	//loops thru all elements;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//accessing rgb values;
			RGBTRIPLE pixel = image[i][j];
			float r = (pixel.rgbtRed);
			float g = (pixel.rgbtGreen);
			float b = (pixel.rgbtBlue);
			//taking average and rounding
			BYTE average = round((r + g + b) / 3.0);

			//assigning new value;
			image[i][j].rgbtRed = average;
			image[i][j].rgbtGreen = average;
			image[i][j].rgbtBlue = average;
		}
	}
	return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
	//iterating through the file;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//old values;
			RGBTRIPLE pixel = image[i][j];
			float r = (pixel.rgbtRed);
			float g = (pixel.rgbtGreen);
			float b = (pixel.rgbtBlue);
			//new values;
			float R = (0.393 * r) + (0.769 * g) + (0.189 * b);
			float G = (0.349 * r) + (0.686 * g) + (0.168 * b);
			float B = (0.272 * r) + (0.534 * g) + (0.131 * b);
			//rounding values;
			R = round(R);
			G = round(G);
			B = round(B);
			//capping to;255 || better implementation possible;
			if (R > 255)
			{
				R = 255;
			}
			if (G > 255)
			{
				G = 255;
			}
			if (B > 255)
			{
				B = 255;
			}

			//assigning new values;
			image[i][j].rgbtRed = R;
			image[i][j].rgbtGreen = G;
			image[i][j].rgbtBlue = B;
		}
	}
	return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
	//space for new image;
	RGBTRIPLE newimage[height][width];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//flipping row elements;
			newimage[i][j] = image[i][width - j - 1];
		}
	}

	//savinging new image;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			image[i][j] = newimage[i][j];
		}
	}
	return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
	//making a replica;
	RGBTRIPLE copy[height][width];
	for (int h = 0; h < height; h++)
	{
		for (int k = 0; k < width; k++)
		{
			copy[h][k] = image[h][k];
		}
	}
	float n; //number of pixels in arrays;
	float r, g, b;
	//going thru all pixels;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			n = 0;
			r = 0;
			g = 0;
			b = 0;
			//going thru arrays of 9s;
			for (int ii = -1; ii <= 1; ii++)
			{
				for (int jj = -1; jj <= 1; jj++)
				{
					//checking for border cases
					if (i + ii >= 0 && i + ii < height && j + jj >= 0 && j + jj < width)
					{
						n++;
						r += (float)copy[i + ii][j + jj].rgbtRed;
						g += (float)copy[i + ii][j + jj].rgbtGreen;
						b += (float)copy[i + ii][j + jj].rgbtBlue;
					}
				}
			}
			//printf("%f ", n);
			//saving changes in original file;
			image[i][j].rgbtRed = (int)round(r / n);
			image[i][j].rgbtGreen = (int)round(g / n);
			image[i][j].rgbtBlue = (int)round(b / n);
		}
		//printf("\n\n\n\n");
	}
	return;
}

//edge detection
void edge(int height, int width, RGBTRIPLE image[height][width])
{
	//defining kernel;
	int kernel[3][3];
	kernel[0][0] = -1;
	kernel[0][1] = 0;
	kernel[0][2] = 1;
	kernel[1][0] = -2;
	kernel[1][1] = 0;
	kernel[1][2] = 2;
	kernel[2][0] = -1;
	kernel[2][1] = 0;
	kernel[2][2] = 1;
	
	//making a replica;
	RGBTRIPLE copy[height][width];
	RGBTRIPLE copy2[height][width];
	for (int h = 0; h < height; h++)
	{
		for (int k = 0; k < width; k++)
		{
			copy[h][k] = image[h][k];
			copy2[h][k] = image[h][k];
		}
	}
	float n; //number of pixels in arrays;
	float r, g, b;
	//going thru all pixels;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			n = 0;
			r = 0;
			g = 0;
			b = 0;
			//going thru arrays of 9s;
			for (int ii = -1; ii <= 1; ii++)
			{
				for (int jj = -1; jj <= 1; jj++)
				{
					//checking for border cases
					if (i + ii >= 0 && i + ii < height && j + jj >= 0 && j + jj < width)
					{
						n++;
						r += (float)copy[i + ii][j + jj].rgbtRed * jj;
						g += (float)copy[i + ii][j + jj].rgbtGreen * jj;
						b += (float)copy[i + ii][j + jj].rgbtBlue * jj;
					}
				}
			}
			//printf("%f ", n);
			//saving changes in original file;
			copy[i][j].rgbtRed = (int)round(r / n);
			copy[i][j].rgbtGreen = (int)round(g / n);
			copy[i][j].rgbtBlue = (int)round(b / n);
		}
		//printf("\n\n\n\n");
	}
	//vertical detection;
//	float n; //number of pixels in arrays;
//	float r, g, b;
	//going thru all pixels;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			n = 0;
			r = 0;
			g = 0;
			b = 0;
			//going thru arrays of 9s;
			for (int ii = -1; ii <= 1; ii++)
			{
				for (int jj = -1; jj <= 1; jj++)
				{
					//checking for border cases
					if (i + ii >= 0 && i + ii < height && j + jj >= 0 && j + jj < width)
					{
						n++;
						r += (float)copy[i + ii][j + jj].rgbtRed * ii;
						g += (float)copy[i + ii][j + jj].rgbtGreen * ii;
						b += (float)copy[i + ii][j + jj].rgbtBlue * ii;
					}
				}
			}
			//printf("%f ", n);
			//saving changes in original file;
			copy2[i][j].rgbtRed = (int)round(r / n);
			copy2[i][j].rgbtGreen = (int)round(g / n);
			copy2[i][j].rgbtBlue = (int)round(b / n);
		}
		//printf("\n\n\n\n");
	}
for (int i = 0; i < height; i++)
{
	for (int j = 0; j < width; j++)
	{
		image[i][j].rgbtRed = round(sqrt((copy2[i][j].rgbtRed * copy2[i][j].rgbtRed) + (copy2[i][j].rgbtRed * copy2[i][j].rgbtRed)));
		image[i][j].rgbtGreen = image[i][j].rgbtRed;
		image[i][j].rgbtBlue = image[i][j].rgbtBlue;
	
	return;
}
}
}