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


	cout << "Select Complexity" << endl;
	cout << "1 - weak (ohne Grossbuchstaben und Sonderzeichen) | 2 - average (ohne Sonderzeichen)| 3-strong" << endl;
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

		for (i = 0; i < length; i++) {
			if (complexity == 1) { 
				if (rand() % 2 == 1) {//buchstaben
					pass[i] = 97 + rand() % 26;  //erstelle das random Passwort und weise es dem char string zu
				}
				else {
					pass[i] = 48 + rand() % 10; //zahlen
				}
					
			}
				
			


			else if (complexity == 2) {
				if (rand() % 3 == 1) {
					pass[i] = 97 + rand() % 26;
				}
				else if (rand() % 3 == 2) {
					pass[i] = 65 + rand() % 26;
				}
				else {
					pass[i] = 48 + rand() % 10;
				}
			
			}

			else if (complexity == 3) {
				if (rand() % 4 == 1) {
					pass[i] = 97 + rand() % 26;
				}
				else if (rand() % 4 == 2) {
					pass[i] = 65 + rand() % 26;
				}
				else if (rand() % 4 == 3) {
					pass[i] = 33 + rand() % 15;
				}
				else {
					pass[i] = 48 + rand() % 10;
				}
				
			}
		} 
		pass[i] = '\0';
		system("cls");
		gotoxy(11, 8); cout << pass;
	

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