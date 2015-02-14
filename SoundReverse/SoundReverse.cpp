// SoundReverse.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "wave.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Wave audio;
	Wave key;
	audio.read("C:\\Prog\\politeh-prog2\\SoundReverse\\test.wav");
	key.read("C:\\Prog\\politeh-prog2\\SoundReverse\\key.wav");
	/*for (int i=0; i<audio.n/2; i++)
	{
		_int16 tmp = 10*audio.samples[i];
		audio.samples[i] = 120*audio.samples[audio.n-i-1];
		audio.samples[audio.n-i-1]=tmp;
	}*/
	for (int i=0; i<audio.n; i++)
	{
		audio.samples[i]^=key.samples[i];
	}
	audio.write("C:\\Prog\\politeh-prog2\\SoundReverse\\test1.wav");
	
	return 0;
}

