/**
Автор:          programina
Описание:       уменьшает точечный рисунок .bmp в два раза
Время:          11:01(моск. время) 27.05.2012
**/
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)

struct BITMAPFILEHEADER{
    unsigned short  bfType;
    unsigned long   bfSize;
    unsigned short  bfReserved1;
    unsigned short  bfReserved2;
    unsigned long   bfOffBits;
};
#pragma pack(pop)
#pragma pack(push, 2)
struct BITMAPINFOHEADER{
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
} ;
#pragma pack(pop)

struct PIXEL{
        unsigned char b;
        unsigned char g;
        unsigned char r;
};
#pragma comment(linker, "/STACK:50000000")
struct BMPfile
{
	BITMAPFILEHEADER    headfirst;
    BITMAPINFOHEADER    headsecond;
	PIXEL image[1000][1000];
 
    FILE                    *fin, *fou;

	void read(const char * file)
	{
		fin = fopen(file,"rb+");
		fread( &headfirst, sizeof(BITMAPFILEHEADER), 1, fin );
		fread( &headsecond, sizeof(BITMAPINFOHEADER), 1, fin );
		fseek(fin, headfirst.bfOffBits, SEEK_SET);
		for (int i = 0; i < headsecond.biHeight; i +=1)
		{
			for (int j = 0; j < headsecond.biWidth; j += 1)
			{
			   
				fread( &image[i][j].b, 1, 1, fin );  
				fread( &image[i][j].g, 1, 1, fin );  
				fread( &image[i][j].r, 1, 1, fin ); 
			}
			for (int j=0; j<(4-headsecond.biWidth%4)%4; j++)
			{
				getc(fin);
			}
		 }

		fclose(fin);
	}
	void write(const char * file)
	{
		fou = fopen(file,"wb+");
		fwrite( &headfirst, sizeof(BITMAPFILEHEADER), 1, fou );
		fwrite( &headsecond, sizeof(BITMAPINFOHEADER), 1, fou );

		for (int i = 0; i < headsecond.biHeight; i +=1)
		{
			for (int j = 0; j < headsecond.biWidth; j += 1)
			{			
							fwrite( &image[i][j].b, 1, 1, fou );  
							fwrite( &image[i][j].g, 1, 1, fou );  
							fwrite( &image[i][j].r, 1, 1, fou );           
			}
			for (int j=0; j< (4-headsecond.biWidth%4)%4; j++)
			{
				char a = 1;
				fwrite( &a, 1, 1, fou );
			}
		
            
		}


		fclose(fou);
		}
};

int main()
{
	BMPfile myfile;
	myfile.read("test2.bmp");
	
	
	myfile.write("test3.bmp");
	 
    system("pause");
    return 0;
}