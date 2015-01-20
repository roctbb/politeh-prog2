/**
Автор:          programina
Описание:       уменьшает точечный рисунок .bmp в два раза
Время:          11:01(моск. время) 27.05.2012
**/
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
 
#pragma pack(push,1)
typedef struct tagBITMAPFILEHEADER{
    unsigned short  bfType;
    unsigned long   bfSize;
    unsigned short  bfReserved1;
    unsigned short  bfReserved2;
    unsigned long   bfOffBits;
} BITMAPFILEHEADER;
#pragma pack(pop)
 
#pragma pack(push,2)
typedef struct tagBITMAPINFOHEADER{
    unsigned int    biSize;
    long        biWidth;
    long        biHeight;
    unsigned short  biPlanes;
    unsigned short  biBitCount;
    unsigned int    biCompression;
    unsigned int    biSizeImage;
    long        biXPelsPerMeter;
    long        biYPelsPerMeter;
    unsigned int    biClrUsed;
    unsigned int    biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)
 
 
struct PIXEL{
        unsigned char b;
        unsigned char g;
        unsigned char r;
};
 
int main()
{
    BITMAPFILEHEADER    headfirst;
    BITMAPINFOHEADER    headsecond;
    PIXEL                       pixel;
 
    FILE                    *fin, *fou;
 
    fin = fopen("test.bmp","rb+");
    fou = fopen("test2.bmp","wb+");
 
    fread( &headfirst, sizeof(BITMAPFILEHEADER), 1, fin );
    fread( &headsecond, sizeof(BITMAPINFOHEADER), 1, fin );

 
    fwrite( &headfirst, sizeof(BITMAPFILEHEADER), 1, fou );
    fwrite( &headsecond, sizeof(BITMAPINFOHEADER), 1, fou );
 
 
        for (int i = 0; i < headsecond.biHeight; i +=1)
        {
                for (int j = 0; j < headsecond.biWidth; j += 1)
                {
					    char a=0;
                        fread( &pixel.b, 1, 1, fin );
                        fread( &pixel.g, 1, 1, fin );
                        fread( &pixel.r, 1, 1, fin );
						printf("%d %d %d\n", (int)pixel.r, (int)pixel.g, (int)pixel.b);
                        fwrite( &pixel.b, 1, 1, fou );
                        fwrite( &a, 1, 1, fou );
                        fwrite( &a, 1, 1, fou );
                      
                }
                
        }
 
    fclose(fin);
    fclose(fou);
 
    system("pause");
    return 0;
}