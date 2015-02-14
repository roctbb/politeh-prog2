#include <string.h>
#include<stdio.h>
#include<iostream>
#include<complex>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
struct Wave
{
    char chunkId[4];				//"RIFF"
    unsigned long chunkSize;		//оставшейся размер цепочки
    char format[4];					//"WAVE"
    char subchunk1Id[4];			//"fmt "
    unsigned long subchunk1Size;	//16 Оставшей размер подцепочки
    unsigned short audioFormat;		//Аудиоформат. Стандартно 1
    unsigned short numChannels;		//количество каналов
    unsigned long sampleRate;		//частота дискретизации
    unsigned long byteRate;			//кол-во байт за секунду воспроизведения
    unsigned short blockAlign;		//кол-во байт для одного семпла
    unsigned short bitsPerSample;	//бит в семпле/глубина звука
    char subchunk2Id[6];			//"data"
    unsigned long subchunk2Size;	//кол-во байт в области данных
	
	int n;
    //vector < _int16 > samples;
	_int16 * samples;
	void read(std::string str)
	{

		FILE *f;
		f = fopen(str.c_str(), "rb");
        
		fread(&this->chunkId, sizeof(char), 4, f);
        fread(&this->chunkSize, sizeof(unsigned long), 1, f);
		fread(&this->format, sizeof(char), 4, f);
		fread(&this->subchunk1Id, sizeof(char), 4, f);
        fread(&this->subchunk1Size, sizeof(unsigned long), 1, f);
		fread(&this->audioFormat, sizeof(unsigned short), 1, f);
		fread(&this->numChannels, sizeof(unsigned short), 1, f);
		fread(&this->sampleRate, sizeof(unsigned long), 1, f);
		fread(&this->byteRate, sizeof(unsigned long), 1, f);
		fread(&this->blockAlign, sizeof(unsigned short), 1, f);
		fread(&this->bitsPerSample, sizeof(unsigned short), 1, f);
        fread(&this->subchunk2Id, sizeof(char), 6, f);
        fread(&this->subchunk2Size, sizeof(unsigned long), 1, f);

        this->n = (int)(this->subchunk2Size/this->numChannels*8/this->bitsPerSample);

		samples = new __int16[n];
        for (int i = 0; i < n; i++)
		{

            _int16 tmp = 0;
            fread(&tmp, 2 , 1, f);
            samples[i] = tmp;

        }

		fclose(f);
	}
	void write(std::string str)
	{

		FILE *f;
		f = fopen(str.c_str(), "wb");
        
        //cout<<"eee";
		fwrite(&this->chunkId, sizeof(char), 4, f);
        fwrite(&this->chunkSize, sizeof(unsigned long), 1, f);
		fwrite(&this->format, sizeof(char), 4, f);
		fwrite(&this->subchunk1Id, sizeof(char), 4, f);
        fwrite(&this->subchunk1Size, sizeof(unsigned long), 1, f);
		fwrite(&this->audioFormat, sizeof(unsigned short), 1, f);
		fwrite(&this->numChannels, sizeof(unsigned short), 1, f);
		fwrite(&this->sampleRate, sizeof(unsigned long), 1, f);
		fwrite(&this->byteRate, sizeof(unsigned long), 1, f);
		fwrite(&this->blockAlign, sizeof(unsigned short), 1, f);
		fwrite(&this->bitsPerSample, sizeof(unsigned short), 1, f);
        fwrite(&this->subchunk2Id, sizeof(char), 6, f);
        fwrite(&this->subchunk2Size, sizeof(unsigned long), 1, f);

        this->n = (int)(this->subchunk2Size/this->numChannels*8/this->bitsPerSample);

        for (int i = 0; i < n; i++)
		{
            _int16 tmp = samples[i];
            fwrite(&tmp, 2 , 1, f);
        }

		fclose(f);
	}
};
