#include<iostream>
#include<conio.h>
#include<string>
#include<windows.h>
#include <stdlib.h>
#include <cstdlib>
#include<time.h>
#include<fstream>

// Azfar Nayyan @GIT HUB. 
using namespace std;

HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
POINT XY;
const int row = 9, coloum = 9, selec = 20;
int usergrid[row][coloum] = { 0 };  //The grid played by user. //Prints new game every time.
const int up = 72, down = 80, lft = 75, rght = 77;
int	xrr[9] = { 3,7,11,17,21,25,31,35,39 };
int yrr[9] = { 4,6,8,11,13,15,18,20,22 };
int selectedx[selec], selectedy[selec], selectednum[selec];
int savex[9][9] = { 0 }, savey[9][9] = { 0 };
int indexx, indexy;
int grid[row][coloum] = { {3, 1, 6, 5, 7, 8, 4 ,9, 2 },
	{5, 2, 9, 1, 3, 4, 7, 6, 8},
	{4 ,8 ,7 ,6 ,2 ,9 ,5 ,3 ,1},
	{2 ,6 ,3 ,4 ,1 ,5 ,9 ,8 ,7},
	{9 ,7, 4, 8, 6, 3, 1, 2, 5},
	{8 ,5 ,1 ,7, 9, 2, 6, 4, 3},
	{1, 3, 8, 9, 4, 7, 2, 5, 6},
	{6 ,9, 2, 3, 5 ,1 ,8, 7, 4},
	{7, 4, 5, 2, 8, 6, 3, 1, 9}
};


void setCord(int x, int y);
int mainmenu();
void sudokugrid();
void sudoku();
bool boundaryCheck(int a, int& x, int& y);
bool Rowsearch(int val, int x, int y);
bool Coloumsearch(int val, int x, int y);
bool boxsearch(int val, int x, int y);
void puzzleset();
void selectrandomcoor();
void printrandomcoor();
bool coordinatesearch(int x, int y);
bool wingame();
int escapemenu();
void realtimesave();
int loadsavegame();
int savegame();
bool savedgames(int a);
void saveAgame(int a);





int main()
{

label5:	int option = mainmenu();
	if (option == 2)
	{
		puzzleset();
		selectrandomcoor();
		sudokugrid();
		sudoku();

	}
	if (option == 3)
	{
		int b = loadsavegame();
		if (b == 2)
		{
			bool n = savedgames(b);
			if (n == false)
			{
				SetConsoleTextAttribute(a, 8);
				cout << "NO SAVED GAME EXISTS. SAVE FIRST." << endl;
				cout << "(Wait for 2 seconds.)" << endl;
				Sleep(2000);
				system("CLS");
				goto label5;
			}
			sudokugrid();
			realtimesave();
			sudoku();
		}
		if (b == 3)
		{
			bool n = savedgames(b);
			if (n == false)
			{
				SetConsoleTextAttribute(a, 8);
				cout << "NO SAVED GAME EXISTS. SAVE FIRST." << endl;
				cout << "(Wait for 2 seconds.)" << endl;
				Sleep(2000);
				system("CLS");
				goto label5;
			}
			sudokugrid();
			realtimesave();
			sudoku();
		}
		if (b == 4)
		{
			bool n = savedgames(b);
			if (n == false)
			{
				SetConsoleTextAttribute(a, 8);
				cout << "NO SAVED GAME EXISTS. SAVE FIRST." << endl;
				cout << "(Wait for 2 seconds.)" << endl;
				Sleep(2000);
				system("CLS");
				goto label5;
			}
			sudokugrid();
			realtimesave();
			sudoku();
		}
		if (b == -1)
		{
			goto label5;
		}
	}
	if (option == 4)
	{
		return 0;
	}




	system("pause>0");
	return 0;

}





void setCord(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


int mainmenu()
{
	SetConsoleTextAttribute(a, 5);
	cout << "**************** SUDOKU ********************" << endl << endl;
	SetConsoleTextAttribute(a, 8);
	cout << " (1) Start a new game." << endl;
	cout << " (2) Load a previous game." << endl;
	cout << " (3) Quit the game." << endl << endl;
	SetConsoleTextAttribute(a, 4);
	cout << "-------------------------------------" << endl;
	cout << "use up/down keys to toggle throw menu." << endl;
	cout << "press enter to access." << endl;

	bool flag = true;
	int c = 2, val, y;
	char key;

	setCord(0, c);
	SetConsoleTextAttribute(a, 9);
	cout << " (1) Start a new game." << endl;
	setCord(0, c);


	do {
		key = _getch();
		val = key;
		if (val == 72)
		{
			if (c == 2)
			{
				continue;
			}
			setCord(0, --c);
			if (c == 2)
			{
				SetConsoleTextAttribute(a, 9);
				cout << " (1) Start a new game." << endl;
				SetConsoleTextAttribute(a, 8);
				cout << " (2) Load a previous game." << endl;
				cout << " (3) Quit the game." << endl;
				setCord(0, c);

			}
			if (c == 3)
			{
				SetConsoleTextAttribute(a, 9);
				cout << " (2) Load a previous game." << endl;
				setCord(0, c - 1);
				SetConsoleTextAttribute(a, 8);
				cout << " (1) Start a new game." << endl;
				setCord(0, c + 1);
				SetConsoleTextAttribute(a, 8);
				cout << " (3) Quit the game." << endl;
				setCord(0, c);
			}
			if (c == 4)
			{
				SetConsoleTextAttribute(a, 9);
				cout << " (3) Quit the game." << endl;
				setCord(0, c - 2);
				SetConsoleTextAttribute(a, 8);
				cout << " (1) Start a new game." << endl;
				cout << " (2) Load a previous game." << endl;
				setCord(0, c);

			}
		}
		if (val == 80)
		{
			if (c == 4)
			{
				continue;
			}
			setCord(0, ++c);
			if (c == 2)
			{
				SetConsoleTextAttribute(a, 9);
				cout << " (1) Start a new game." << endl;
				SetConsoleTextAttribute(a, 8);
				cout << " (2) Load a previous game." << endl;
				cout << " (3) Quit the game." << endl;
				setCord(0, c);
			}
			if (c == 3)
			{
				SetConsoleTextAttribute(a, 9);
				cout << " (2) Load a previous game." << endl;
				setCord(0, c - 1);
				SetConsoleTextAttribute(a, 8);
				cout << " (1) Start a new game." << endl;
				setCord(0, c + 1);
				SetConsoleTextAttribute(a, 8);
				cout << " (3) Quit the game." << endl;
				setCord(0, c);
			}
			if (c == 4)
			{
				SetConsoleTextAttribute(a, 9);
				cout << " (3) Quit the game." << endl;
				setCord(0, c - 2);
				SetConsoleTextAttribute(a, 8);
				cout << " (1) Start a new game." << endl;
				cout << " (2) Load a previous game." << endl;
				setCord(0, c);
			}
		}
		if (val == 13)
		{
			flag = false;
			break;
		}

	} while (flag == true);

	system("CLS");
	return c;
}

void sudokugrid()
{
	SetConsoleTextAttribute(a, 6);
	cout << "_______________________________________";
	SetConsoleTextAttribute(a, 4);
	cout << " SUDOKU ";
	SetConsoleTextAttribute(a, 6);
	cout << "__________________________________________" << endl;
	cout << "_________________________________________________________________________________________" << endl << "Azfar Nayyan @Git Hub." << endl;


	for (int g = 1; g <= 3; g++)
	{
		SetConsoleTextAttribute(a, 5);
		for (int i = 1; i <= 43; i++)
		{
			cout << "#";
		}
		cout << endl;

		for (int x = 1; x <= 3; x++)
		{
			for (int k = 1; k <= 3; k++)
			{
				cout << "#";
				for (int j = 1; j <= 3; j++)
				{
					cout << "|   ";
				}
				cout << "|";
			}
			cout << "#" << endl;
			for (int y = 1; y <= 3; y++)
			{
				cout << "#|";
				for (int a = 1; a <= 3; a++)
				{
					if (a == 3)
					{
						cout << "---|";
						break;
					}
					cout << "---*";
				}
			}
			cout << "#" << endl;
		}
	}
	for (int i = 1; i <= 43; i++)
	{
		cout << "#";
	}
	cout << endl << endl;

	setCord(45, 3);
	SetConsoleTextAttribute(a, 3);
	for (int i = 1; i <= 43; i++)
	{
		cout << "_";
	}
	setCord(45, 4);
	cout << "USE UP/DOWN/LEFT/RIGHT KEYS TO PLAY.";
	setCord(45, 5);
	cout << "PRESS [ESC] TO PAUSE.";
	setCord(45, 6);
	for (int i = 1; i <= 43; i++)
	{
		cout << "_";
	}
	setCord(45, 7);
	cout << "* - Coloured numbers are fixed.";

	setCord(0, 26);
	SetConsoleTextAttribute(a, 6);
	cout << "_________________________________________________________________________________________" << endl << endl;

	SetConsoleTextAttribute(a, 2);
	printrandomcoor();

}


void sudoku()
{

	bool flag1 = true;
	char key1;
	int val1, x = 3, y = 4;

	int v = 0;
	for (int i = 0; i <= 19; i++)
	{
		if (x == selectedx[i] && y == selectedy[i])
		{
			x = xrr[v + 1];
			y = yrr[v + 1];
			v++;
		}
	}

	setCord(x, y);

	do {
		key1 = _getch();
		val1 = key1;


	label1:	if (val1 == up)
	{
		bool check = boundaryCheck(val1, x, y);

		if (check == false)
			continue;
		else if (check == true)
		{
			y -= 2;
			bool q = coordinatesearch(x, y);
			if (q == true)
			{
				setCord(x, y);
				continue;
			}
			else
			{
				goto label1;
			}

		}
	}
label2:	if (val1 == down)
{
	bool check = boundaryCheck(val1, x, y);
	if (check == false)
		continue;
	else if (check == true)
	{
		y += 2;
		bool q = coordinatesearch(x, y);
		if (q == true)
		{
			setCord(x, y);
			continue;
		}
		else
		{
			goto label2;
		}
	}
}
label3:	if (val1 == lft)
{
	bool check = boundaryCheck(val1, x, y);
	if (check == false)
		continue;
	else if (check == true)
	{
		x -= 4;
		bool q = coordinatesearch(x, y);
		if (q == true)
		{
			setCord(x, y);
			continue;
		}
		else
		{
			goto label3;
		}
	}
}
label4:	if (val1 == rght)
{
	bool check = boundaryCheck(val1, x, y);
	if (check == false)
		continue;
	if (check == true)
	{
		x += 4;
		bool q = coordinatesearch(x, y);
		if (q == true)
		{
			setCord(x, y);
			continue;
		}
		else
		{
			goto label4;
		}

	}
}
if (val1 == 49)
{
	for (int i = 0; i < 9; i++)
	{
		if (x == xrr[i])
		{
			indexx = i;
		}
	}
	for (int j = 0; j < 9; j++)
	{
		if (y == yrr[j])
		{
			indexy = j;
		}
	}

	int temp = indexx;
	indexx = indexy;
	indexy = temp;

	bool v = Rowsearch(1, indexx, indexy);
	bool b = Coloumsearch(1, indexx, indexy);
	bool c = boxsearch(1, indexx, indexy);

	if (v == true && b == true && c == true)
	{
		usergrid[indexx][indexy] = 1;
		savex[indexx][indexy] = x;
		savey[indexx][indexy] = y;
		SetConsoleTextAttribute(a, 2);
		cout << "1";
	}
	else
	{
		SetConsoleTextAttribute(a, 4);
		usergrid[indexx][indexy] = 0;
		savex[indexx][indexy] = 0;
		savey[indexx][indexy] = 0;
		cout << "1";
		setCord(x, y);
		Sleep(500);
		cout << " ";
	}
	setCord(x, y);
}
if (val1 == 50)
{
	for (int i = 0; i < 9; i++)
	{
		if (x == xrr[i])
		{
			indexx = i;
		}
	}
	for (int j = 0; j < 9; j++)
	{
		if (y == yrr[j])
		{
			indexy = j;
		}
	}

	int temp = indexx;
	indexx = indexy;
	indexy = temp;

	bool v = Rowsearch(2, indexx, indexy);
	bool b = Coloumsearch(2, indexx, indexy);
	bool c = boxsearch(2, indexx, indexy);

	if (v == true && b == true && c == true)
	{
		usergrid[indexx][indexy] = 2;
		savex[indexx][indexy] = x;
		savey[indexx][indexy] = y;
		SetConsoleTextAttribute(a, 2);
		cout << "2";
	}
	else
	{
		SetConsoleTextAttribute(a, 4);
		usergrid[indexx][indexy] = 0;
		savex[indexx][indexy] = 0;
		savey[indexx][indexy] = 0;
		cout << "2";
		setCord(x, y);
		Sleep(500);
		cout << " ";
	}
	setCord(x, y);
}
if (val1 == 51)
{
	for (int i = 0; i < 9; i++)
	{
		if (x == xrr[i])
		{
			indexx = i;
		}
	}
	for (int j = 0; j < 9; j++)
	{
		if (y == yrr[j])
		{
			indexy = j;
		}
	}

	int temp = indexx;
	indexx = indexy;
	indexy = temp;

	bool v = Rowsearch(3, indexx, indexy);
	bool b = Coloumsearch(3, indexx, indexy);
	bool c = boxsearch(3, indexx, indexy);

	if (v == true && b == true && c == true)
	{
		usergrid[indexx][indexy] = 3;
		savex[indexx][indexy] = x;
		savey[indexx][indexy] = y;
		SetConsoleTextAttribute(a, 2);
		cout << "3";
	}
	else
	{
		SetConsoleTextAttribute(a, 4);
		usergrid[indexx][indexy] = 0;
		savex[indexx][indexy] = 0;
		savey[indexx][indexy] = 0;
		cout << "3";
		setCord(x, y);
		Sleep(500);
		cout << " ";
	}
	setCord(x, y);
}
if (val1 == 52)
{
	for (int i = 0; i < 9; i++)
	{
		if (x == xrr[i])
		{
			indexx = i;
		}
	}
	for (int j = 0; j < 9; j++)
	{
		if (y == yrr[j])
		{
			indexy = j;
		}
	}

	int temp = indexx;
	indexx = indexy;
	indexy = temp;

	bool v = Rowsearch(4, indexx, indexy);
	bool b = Coloumsearch(4, indexx, indexy);
	bool c = boxsearch(4, indexx, indexy);

	if (v == true && b == true && c == true)
	{
		usergrid[indexx][indexy] = 4;
		savex[indexx][indexy] = x;
		savey[indexx][indexy] = y;
		SetConsoleTextAttribute(a, 2);
		cout << "4";
	}
	else
	{
		SetConsoleTextAttribute(a, 4);
		usergrid[indexx][indexy] = 0;
		savex[indexx][indexy] = 0;
		savey[indexx][indexy] = 0;
		cout << "4";
		setCord(x, y);
		Sleep(500);
		cout << " ";
	}
	setCord(x, y);
}
if (val1 == 53)
{
	for (int i = 0; i < 9; i++)
	{
		if (x == xrr[i])
		{
			indexx = i;
		}
	}
	for (int j = 0; j < 9; j++)
	{
		if (y == yrr[j])
		{
			indexy = j;
		}
	}

	int temp = indexx;
	indexx = indexy;
	indexy = temp;

	bool v = Rowsearch(5, indexx, indexy);
	bool b = Coloumsearch(5, indexx, indexy);
	bool c = boxsearch(5, indexx, indexy);

	if (v == true && b == true && c == true)
	{
		usergrid[indexx][indexy] = 5;
		savex[indexx][indexy] = x;
		savey[indexx][indexy] = y;
		SetConsoleTextAttribute(a, 2);
		cout << "5";
	}
	else
	{
		SetConsoleTextAttribute(a, 4);
		usergrid[indexx][indexy] = 0;
		savex[indexx][indexy] = 0;
		savey[indexx][indexy] = 0;
		cout << "5";
		setCord(x, y);
		Sleep(500);
		cout << " ";
	}
	setCord(x, y);

}
if (val1 == 54)
{
	for (int i = 0; i < 9; i++)
	{
		if (x == xrr[i])
		{
			indexx = i;
		}
	}
	for (int j = 0; j < 9; j++)
	{
		if (y == yrr[j])
		{
			indexy = j;
		}
	}

	int temp = indexx;
	indexx = indexy;
	indexy = temp;

	bool v = Rowsearch(6, indexx, indexy);
	bool b = Coloumsearch(6, indexx, indexy);
	bool c = boxsearch(6, indexx, indexy);

	if (v == true && b == true && c == true)
	{
		usergrid[indexx][indexy] = 6;
		savex[indexx][indexy] = x;
		savey[indexx][indexy] = y;
		SetConsoleTextAttribute(a, 2);
		cout << "6";
	}
	else
	{
		SetConsoleTextAttribute(a, 4);
		usergrid[indexx][indexy] = 0;
		savex[indexx][indexy] = 0;
		savey[indexx][indexy] = 0;
		cout << "6";
		setCord(x, y);
		Sleep(500);
		cout << " ";
	}
	setCord(x, y);
}
if (val1 == 55)
{
	for (int i = 0; i < 9; i++)
	{
		if (x == xrr[i])
		{
			indexx = i;
		}
	}
	for (int j = 0; j < 9; j++)
	{
		if (y == yrr[j])
		{
			indexy = j;
		}
	}

	int temp = indexx;
	indexx = indexy;
	indexy = temp;

	bool v = Rowsearch(7, indexx, indexy);
	bool b = Coloumsearch(7, indexx, indexy);
	bool c = boxsearch(7, indexx, indexy);

	if (v == true && b == true && c == true)
	{
		usergrid[indexx][indexy] = 7;
		savex[indexx][indexy] = x;
		savey[indexx][indexy] = y;
		SetConsoleTextAttribute(a, 2);
		cout << "7";
	}
	else
	{
		SetConsoleTextAttribute(a, 4);
		usergrid[indexx][indexy] = 0;
		savex[indexx][indexy] = 0;
		savey[indexx][indexy] = 0;
		cout << "7";
		setCord(x, y);
		Sleep(500);
		cout << " ";
	}
	setCord(x, y);
}
if (val1 == 56)
{
	for (int i = 0; i < 9; i++)
	{
		if (x == xrr[i])
		{
			indexx = i;
		}
	}
	for (int j = 0; j < 9; j++)
	{
		if (y == yrr[j])
		{
			indexy = j;
		}
	}

	int temp = indexx;
	indexx = indexy;
	indexy = temp;


	bool v = Rowsearch(8, indexx, indexy);
	bool b = Coloumsearch(8, indexx, indexy);
	bool c = boxsearch(8, indexx, indexy);

	if (v == true && b == true && c == true)
	{
		usergrid[indexx][indexy] = 8;
		savex[indexx][indexy] = x;
		savey[indexx][indexy] = y;
		SetConsoleTextAttribute(a, 2);
		cout << "8";
	}
	else
	{
		SetConsoleTextAttribute(a, 4);
		usergrid[indexx][indexy] = 0;
		savex[indexx][indexy] = 0;
		savey[indexx][indexy] = 0;
		cout << "8";
		setCord(x, y);
		Sleep(500);
		cout << " ";
	}
	setCord(x, y);
}
if (val1 == 57)
{
	for (int i = 0; i < 9; i++)
	{
		if (x == xrr[i])
		{
			indexx = i;
		}
	}
	for (int j = 0; j < 9; j++)
	{
		if (y == yrr[j])
		{
			indexy = j;
		}
	}

	int temp = indexx;
	indexx = indexy;
	indexy = temp;

	bool v = Rowsearch(9, indexx, indexy);
	bool b = Coloumsearch(9, indexx, indexy);
	bool c = boxsearch(9, indexx, indexy);

	if (v == true && b == true && c == true)
	{
		usergrid[indexx][indexy] = 9;
		savex[indexx][indexy] = x;
		savey[indexx][indexy] = y;

		SetConsoleTextAttribute(a, 2);
		cout << "9";
	}
	else
	{
		SetConsoleTextAttribute(a, 4);
		usergrid[indexx][indexy] = 0;
		savex[indexx][indexy] = 0;
		savey[indexx][indexy] = 0;
		cout << "9";
		setCord(x, y);
		Sleep(500);
		cout << " ";
	}
	setCord(x, y);
}
if (val1 == 27)
{
label9:	int b = escapemenu();
	if (b == 2)
	{
		sudokugrid();
		realtimesave();
		sudoku();
	}
	if (b == 3)
	{
		int b = savegame();
		if (b == 2)
		{
			saveAgame(b);
			system("CLS");
			cout << "GAME SAVED" << endl;
			cout << "(Wait for 2 seconds.)" << endl;
			Sleep(2000);
			goto label9;
		}
		if (b == 3)
		{
			saveAgame(b);
			system("CLS");
			cout << "GAME SAVED" << endl;
			cout << "(Wait for 2 seconds.)" << endl;
			Sleep(3000);
			goto label9;
		}
		if (b == 4)
		{
			saveAgame(b);
			system("CLS");
			cout << "GAME SAVED" << endl;
			cout << "(Wait for 2 seconds.)" << endl;
			Sleep(3000);
			goto label9;
		}
		if (b == -1)
		{
			goto label9;
		}
	}
	if (b == 4)
	{
	label6:	int option = mainmenu();
		if (option == 2)
		{
			memset(usergrid, 0, sizeof(usergrid));
			memset(savex, 0, sizeof(savex));
			memset(savey, 0, sizeof(savey));
			memset(selectedx, 0, sizeof(selectedx));
			memset(selectedy, 0, sizeof(selectedy));
			memset(selectednum, 0, sizeof(selectednum));
			puzzleset();
			selectrandomcoor();
			sudokugrid();
			sudoku();
		}
		if (option == 3)
		{
			int b = loadsavegame();
			if (b == 2)
			{
				bool n = savedgames(b);
				if (n == false)
				{
					SetConsoleTextAttribute(a, 8);
					cout << "NO SAVED GAME EXISTS. SAVE FIRST." << endl;
					cout << "(Wait for 2 seconds.)" << endl;
					Sleep(2000);
					system("CLS");
					goto label6;
				}
				sudokugrid();
				realtimesave();
				sudoku();
			}
			if (b == 3)
			{
				bool n = savedgames(b);
				if (n == false)
				{
					SetConsoleTextAttribute(a, 8);
					cout << "NO SAVED GAME EXISTS. SAVE FIRST." << endl;
					cout << "(Wait for 2 seconds.)" << endl;
					Sleep(2000);
					system("CLS");
					goto label6;
				}
				sudokugrid();
				realtimesave();
				sudoku();

			}
			if (b == 4)
			{
				bool n = savedgames(b);
				if (n == false)
				{
					SetConsoleTextAttribute(a, 8);
					cout << "NO SAVED GAME EXISTS. SAVE FIRST." << endl;
					cout << "(Wait for 2 seconds.)" << endl;
					Sleep(2000);
					system("CLS");
					goto label6;
				}
				sudokugrid();
				realtimesave();
				sudoku();
			}
			if (b == -1)
			{
				goto label6;
			}

		}
		if (option == 4)
		{
			flag1 = false;
			exit(0);
		}

	}
}

bool h = wingame();
if (h == true)
{
	flag1 = false;
	system("CLS");
	SetConsoleTextAttribute(a, 4);
	setCord(3, 4);
	cout << " YOU WIN. CONGRATS. " << endl;
}


	} while (flag1 == true);

}


bool boundaryCheck(int a, int& x, int& y)
{
	if (a == up)
	{
		if (y == 11 || y == 18)
		{
			y -= 1;
			return true;
		}
		else if (y <= 4)
		{
			return false;
		}
		else
			return true;
	}
	if (a == down)
	{
		if (y == 8 || y == 15)
		{
			y += 1;
			return true;
		}
		else if (y >= 22)
		{
			return false;
		}
		else
			return true;
	}
	if (a == lft)
	{
		if (x == 17 || x == 31)
		{
			x -= 2;
			return true;
		}
		else if (x <= 3)
		{
			return false;
		}
		else
			return true;
	}
	if (a == rght)
	{
		if (x == 11 || x == 25)
		{
			x += 2;
			return true;
		}
		else if (x >= 39)
		{
			return false;
		}
		else
			return true;
	}

	return true;
}

bool Rowsearch(int val, int x, int y)
{
	for (int i = 0; i < 9; i++)
	{
		if (usergrid[x][i] == val)
		{
			return false;
		}
	}

	return true;
}
bool Coloumsearch(int val, int x, int y)
{
	for (int j = 0; j < 9; j++)
	{
		if (usergrid[j][y] == val)
		{
			return false;
		}
	}

	return true;
}
bool boxsearch(int val, int x, int y)
{
	int k, l;
	if (x == 0 || x == 1 || x == 2)
	{
		k = 0;
	}
	if (x == 3 || x == 4 || x == 5)
	{
		k = 3;
	}
	if (x == 6 || x == 7 || x == 8)
	{
		k = 6;
	}
	if (y == 0 || y == 1 || y == 2)
	{
		l = 0;
	}
	if (y == 3 || y == 4 || y == 5)
	{
		l = 3;
	}
	if (y == 6 || y == 7 || y == 8)
	{
		l = 6;
	}
	bool c = true;

	for (int j = 0; j < 3; j++)
	{
		int temp = l;
		for (int i = 0; i < 3; i++)
		{
			if (val == usergrid[k][temp])
			{
				c = false;
				return false;
				break;
			}
			temp++;
		}
		k++;
	}
	if (c == true)
	{
		return true;
	}
}

void puzzleset()
{
	srand((unsigned)time(0));
	int  randnum1, randnum2, randnum3, randnum4;


	randnum1 = (rand() % 9) + 1;
	randnum2 = (rand() % 9) + 1;

	if (randnum1 == randnum2)
	{
		do
		{
			randnum2 = (rand() % 9) + 1;

		} while (randnum1 == randnum2);
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (grid[i][j] == randnum1)
			{
				grid[i][j] = randnum2;
			}
			else if (grid[i][j] == randnum2)
			{
				grid[i][j] = randnum1;
			}
		}
	}


}


void selectrandomcoor()
{
	int r1, r2;
	int h, d, f;

	for (int i = 0; i <= 19; i++)
	{
		r1 = (rand() % 8);
		r2 = (rand() % 8);
		h = xrr[r1];
		d = yrr[r2];

		selectedx[i] = h;
		selectedy[i] = d;

		f = grid[r2][r1];
		usergrid[r2][r1] = f;
		selectednum[i] = f;

	}

}

bool coordinatesearch(int x, int y)
{
	for (int i = 0; i <= 19; i++)
	{
		if (selectedx[i] == x)
		{
			if (selectedy[i] == y)
			{
				return false;
			}
		}
	}

	return true;
}

bool wingame()
{
	int count = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (usergrid[i][j] == grid[i][j])
			{
				count++;
			}
		}
	}

	if (count == 81)
	{
		return true;
	}
	else
		return false;
}

int escapemenu()
{
	system("CLS");
	setCord(0, 0);
	SetConsoleTextAttribute(a, 5);
	cout << "___________________________________";
	cout << "GAME PAUSED _______________________________" << endl;
	cout << endl;
	SetConsoleTextAttribute(a, 7);
	cout << " (1) Resume." << endl;
	cout << " (2) Save this game." << endl;
	cout << " (3) Quit to main menu." << endl;
	cout << endl;

	SetConsoleTextAttribute(a, 5);
	cout << "______________________________________________________________________________" << endl;
	cout << "USE [UP]/[DOWN] KEYS TO TOGGLE THROW MENU." << endl;
	cout << "PRESS [ENTER] TO ACCSESS." << endl;

	int c = 2, val;
	bool flag = true;
	char key;

	setCord(0, c);
	SetConsoleTextAttribute(a, 5);
	cout << " (1) Resume." << endl;
	setCord(0, c);


	do {
		key = _getch();
		val = key;
		if (val == 72)
		{
			if (c == 2)
			{
				continue;
			}
			setCord(0, --c);
			if (c == 2)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (1) Resume." << endl;
				SetConsoleTextAttribute(a, 7);
				cout << " (2) Save this game." << endl;
				cout << " (3) Quit to main menu." << endl;
				setCord(0, c);

			}
			if (c == 3)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (2) Save this game." << endl;
				setCord(0, c - 1);
				SetConsoleTextAttribute(a, 7);
				cout << " (1) Resume." << endl;
				setCord(0, c + 1);
				SetConsoleTextAttribute(a, 7);
				cout << " (3) Quit to main menu." << endl;
				setCord(0, c);
			}
			if (c == 4)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (3) Quit to main menu." << endl;
				setCord(0, c - 2);
				SetConsoleTextAttribute(a, 7);
				cout << " (1) Resume." << endl;
				cout << " (2) Save this game." << endl;
				setCord(0, c);

			}
		}
		if (val == 80)
		{
			if (c == 4)
			{
				continue;
			}
			setCord(0, ++c);
			if (c == 2)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (1) Resume." << endl;
				SetConsoleTextAttribute(a, 7);
				cout << " (2) Save this game." << endl;
				cout << " (3) Quit to main menu." << endl;
				setCord(0, c);
			}
			if (c == 3)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (2) Save this game." << endl;
				setCord(0, c - 1);
				SetConsoleTextAttribute(a, 7);
				cout << " (1) Resume." << endl;
				setCord(0, c + 1);
				SetConsoleTextAttribute(a, 7);
				cout << " (3) Quit to main menu." << endl;
				setCord(0, c);
			}
			if (c == 4)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (3) Quit to main menu." << endl;
				setCord(0, c - 2);
				SetConsoleTextAttribute(a, 7);
				cout << " (1) Resume." << endl;
				cout << " (2) Save this game." << endl;
				setCord(0, c);
			}
		}
		if (val == 13)
		{
			flag = false;
			break;
		}

	} while (flag == true);

	system("CLS");
	return c;
}

void printrandomcoor()
{

	int h, d, f;

	for (int i = 0; i <= 19; i++)
	{
		h = selectedx[i];
		d = selectedy[i];
		f = selectednum[i];


		setCord(h, d);
		SetConsoleTextAttribute(a, 3);
		cout << f;
	}

}

void realtimesave()
{
	int x, y, z;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (usergrid[i][j] != 0)
			{
				x = savex[i][j];
				y = savey[i][j];
				z = usergrid[i][j];
				setCord(x, y);
				SetConsoleTextAttribute(a, 2);
				cout << z;
			}
		}
	}
}

int loadsavegame()
{
	system("CLS");
	setCord(0, 0);
	SetConsoleTextAttribute(a, 5);
	cout << "___________________________________";
	cout << "Load a Saved Game. _______________________________" << endl;
	cout << endl;
	SetConsoleTextAttribute(a, 7);
	cout << " (1) SavedGame1" << endl;
	cout << " (2) SavedGame2" << endl;
	cout << " (3) SavedGame3" << endl;
	cout << endl;

	SetConsoleTextAttribute(a, 5);
	cout << "______________________________________________________________________________" << endl;
	cout << "USE [UP]/[DOWN] KEYS TO TOGGLE THROW MENU." << endl;
	cout << "PRESS [ENTER] TO ACCESS. Press [esc] to go back" << endl;

	int c = 2, val;
	bool flag = true;
	char key;

	setCord(0, c);
	SetConsoleTextAttribute(a, 5);
	cout << " (1) SavedGame1" << endl;
	setCord(0, c);


	do {
		key = _getch();
		val = key;
		if (val == 72)
		{
			if (c == 2)
			{
				continue;
			}
			setCord(0, --c);
			if (c == 2)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (1) SavedGame1" << endl;
				SetConsoleTextAttribute(a, 7);
				cout << " (2) SavedGame2" << endl;
				cout << " (3) SavedGame3" << endl;
				setCord(0, c);

			}
			if (c == 3)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (2) SavedGame2" << endl;
				setCord(0, c - 1);
				SetConsoleTextAttribute(a, 7);
				cout << " (1) SavedGame1" << endl;
				setCord(0, c + 1);
				SetConsoleTextAttribute(a, 7);
				cout << " (3) SavedGame3" << endl;
				setCord(0, c);
			}
			if (c == 4)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (3) SavedGame3" << endl;
				setCord(0, c - 2);
				SetConsoleTextAttribute(a, 7);
				cout << " (1) SavedGame1" << endl;
				cout << " (2) SavedGame2" << endl;
				setCord(0, c);

			}
		}
		if (val == 80)
		{
			if (c == 4)
			{
				continue;
			}
			setCord(0, ++c);
			if (c == 2)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (1) SavedGame1" << endl;
				SetConsoleTextAttribute(a, 7);
				cout << " (2) SavedGame2" << endl;
				cout << " (3) SavedGame3" << endl;
				setCord(0, c);
			}
			if (c == 3)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (2) SavedGame2" << endl;
				setCord(0, c - 1);
				SetConsoleTextAttribute(a, 7);
				cout << " (1) SavedGame1" << endl;
				setCord(0, c + 1);
				SetConsoleTextAttribute(a, 7);
				cout << " (3) SavedGame3" << endl;
				setCord(0, c);
			}
			if (c == 4)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (3) SavedGame3" << endl;
				setCord(0, c - 2);
				SetConsoleTextAttribute(a, 7);
				cout << " (1) SavedGame1" << endl;
				cout << " (2) SavedGame2" << endl;
				setCord(0, c);
			}
		}
		if (val == 13)
		{
			flag = false;
			break;
		}
		if (val == 27)
		{
			flag = false;
			system("CLS");
			return -1;
		}

	} while (flag == true);

	system("CLS");
	return c;

}

bool savedgames(int a)
{
	if (a == 2)
	{
		ifstream fr;
		fr.open("usergrid(1).txt");
		if (!(fr))
		{
			return false;
		}
		int num;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fr >> num;
				usergrid[i][j] = num;
			}
		}
		fr.close();

		ifstream fg;
		fg.open("grid(1).txt");
		int num1;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fg >> num1;
				grid[i][j] = num1;
			}
		}
		fg.close();

		ifstream lo;
		lo.open("savex(1).txt");
		int num2;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				lo >> num2;
				savex[i][j] = num2;
			}
		}
		lo.close();

		ifstream gg;
		gg.open("savey(1).txt");
		int num3;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				gg >> num3;
				savey[i][j] = num3;
			}
		}
		gg.close();

		ifstream dd;
		dd.open("selectedx(1).txt");
		int num4;
		for (int i = 0; i <= 19; i++)
		{
			dd >> num4;
			selectedx[i] = num4;
		}
		dd.close();

		ifstream df;
		df.open("selectedy(1).txt");
		int num5;
		for (int i = 0; i <= 19; i++)
		{
			df >> num5;
			selectedy[i] = num5;
		}
		df.close();

		ifstream da;
		da.open("selectednum(1).txt");
		int num6;
		for (int i = 0; i <= 19; i++)
		{
			da >> num6;
			selectednum[i] = num6;
		}
		da.close();


	}
	if (a == 3)
	{
		ifstream fr;
		fr.open("usergrid(2).txt");
		if (!(fr))
		{
			return false;
		}
		int num;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fr >> num;
				usergrid[i][j] = num;
			}
		}
		fr.close();

		ifstream fg;
		fg.open("grid(2).txt");
		int num1;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fg >> num1;
				grid[i][j] = num1;
			}
		}
		fg.close();

		ifstream lo;
		lo.open("savex(2).txt");
		int num2;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				lo >> num2;
				savex[i][j] = num2;
			}
		}
		lo.close();

		ifstream gg;
		gg.open("savey(2).txt");
		int num3;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				gg >> num3;
				savey[i][j] = num3;
			}
		}
		gg.close();

		ifstream dd;
		dd.open("selectedx(2).txt");
		int num4;
		for (int i = 0; i <= 19; i++)
		{
			dd >> num4;
			selectedx[i] = num4;
		}
		dd.close();

		ifstream df;
		df.open("selectedy(2).txt");
		int num5;
		for (int i = 0; i <= 19; i++)
		{
			df >> num5;
			selectedy[i] = num5;
		}
		df.close();

		ifstream da;
		da.open("selectednum(2).txt");
		int num6;
		for (int i = 0; i <= 19; i++)
		{
			da >> num6;
			selectednum[i] = num6;
		}
		da.close();
	}
	if (a == 4)
	{
		ifstream fr;
		fr.open("usergrid(3).txt");
		if (!(fr))
		{
			return false;
		}
		int num;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fr >> num;
				usergrid[i][j] = num;
			}
		}
		fr.close();

		ifstream fg;
		fg.open("grid(3).txt");
		int num1;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fg >> num1;
				grid[i][j] = num1;
			}
		}
		fg.close();

		ifstream lo;
		lo.open("savex(3).txt");
		int num2;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				lo >> num2;
				savex[i][j] = num2;
			}
		}
		lo.close();

		ifstream gg;
		gg.open("savey(3).txt");
		int num3;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				gg >> num3;
				savey[i][j] = num3;
			}
		}
		gg.close();

		ifstream dd;
		dd.open("selectedx(3).txt");
		int num4;
		for (int i = 0; i <= 19; i++)
		{
			dd >> num4;
			selectedx[i] = num4;
		}
		dd.close();

		ifstream df;
		df.open("selectedy(3).txt");
		int num5;
		for (int i = 0; i <= 19; i++)
		{
			df >> num5;
			selectedy[i] = num5;
		}
		df.close();

		ifstream da;
		da.open("selectednum(3).txt");
		int num6;
		for (int i = 0; i <= 19; i++)
		{
			da >> num6;
			selectednum[i] = num6;
		}
		da.close();
	}

	return true;
}

int savegame()
{
	system("CLS");
	setCord(0, 0);
	SetConsoleTextAttribute(a, 5);
	cout << "___________________________________";
	cout << "Save game. _______________________________" << endl;
	cout << endl;
	SetConsoleTextAttribute(a, 7);
	cout << " (1) Slot(1)" << endl;
	cout << " (2) Slot(2)" << endl;
	cout << " (3) Slot(3)" << endl;
	cout << endl;

	SetConsoleTextAttribute(a, 5);
	cout << "______________________________________________________________________________" << endl;
	cout << "USE [UP]/[DOWN] KEYS TO TOGGLE THROW MENU." << endl;
	cout << "PRESS [ENTER] TO ACCESS. Press [esc] to go back" << endl;

	int c = 2, val;
	bool flag = true;
	char key;

	setCord(0, c);
	SetConsoleTextAttribute(a, 5);
	cout << " (1) Slot(1)" << endl;
	setCord(0, c);


	do {
		key = _getch();
		val = key;
		if (val == 72)
		{
			if (c == 2)
			{
				continue;
			}
			setCord(0, --c);
			if (c == 2)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (1) Slot(1)" << endl;
				SetConsoleTextAttribute(a, 7);
				cout << " (2) Slot(2)" << endl;
				cout << " (3) Slot(3)" << endl;
				setCord(0, c);

			}
			if (c == 3)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (2) Slot(2)" << endl;
				setCord(0, c - 1);
				SetConsoleTextAttribute(a, 7);
				cout << " (1) Slot(1)" << endl;
				setCord(0, c + 1);
				SetConsoleTextAttribute(a, 7);
				cout << " (3) Slot(3)" << endl;
				setCord(0, c);
			}
			if (c == 4)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (3) Slot(3)" << endl;
				setCord(0, c - 2);
				SetConsoleTextAttribute(a, 7);
				cout << " (1) Slot(1)" << endl;
				cout << " (2) Slot(2)" << endl;
				setCord(0, c);

			}
		}
		if (val == 80)
		{
			if (c == 4)
			{
				continue;
			}
			setCord(0, ++c);
			if (c == 2)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (1) Slot(1)" << endl;
				SetConsoleTextAttribute(a, 7);
				cout << " (2) Slot(2)" << endl;
				cout << " (3) Slot(3)" << endl;
				setCord(0, c);
			}
			if (c == 3)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (2) Slot(2)" << endl;
				setCord(0, c - 1);
				SetConsoleTextAttribute(a, 7);
				cout << " (1) Slot(1)" << endl;
				setCord(0, c + 1);
				SetConsoleTextAttribute(a, 7);
				cout << " (3) Slot(3)" << endl;
				setCord(0, c);
			}
			if (c == 4)
			{
				SetConsoleTextAttribute(a, 5);
				cout << " (3) Slot(3)" << endl;
				setCord(0, c - 2);
				SetConsoleTextAttribute(a, 7);
				cout << " (1) Slot(1)" << endl;
				cout << " (2) Slot(2)" << endl;
				setCord(0, c);
			}
		}
		if (val == 13)
		{
			flag = false;
			break;
		}
		if (val == 27)
		{
			flag = false;
			system("CLS");
			return -1;
		}

	} while (flag == true);

	system("CLS");
	return c;
}


void saveAgame(int a)
{
	if (a == 2)
	{
		ofstream gg;
		gg.open("usergrid(1).txt");
		int num;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				num = usergrid[i][j];
				gg << num << " ";
			}
		}
		gg.close();

		ofstream gh;
		gh.open("grid(1).txt");
		int num1;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				num1 = grid[i][j];
				gh << num1 << " ";
			}
		}
		gh.close();

		ofstream go;
		go.open("savex(1).txt");
		int num2;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				num2 = savex[i][j];
				go << num2 << " ";
			}
		}
		go.close();

		ofstream gl;
		gl.open("savey(1).txt");
		int num3;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				num3 = savey[i][j];
				gl << num3 << " ";
			}
		}
		gl.close();

		ofstream ll;
		ll.open("selectedx(1).txt");
		int num4;
		for (int i = 0; i <= 19; i++)
		{
			num4 = selectedx[i];
			ll << num4 << " ";
		}
		ll.close();

		ofstream lc;
		lc.open("selectedy(1).txt");
		int num5;
		for (int i = 0; i <= 19; i++)
		{
			num5 = selectedy[i];
			lc << num5 << " ";
		}
		lc.close();

		ofstream la;
		la.open("selectednum(1).txt");
		int num6;
		for (int i = 0; i <= 19; i++)
		{
			num6 = selectednum[i];
			la << num6 << " ";
		}
		la.close();



	}
	if (a == 3)
	{
		ofstream gg;
		gg.open("usergrid(2).txt");
		int num;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				num = usergrid[i][j];
				gg << num << " ";
			}
		}
		gg.close();

		ofstream gh;
		gh.open("grid(2).txt");
		int num1;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				num1 = grid[i][j];
				gh << num1 << " ";
			}
		}
		gh.close();

		ofstream go;
		go.open("savex(2).txt");
		int num2;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				num2 = savex[i][j];
				go << num2 << " ";
			}
		}
		go.close();

		ofstream gl;
		gl.open("savey(2).txt");
		int num3;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				num3 = savey[i][j];
				gl << num3 << " ";
			}
		}
		gl.close();

		ofstream ll;
		ll.open("selectedx(2).txt");
		int num4;
		for (int i = 0; i <= 19; i++)
		{
			num4 = selectedx[i];
			ll << num4 << " ";
		}
		ll.close();

		ofstream lc;
		lc.open("selectedy(2).txt");
		int num5;
		for (int i = 0; i <= 19; i++)
		{
			num5 = selectedy[i];
			lc << num5 << " ";
		}
		lc.close();

		ofstream la;
		la.open("selectednum(2).txt");
		int num6;
		for (int i = 0; i <= 19; i++)
		{
			num6 = selectednum[i];
			la << num6 << " ";
		}
		la.close();

	}
	if (a == 4)
	{
		ofstream gg;
		gg.open("usergrid(3).txt");
		int num;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				num = usergrid[i][j];
				gg << num << " ";
			}
		}
		gg.close();

		ofstream gh;
		gh.open("grid(3).txt");
		int num1;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				num1 = grid[i][j];
				gh << num1 << " ";
			}
		}
		gh.close();

		ofstream go;
		go.open("savex(3).txt");
		int num2;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				num2 = savex[i][j];
				go << num2 << " ";
			}
		}
		go.close();

		ofstream gl;
		gl.open("savey(3).txt");
		int num3;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				num3 = savey[i][j];
				gl << num3 << " ";
			}
		}
		gl.close();

		ofstream ll;
		ll.open("selectedx(3).txt");
		int num4;
		for (int i = 0; i <= 19; i++)
		{
			num4 = selectedx[i];
			ll << num4 << " ";
		}
		ll.close();

		ofstream lc;
		lc.open("selectedy(3).txt");
		int num5;
		for (int i = 0; i <= 19; i++)
		{
			num5 = selectedy[i];
			lc << num5 << " ";
		}
		lc.close();

		ofstream la;
		la.open("selectednum(3).txt");
		int num6;
		for (int i = 0; i <= 19; i++)
		{
			num6 = selectednum[i];
			la << num6 << " ";
		}
		la.close();
	}


}
