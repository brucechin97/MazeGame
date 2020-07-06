/****************************
* MazeGame
* Autor: Bruce Yuan Zhen Chin
* Darum: 13.06.2018
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Zweck: Spielfigur steuern und aus dem Labyrinth bringen
* Eingaben: Tastatursteuerung mit w, a, s & d
*****************************/

#include <iostream>
#include <ctime>	// fuer die Funktion sleep()
#include <conio.h>	// zum Benutzen der Befehle kbhit() und getch()
using namespace std;

void sleep(clock_t wait);
void ausgabe(unsigned char m[10][12]);
void stufe1();
void stufe2();
void bewegen(unsigned char Feld[10][12], int posX, int posY);

void main()		// main Funktion: ruft das Spiel Stufe 1 & Stufe 2 auf
{
	stufe1();
	sleep(5000);
	system("cls");
	stufe2();
	sleep(5000);
	system("cls");

	system("PAUSE");
}

void sleep(clock_t wait)	// pausiert für 'wait' Millisekunden
{
	clock_t goal;
	goal = wait + clock();
	while (goal > clock());
}

void ausgabe(unsigned char m[10][12])		// Ausgabe Funktion zur Ausgabe des Spielfeldes und Spielfigur
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout << m[i][j];
		}
		cout << endl;
	}
}

void stufe1()
{
	int posX = 0;		// Initialisierung der Position von der Spielfigur
	int posY = 8;
	unsigned char Feld[10][12] =	// Initialisierung des Spielfeldes mithilfe 2D Array
	{
		'#','#','#','#','#','#','#','#','#','#','#','#',
		'#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',
		'#',' ','#',' ',' ',' ','#','#','#','#','#','#',
		'#',' ','#','#','#','#','#',' ','#',' ',' ','#',
		'#',' ',' ',' ',' ',' ','#',' ','#','#',' ','#',
		'#',' ','#',' ','#',' ','#',' ',' ','#',' ','#',
		'#',' ','#',' ','#',' ','#','#',' ',' ',' ','#',
		'#','#','#',' ','#','#','#','#','#','#',' ','#',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#','#','#','#','#','#','#','#','#','#','#','#'
	};

	cout << "\nWillkommen zum Labyrinthspiel!\n\n";		// Begruessung und Anleitung fuer das Spiel
	sleep(3000);		// wartet 3 Sekunden
	system("cls");		// (clear screen) Alle Ausgabe loeschen
	cout << "\n\n***STUFE 1***";		// Stufe 1
	sleep(3000);
	system("cls");
	cout << "Hilfe! Hilfe!\n";			// Hintergrundgeschichte macht das Spiel mehr "user-friendly"
	sleep(2000);
	cout << "Die arme Schnecke hat sich in einem Garten verirrt!\n";
	sleep(2000);
	cout << "Helfen Sie ihr, um aus dem Garten zu entkommen.\n\n";
	sleep(2000);
	cout << "Tastatursteuerung:\nw: hoch\ns: runter\na: links\nd: rechts\n\n";
	sleep(5000);
	cout << "Das Spiel beginnt in...3";		// Kurze countdown vor dem Spielbeginn
	sleep(1000);
	cout << "\rDas Spiel beginnt in...2";
	sleep(1000);
	cout << "\rDas Spiel beginnt in...1";
	sleep(1000);
	system("cls");

	Feld[posY][posX] = '@';		// Initialisieren der Spielfigur
	ausgabe(Feld);

	while (Feld[1][11] != '@')	// Schleife wiederholt sich bis die Spielfigur das Ziel erreicht
	{
		if (_kbhit())	// prüft, ob der Benutzer eine Taste gedrückt hat
		{
			char strg = _getch();	// getch() liest das eingegebene Zeichen, ohne dass es auf der Konsole ausgegeben wird
			switch (strg)
			{
			case 'w':	// Spielfigur nach oben bewegen
				if (Feld[posY - 1][posX] != '#')		// Spielfigur bewegt ein Schritt nach oben, wenn das Feld daoben nicht '#' ist
				{
					Feld[posY][posX] = ' ';			
					posY--;
					Feld[posY][posX] = '@';
				}

				else
				{
					cout << "Nicht durch die Wand gehen!!";		// sonst wird eine Fehlermeldung ausgegeben, dass der Zug nicht geht
					sleep(500);
				}
				break;

			case 'd':		// Spielfigur nach rechts bewegen
				if (Feld[posY][posX + 1] != '#')
				{
					Feld[posY][posX] = ' ';
					posX++;
					Feld[posY][posX] = '@';
				}

				else
				{
					cout << "Nicht durch die Wand gehen!!";
					sleep(500);
				}
				break;

			case 's':		// Spielfigur nach unten bewegen
				if (Feld[posY + 1][posX] != '#')
				{
					Feld[posY][posX] = ' ';
					posY++;
					Feld[posY][posX] = '@';
				}

				else
				{
					cout << "Nicht durch die Wand gehen!!";
					sleep(500);
				}
				break;

			case 'a':		// Spielfigur nach links bewegen
				if (Feld[posY][posX - 1] != '#')
				{
					Feld[posY][posX] = ' ';
					posX--;
					Feld[posY][posX] = '@';
				}

				else
				{
					cout << "Nicht durch die Wand gehen!!";
					sleep(500);
				}
				break;
			}

			system("cls");		// Bildschirm loeschen und aktuelles Spielfeld ausgeben
			ausgabe(Feld);
		}

	}

	cout << "\n*****GEWONNEN!*****\n**Herzlichen Glueckwunsch!**\n";
}

void stufe2()
{
	int posX = 0;		// Initialisierung der Position von der Spielfigur
	int posY = 8;
	int wert = 0;
	unsigned char Feld[10][12] =	// Initialisierung des Spielfeldes mithilfe 2D Array
	{
		'#','#','#','#','#','#','#','#','#','#','#','#',
		'#',' ',' ',' ','#','o','#',' ',' ',' ',' ',' ',
		'#',' ','#',' ',' ',' ','#',' ','#','#','#','#',
		'#',' ','#','#','#','#','#',' ','#','o',' ','#',
		'#',' ',' ',' ',' ',' ','#',' ','#','#',' ','#',
		'#',' ','#',' ','#',' ','#',' ',' ','#',' ','#',
		'#','o','#',' ','#','o','#','#',' ',' ',' ','#',
		'#','#','#',' ','#','#','#','#','#','#',' ','#',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#','#','#','#','#','#','#','#','#','#','#','#'
	};

	cout << "\n\n***STUFE 2***";
	sleep(3000);
	system("cls");
	cout << "Hilfe!\n";			// Hintergrundgeschichte macht das Spiel mehr "user-friendly"
	sleep(2000);
	cout << "Die arme Schnecke hat sich beim Essen suchen nochmal in dem Garten \nverirrt...\n\n";
	sleep(3000);
	cout << "Helfen Sie ihr, um Essen zu sammeln und dann aus dem Garten \nzu entkommen.\n\n";
	sleep(3000);
	cout << "Tastatursteuerung:\nw: hoch\ns: runter\na: links\nd: rechts\n\n";
	sleep(5000);
	cout << "Das Spiel beginnt in...3";		// Kurze countdown vor dem Spielbeginn
	sleep(1000);
	cout << "\rDas Spiel beginnt in...2";
	sleep(1000);
	cout << "\rDas Spiel beginnt in...1";
	sleep(1000);
	system("cls");

	Feld[posY][posX] = '@';		// Initialisieren der Spielfigur
	ausgabe(Feld);

	while (wert != 4)	// Schleife wiederholt sich bis alle Essen gesammelt wird, hier wenn wert==4
	{
		if (_kbhit())
		{
			char strg = _getch();
			switch (strg)
			{
			case 'w':
				if (Feld[posY - 1][posX] != '#')
				{
					if (Feld[posY - 1][posX] == 'o')
						wert++;			// weist darauf hin, dass der Spieler ein Essen gesamelt hat

					Feld[posY][posX] = ' ';
					posY--;
					Feld[posY][posX] = '@';
				}

				else
				{
					cout << "Nicht durch die Wand gehen!!";
					sleep(500);
				}
				break;

			case 'd':
				if (Feld[posY][posX + 1] != '#')
				{
					if (Feld[posY][posX + 1] == 'o')
						wert++;			// weist darauf hin, dass der Spieler ein Essen gesamelt hat

					Feld[posY][posX] = ' ';
					posX++;
					Feld[posY][posX] = '@';
				}

				else
				{
					cout << "Nicht durch die Wand gehen!!";
					sleep(500);
				}
				break;

			case 's':
				if (Feld[posY + 1][posX] != '#')
				{
					if (Feld[posY + 1][posX] == 'o')
						wert++;			// weist darauf hin, dass der Spieler ein Essen gesamelt hat

					Feld[posY][posX] = ' ';
					posY++;
					Feld[posY][posX] = '@';
				}

				else
				{
					cout << "Nicht durch die Wand gehen!!";
					sleep(500);
				}
				break;

			case 'a':
				if (Feld[posY][posX - 1] != '#')
				{
					if (Feld[posY][posX-1] == 'o')
						wert++;			// weist darauf hin, dass der Spieler ein Essen gesamelt hat

					Feld[posY][posX] = ' ';
					posX--;
					Feld[posY][posX] = '@';
				}

				else
				{
					cout << "Nicht durch die Wand gehen!!";
					sleep(500);
				}
				break;
			}

			system("cls");		// Bildschirm loeschen und aktuelles Spielfeld ausgeben
			ausgabe(Feld);
			cout << "\nGesammeltes Essen: " << wert << endl;
		}

	}

	bewegen(Feld, posX, posY);		

	cout << "\n*****GEWONNEN!*****\n**Herzlichen Glueckwunsch!**\n";
}

void bewegen(unsigned char Feld[10][12], int posX, int posY)
{

	while (Feld[1][11] != '@')	// Schleife wiederholt sich bis die Spielfigur das Ziel erreicht
	{
		if (_kbhit())
		{
			char strg = _getch();
			switch (strg)
			{
			case 'w':
				if (Feld[posY - 1][posX] != '#')
				{
					Feld[posY][posX] = ' ';
					posY--;
					Feld[posY][posX] = '@';
				}

				else
				{
					cout << "Nicht durch die Wand gehen!!";
					sleep(500);
				}
				break;

			case 'd':
				if (Feld[posY][posX + 1] != '#')
				{
					Feld[posY][posX] = ' ';
					posX++;
					Feld[posY][posX] = '@';
				}

				else
				{
					cout << "Nicht durch die Wand gehen!!";
					sleep(500);
				}
				break;

			case 's':
				if (Feld[posY + 1][posX] != '#')
				{
					Feld[posY][posX] = ' ';
					posY++;
					Feld[posY][posX] = '@';
				}

				else
				{
					cout << "Nicht durch die Wand gehen!!";
					sleep(500);
				}
				break;

			case 'a':
				if (Feld[posY][posX - 1] != '#')
				{
					Feld[posY][posX] = ' ';
					posX--;
					Feld[posY][posX] = '@';
				}

				else
				{
					cout << "Nicht durch die Wand gehen!!";
					sleep(500);
				}
				break;
			}

			system("cls");		// Bildschirm loeschen und aktuelles Spielfeld ausgeben
			ausgabe(Feld);
			cout << "\nGesammeltes Essen: 4" << endl;
		}

	}
};