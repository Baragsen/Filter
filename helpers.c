#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; i < width; j++)
        {
            int gray = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed ) / 3.0;
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{   
    int const MAX = 255;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; i < width; j++)
        {   
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue ;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = min(MAX ,round(sepiaBlue) );
            image[i][j].rgbtGreen = min(MAX , round(sepiaGreen) );
            image[i][j].rgbtRed = min(MAX , round(sepiaRed) );
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
         for (int j = 0; i < width; j++)
        {
            int k = width - (i+1);
            image[i][j] = image[i][k];
            image[i][k] = image[i][j];
        }  
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}