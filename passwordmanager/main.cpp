#include <iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
using namespace std;

void generatePassword(int, char*);

void generatePassword(int complexity, char* password)
{
	int realLength;
	int i;

	time_t t;
	srand((unsigned)&t);

	password[0] = 0;

	switch (complexity)
	{
	case 1:	realLength = 8;			// weak - ohne Groﬂbuchstaben und Sonderzeichen 

		for (i = 0; i < 8; i++)
		{
			if (rand() % 2)			// Ziffer (1=true) oder Kleinbuchstabe (0=false)?
			{
				password[i] = 48 + rand() % 10;		// Ziffern ASCII 48 bis 57 
			}
			else
			{
				password[i] = 97 + rand() % 26;		// Kleinbuchstaben ASCII 97 bis 122 
			}
		}

		break;

	case 2:	realLength = 14;		// avarage - ohne Sonderzeichen

		for (i = 0; i < 14; i++)
		{
			if (rand() % 3 == 1) {
				password[i] = 97 + rand() % 26;
			}
			else if (rand() % 3 == 2) {
				password[i] = 65 + rand() % 26;
			}
			else {
				password[i] = 48 + rand() % 10;
			}
		}
		
		
		break;

	case 3:	realLength = 20;		// strong - mit allem

		for (i = 0; i < 20; i++) {
			if (rand() % 4 == 1) {
				password[i] = 97 + rand() % 26;
			}
			else if (rand() % 4 == 2) {
				password[i] = 65 + rand() % 26;
			}
			else if (rand() % 4 == 3) {
				password[i] = 33 + rand() % 15;
			}
			else {
				password[i] = 48 + rand() % 10;
			}
		}
		
		break;

	default: password[0] = 0;
	}

	password[realLength] = 0;

	// Test: cout << password << "\n\n"; _getch();
}



void checkPassord(char* password) {

	int length = strlen(password); //länge des char strings
	//cout << length;

	int bonusCombo = 0;

	int numSym = 0; //Anzahl der Symbole
	int numUp = 0; //Anzhal der Großbuchstaben
	int numNumbers = 0; //Anzahl der Nummern
	int numLower = 0; //Anzahl der Kleinbuchstaben

	for (int i = 0; i < strlen(password);i++) {
		if (password[i] >= 48 && password[i] <= 57) { //0 -9
			numNumbers++;
		}
		if (password[i] >= 97 && password[i] <= 125) { //a-z
			numLower++;
		}
		if (password[i] >= 65 && password[i] <= 90) { //A-Z
			numUp++;
		}
		if (password[i] >= 33 && password[i] <= 47) { //symbols
			numSym++;
		}
	}

	//cout << numNumbers;


	if (numUp > 0 && numNumbers > 0 && numSym > 0) {
		bonusCombo = 25; //alle 3 Kriterien sind erfüllt
	}


	else if (numUp > 0 && numNumbers > 0 || numSym > 0 && numUp > 0) {
		bonusCombo = 15; // zwei Kriterien sind erfüllt
	}


	int score = bonusCombo + strlen(password);

	if (score >= 30) {
		cout << "strong password";
	}
	else if (score > 20 && score < 30) {
		cout << "medium password";
	}
	else if (score <= 20) {
		cout << "weak password";
	}
	


}

int main()
{
	char test[30];
	int complexity = 0;
	int wtdo = 0;
	char network[30];
	char username[30];

	while (wtdo != 3) {

	cout << "======================================";
	cout << "              PASSWORD MANAGER        ";
	cout << "======================================";

	
		cout << " neue Daten schreiben (1) | passwoerter anzeigen (2) | Programm beenden (3) | Passwort Strength Checker (4)"; cin >> wtdo;



		switch (wtdo)
		{
		case 1:
			cout << "Wo hast du dich registriert? \t"; cin >> network;
			cout << "gebe deinen nutzernamen ein \t"; cin >> username;
			cout << "wie komplex soll das Passwort sein? \t"; cin >> complexity;
			if (complexity == 1) {
				generatePassword(1, test);
				strcpy_s(test, _countof(test), test);


				fstream sw;
				sw.open("PwDatei.txt", ios::app);
				sw << network << "\n" << username << "\n" << test << "\n" "\n" "--------------------------------------------------------" << "\n";
				sw.close();

				cout << "\n\n";
				system("pause");
			}
			else if (complexity == 2) {
				generatePassword(2, test);
				strcpy_s(test, _countof(test), test);


				fstream sw;
				sw.open("PwDatei.txt", ios::app);
				sw << network << "\n" << username << "\n" << test << "\n" "\n" "--------------------------------------------------------" << "\n";
				sw.close();

				cout << "\n\n";
				system("pause");
			}
			else if (complexity == 3) {
				generatePassword(3, test);
				strcpy_s(test, _countof(test), test);


				fstream sw;
				sw.open("PwDatei.txt", ios::app);
				sw << network << "\n" << username << "\n" << test << "\n" "\n" "--------------------------------------------------------" << "\n";
				sw.close();

				cout << "\n\n";
				system("pause");
			}
		case 2:
			system("type PwDatei.txt");
			break;

		case 4:
			char password[30];
			cin >> password;
			checkPassord(password);
			break;
		
		}

	}


	
	

	


	

	

	
	return 0;
}
