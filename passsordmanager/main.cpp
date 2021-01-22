#include <iostream>	
#include <conio.h>
#include <dos.h>
#include <Windows.h>
#include <time.h>


using namespace std;



HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;


void gotoxy(int x, int y) {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void generatePassword() {
	int length;
	int complexity;

	do {
		cout << "Select Complexity" << endl;
		cout << "1 - weak | 2 - average | 3-strong" << endl;
		cin >> complexity;

		if (complexity == 1) {
			length = 8;
		}
		else if (complexity == 2) {
			length = 14;
		}
		else {
			length = 20;
		}

		char pass[21] = "";

		int i = 0;

	} while (true);

}

int main() {
	do {
		cout << endl << endl;
		cout << "=======================================" << endl;
		cout << "             PASSWORD MANAGER            " << endl;
		cout << "=======================================" << endl;

		generatePassword();

	} while (true);
}