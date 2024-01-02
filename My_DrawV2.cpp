#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;


void gotoCursor(int x, int y) {

	COORD run = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), run);
}

void Draw(int x, int y, bool pen, int*pntr) {
	if (pen == true) {
		cout << "#";
	}
	else if (pen == false) {
		cout << " ";
	}
}


void Input(int x, int y, bool pen, int*pntr) {
	while (true) {
		if (_kbhit()) {
			switch (_getch()) {
			case 72:
				y--;
				break;
			case 80:
				y++;
				break;
			case 75:
				x--;
				break;
			case 77:
				x++;
				break;
			case '1':
				pen = true;
				break;
			case '0':
				pen = false;
				break;
			}
		}
		gotoCursor(x, y);
		Draw(x, y, pen, pntr);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int x = 10;
	int y = 10;
	bool pen = true;

	const int rows = 0;
	const int cols = 0;

	int** pntr = new int*[rows];
	for (int i = 0; i < rows; i++) {
		pntr[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			pntr[i][j] = 1;
		}
	}

	while (true) {
		Input(x, y, pen, *pntr);
		
	}

	delete[]pntr;

	return 0;
}