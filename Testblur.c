#include <stdio.h>
#include <math.h>
#include <stdint.h>

typedef struct
{
    uint8_t rgbtBlue;
    uint8_t rgbtGreen;
    uint8_t rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;

int main (void)
{
    RGBTRIPLE temp[100][100];
 
 for (int i = 0; i < 100; i++)
 {
     for(int j = 0; j < 100; j++)
     {
         temp[i][j].rgbtBlue = 0;
         temp[i][j].rgbtGreen = 0;
         temp[i][j].rgbtRed = 0;
     }
 }
 
 
  for (int i = 0; i < 100; i++)
 {
     for(int j = 0; j < 100; j++)
     {
         printf("blue = %i",temp[i][j].rgbtBlue);
         printf("Green = %i",temp[i][j].rgbtGreen);
         printf("Red = %i\n",temp[i][j].rgbtRed);
     }
 }
 
 
 return 0;
    
}