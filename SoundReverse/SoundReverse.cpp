// SoundReverse.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "wave.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Wave audio;
	audio.read("C:\\Prog\\politeh-prog2\\SoundReverse\\test.wav");
	for (int i=0; i<audio.n/2; i++)
	{
		_int16 tmp = 10*audio.samples[i];
		audio.samples[i] = 10*audio.samples[audio.n-i-1];
		audio.samples[audio.n-i-1]=tmp;
	}
	audio.write("C:\\Prog\\politeh-prog2\\SoundReverse\\test.wav");
	
	return 0;
}

