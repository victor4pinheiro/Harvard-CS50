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
    RGBTRIPLE new_image[height][width];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            new_image[i][j] = image[i][j];
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float gx_red = 0;
            float gx_green = 0;
            float gx_blue = 0;

            float gy_red = 0;
            float gy_green = 0;
            float gy_blue = 0;

            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k < 0 || i + k >= height || j + l < 0 || j + l >= width)
                        continue;
                        
                    // gx
                    gx_red += gx[k + 1][l + 1] * new_image[i + k][j + l].rgbtRed;
                    gx_green += gx[k + 1][l + 1] * new_image[i + k][j + l].rgbtGreen;
                    gx_blue += gx[k + 1][l + 1] * new_image[i + k][j + l].rgbtBlue;
                    // gy
                    gy_red += gy[k + 1][l + 1] * new_image[i + k][j + l].rgbtRed;
                    gy_green += gy[k + 1][l + 1] * new_image[i + k][j + l].rgbtGreen;
                    gy_blue += gy[k + 1][l + 1] * new_image[i + k][j + l].rgbtBlue;
                }
            }

            int red = round(sqrt(gx_red * gx_red + gy_red * gy_red));
            int green = round(sqrt(gx_green * gx_green + gy_green * gy_green));
            int blue = round(sqrt(gx_blue * gx_blue + gy_blue * gy_blue));

            if (red > 255)
                red = 255;
            if (green > 255)
                green = 255;
            if (blue > 255)
                blue = 255;

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }

    return;
}
