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

		break;

	case 3:	realLength = 20;		// strong - mit allem


		break;

	default: password[0] = 0;
	}

	password[realLength] = 0;

	// Test: cout << password << "\n\n"; _getch();
}

int main()
{
	char test[30];
	int complexity = 0;
	int wtdo = 0;
	char network[30];
	char username[30];

	cout << "======================================";
	cout << "              PASSWORD MANAGER             ";
	cout << "======================================";


	cout << " neue Daten schreiben (1) | passwoerter anzeigen (2)"; cin >> wtdo;

	

		switch (wtdo)
		{
		case 1:
			cout << "Wo hast du dich registriert? \t"; cin >> network;
			cout << "gebe deinen nutzernamen ein \t"; cin >> username;
			cout << "wie komplex soll das Passwort sein? \t"; cin >> complexity;
			switch (complexity)
			{
			case 1:
				generatePassword(1, test);
				strcpy_s(test, _countof(test), test);


				fstream sw;
				sw.open("PwDatei.txt", ios::app);
				sw << network << "\n" << username << "\n" << test << "\n" "\n" "--------------------------------------------------------" << "\n";
				sw.close();

				cout << "\n\n";
				system("pause");
				break;
			}
		case 2:
			system("type PwDatei.txt");
			break;
		}

	

	


	

	

	
	return 0;
}
