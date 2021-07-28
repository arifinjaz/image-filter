#include "helpers.h"
#include <stdio.h>
#include <math.h>
// Convert image to grayscale
int sepiablue(int blue, int green, int red);
int sepiagreen(int blue, int green, int red);
int sepiared(int blue, int green, int red);
int avg(int blue, int green, int red);
//void swap (void *f, void *l);

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg1 = avg(image[i][j].rgbtBlue, image[i][j].rgbtGreen, image[i][j].rgbtRed);

            image[i][j].rgbtBlue = avg1;
            image[i][j].rgbtGreen = avg1;
            image[i][j].rgbtRed = avg1;
        }
    }

    //FILE *test = fopen("test.txt","w");
    //fprintf(test,"height is: %i \n Width is: %i \n",height,width);
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue = sepiablue(image[i][j].rgbtBlue, image[i][j].rgbtGreen, image[i][j].rgbtRed);
            int green = sepiagreen(image[i][j].rgbtBlue, image[i][j].rgbtGreen, image[i][j].rgbtRed);
            int red = sepiared(image[i][j].rgbtBlue, image[i][j].rgbtGreen, image[i][j].rgbtRed);


            image[i][j].rgbtBlue = blue;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtRed = red;

        }
    }
    return;
}


void swap(BYTE *f, BYTE *l)
{
    BYTE temp = 0;
    temp = *f;
    *f = *l;
    *l = temp;
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int w = width - 1;
    int re = 0;
    BYTE *temp = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            re = w - j;
            swap(&image[i][j].rgbtBlue, &image[i][re].rgbtBlue);
            swap(&image[i][j].rgbtGreen, &image[i][re].rgbtGreen);
            swap(&image[i][j].rgbtRed, &image[i][re].rgbtRed);
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE tempimage[height][width]; // Temp variable to store modified data temp/
    float avgb = 0; // to store average of blue
    float avgg = 0; // to store average of green
    float avgr = 0; // to store average of red

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            if (i == 0 && j == 0) // to blur the first pixcel first row first column
            {
                avgb = 0;
                avgg = 0;
                avgr = 0;

                avgb = ((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4.0);
                avgg = ((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4.0);
                avgr = ((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4.0);

                tempimage[i][j].rgbtBlue = round(avgb);
                tempimage[i][j].rgbtGreen = round(avgg);
                tempimage[i][j].rgbtRed = round(avgr);
            }

            else if (i == 0 && j == (width - 1)) // to blur the pixcel in first row last column
            {
                avgb = 0;
                avgg = 0;
                avgr = 0;

                avgb = ((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 4.0);
                avgg = ((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 4.0);
                avgr = ((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed) / 4.0);

                tempimage[i][j].rgbtBlue = round(avgb);
                tempimage[i][j].rgbtGreen = round(avgg);
                tempimage[i][j].rgbtRed = round(avgr);
            }

            else if (i == (height - 1) && j == (width - 1)) // to blur the pixcel in last row last column
            {
                avgb = 0;
                avgg = 0;
                avgr = 0;

                avgb = ((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / 4.0);
                avgg = ((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / 4.0);
                avgr = ((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed) / 4.0);

                tempimage[i][j].rgbtBlue = round(avgb);
                tempimage[i][j].rgbtGreen = round(avgg);
                tempimage[i][j].rgbtRed = round(avgr);
            }

            else if (i == (height - 1) && j == 0) // to blur the first pixcel last row.
            {
                avgb = 0;
                avgg = 0;
                avgr = 0;

                avgb = ((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 4.0);
                avgg = ((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 4.0);
                avgr = ((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 4.0);

                tempimage[i][j].rgbtBlue = round(avgb);
                tempimage[i][j].rgbtGreen = round(avgg);
                tempimage[i][j].rgbtRed = round(avgr);
            }

            else if ((i == (height - 1) || i == 0) && j != 0 && j != (width - 1)) // To Blur horizontal edges
            {
                avgb = 0;
                avgg = 0;
                avgr = 0;
                
                if (i == 0) // To blur the top row
                {
                    for (int c = i ; c < i + 2; c++)
                    {
                        for (int d = j - 1; d < j + 2; d++)
                        {
                            avgb += image[c][d].rgbtBlue;
                            avgg += image[c][d].rgbtGreen;
                            avgr += image[c][d].rgbtRed;
                        }
                    }
                }
                else if (i == (height - 1)) // To blur the bottom row
                {
                    for (int c = i - 1; c < i + 1; c++)
                    {
                        for (int d = j - 1; d < j + 2; d++)
                        {
                            avgb += image[c][d].rgbtBlue;
                            avgg += image[c][d].rgbtGreen;
                            avgr += image[c][d].rgbtRed;
                        }
                    }
                }
                tempimage[i][j].rgbtBlue = round(avgb / 6);
                tempimage[i][j].rgbtGreen = round(avgg / 6);
                tempimage[i][j].rgbtRed = round(avgr / 6);
            }

            else if ((j == (width - 1) || j == 0) && i != 0 && i != (height - 1)) // To Blur vertical edges
            {
                avgb = 0;
                avgg = 0;
                avgr = 0;

                if (j == 0) // to blur the first row
                {
                    for (int c = j ; c < j + 2; c++)
                    {
                        for (int d = i - 1; d < i + 2; d++)
                        {
                            avgb += image[d][c].rgbtBlue;
                            avgg += image[d][c].rgbtGreen;
                            avgr += image[d][c].rgbtRed;
                        }
                    }
                }
                else if (j == (width - 1)) // To blur the last row
                {

                    for (int c = j - 1; c < j + 1; c++)
                    {
                        for (int d = i - 1; d < i + 2; d++)
                        {
                            avgb += image[d][c].rgbtBlue;
                            avgg += image[d][c].rgbtGreen;
                            avgr += image[d][c].rgbtRed;
                        }
                    }
                }
                tempimage[i][j].rgbtBlue = round(avgb / 6);
                tempimage[i][j].rgbtGreen = round(avgg / 6);
                tempimage[i][j].rgbtRed = round(avgr / 6);
            }

            else if (i != 0 && i != (height - 1) && j != 0 && j != (width - 1)) // to Blur the entire body except edges
            {
                avgb = 0;
                avgg = 0;
                avgr = 0;

                for (int c = i - 1; c < i + 2; c++) // loop to pick 3 rows
                {
                    for (int d = j - 1; d < j + 2; d++) // loop to pick 3 columns
                    {
                        avgb += image[c][d].rgbtBlue;
                        avgg += image[c][d].rgbtGreen;
                        avgr += image[c][d].rgbtRed;
                    }
                }

                tempimage[i][j].rgbtBlue = round(avgb / 9);
                tempimage[i][j].rgbtGreen = round(avgg / 9);
                tempimage[i][j].rgbtRed = round(avgr / 9);
            }
        }
    }

    for (int r = 0; r < height; r++) // to assign actual values from temp variable to main variable
    {
        for (int s = 0; s < width; s++)
        {
            image[r][s].rgbtBlue = tempimage[r][s].rgbtBlue;
            image[r][s].rgbtGreen = tempimage[r][s].rgbtGreen;
            image[r][s].rgbtRed = tempimage[r][s].rgbtRed;
        }
    }
    return;
}


int avg(int blue, int green, int red) // to get average for of 3 int.
{
    float avg = round((blue + green + red) / 3.0);
    return avg;
}


int sepiablue(int blue, int green, int red) // Sepia blue Algorithm
{
    float t = round((float)(red * .272) + (green * .534) + (blue * .131));
    if (t > 255)
    {
        t = 255;
    }
    return t;
}

int sepiagreen(int blue, int green, int red) //Sepia green Algorithm
{
    float t = round((float)(red * .349) + (green * .686) + (blue * .168));
    if (t > 255)
    {
        t = 255;
    }
    return t;
}

int sepiared(int blue, int green, int red) //Sepia red Algorithm
{
    float t = round((float)(red * .393) + (green * .769) + (blue * .189));
    if (t > 255)
    {
        t = 255;
    }
    return t;
}

