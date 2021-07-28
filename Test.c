#include <stdio.h>
#include <math.h>
#include <stdint.h>

typedef uint8_t  BYTE;

typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;

RGBTRIPLE image[3][3];

int main (void)
{

    image[0][0].rgbtBlue = 10;
    image[0][1].rgbtBlue = 40;
    image[0][2].rgbtBlue = 70;
    image[1][0].rgbtBlue = 110;
    image[1][1].rgbtBlue = 120;
    image[1][2].rgbtBlue = 130;
    image[2][0].rgbtBlue = 200;
    image[2][1].rgbtBlue = 229;
    image[2][2].rgbtBlue = 240;

    image[0][0].rgbtGreen = 20;
    image[0][1].rgbtGreen = 50;
    image[0][2].rgbtGreen = 80;
    image[1][0].rgbtGreen = 130;
    image[1][1].rgbtGreen = 140;
    image[1][2].rgbtGreen = 150;
    image[2][0].rgbtGreen = 210;
    image[2][1].rgbtGreen = 230;
    image[2][2].rgbtGreen = 250;

    image[0][0].rgbtRed = 30;
    image[0][1].rgbtRed = 60;
    image[0][2].rgbtRed = 90;
    image[1][0].rgbtRed = 140;
    image[1][1].rgbtRed = 150;
    image[1][2].rgbtRed = 160;
    image[2][0].rgbtRed = 220;
    image[2][1].rgbtRed = 240;
    image[2][2].rgbtRed = 255;




    for (int i = 0; i < 1; i++)
    {
        for(int j = 0; j < 1; j++)
        {
            
            float avgb =  (((float) (image[i][j].rgbtBlue) + (image[i][j + 1].rgbtBlue) + (image[i][j+2].rgbtBlue) + (image[i+1][j].rgbtBlue) + (image[i+1][j + 1].rgbtBlue) + (image[i+1][j+2].rgbtBlue)
                                        + (image[i + 2][j].rgbtBlue) + (image[i + 2][j + 1].rgbtBlue) + (image[i + 2][j + 2].rgbtBlue)) / 9.0);
                                        
                                        
            //float avgg = round ((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j - 1].rgbtGreen + image[i+1][j+1].rgbtGreen
              //                          + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen)/9.0);
                                        
                                        
            //float avgr = round ((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j - 1].rgbtRed + image[i+1][j+1].rgbtRed
              //                          + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j + 1].rgbtRed)/9.0);
            int f = round (avgb);
            printf("avgb:%i", f);
        }
    }



    //,(40, 50, 60), (70, 80, 90)};

    return 0;

}
