// SoundReverse.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "wave.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Wave audio;
	
	audio.read("Z:\\politeh-prog2\\SoundReverse\\task1.wav");
	//audio.samples - ������ �������
	//audio.n - ������ ����� �������
	audio.write("Z:\\politeh-prog2\\SoundReverse\\answer2.wav");
	
	return 0;
}

