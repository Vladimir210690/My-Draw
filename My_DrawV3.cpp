#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

int rows = 0;
int cols = 0;

void gotoCursor(int x, int y) {

	COORD run = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), run);
}

void Draw(int x, int y, bool pen, int**pntr, int i, int j) {
	if (pntr[i][j] == 2) {
		cout << "#";
	}
	else if (pntr[i][j] == 0) {
		cout << " ";
	}

	/*if (pen == true) {

		cout << "#";
	}
	else if (pen == false) {
		cout << " ";
	}*/
}


void Input(int x, int y, bool pen, int**pntr) {
	while (true) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				
				if (_kbhit()) {
					switch (_getch()) {
					case 72:
						if (y == 1)
							break;
						y--;
						pntr[i][j] = 1;
						break;
					case 80:
						if (y == rows - 2)
							break;
						y++;
						pntr[i][j] = 1;
						break;
					case 75:
						if (x == 1)
							break;
						x--;
						pntr[i][j] = 1;
						break;
					case 77:
						if (x == cols - 2)
							break;
						x++;
						pntr[i][j] = 1;
						break;
					case '1':
						pen = true;
						break;
					case '0':
						pen = false;
						break;
					}
				}
				if ((x <= j && y <= i) && (x >= 0 && y >= 0)) {
					gotoCursor(x, y);
					
				}
			}
		}
	}
}

int main() {
	
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	cout << "Укажите размер холста по высоте: ";
	cin >> rows;

	cout << "Укажите размер холста по ширине: ";
	cin >> cols;
	system("cls");

	int x = 5;
	int y = 5;
	bool pen = true;

	int** pntr = new int* [rows];

	for (int i = 0; i < rows; i++) {
		pntr[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			if (i == 0 || i == rows - 1) {
				pntr[i][j] = 2;
			}
			else if (j == 0 || j == cols - 1) {
				pntr[i][j] = 2;
			}
			else {
				pntr[i][j] = 0;
			}
			Draw(x, y, pen, pntr, i, j);
		}
		cout << endl;
	}

	while (true) {
		Input(x, y, pen, pntr);
		
	}

	for (int i = 0; i < rows; i++) {
		delete[]pntr;
	}
	delete[]pntr;

	return 0;
}