#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Convert image to grayscale
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            new_image[i][j] = image[i][width - j - 1];
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = new_image[i][j];
        }
    }
       
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            new_image[i][j] = image[i][j];
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;
            int count = 0;

            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k < 0 || i + k >= height || j + l < 0 || j + l >= width)
                        continue;

                    sum_red += new_image[i + k][j + l].rgbtRed;
                    sum_green += new_image[i + k][j + l].rgbtGreen;
                    sum_blue += new_image[i + k][j + l].rgbtBlue;
                    count++;
                }
            }

            image[i][j].rgbtRed = round(sum_red / (float) count);
            image[i][j].rgbtGreen = round(sum_green / (float) count);
            image[i][j].rgbtBlue = round(sum_blue / (float) count);
        }
    }

    return;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
