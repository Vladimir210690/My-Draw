#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) { // Функция перемещения курсора, выучил наизусть
	COORD trans = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), trans);
}

void Rules() {
	cout << "Вас приветствует программа рисования в консоли, перед началом работы прочитайте инструкцию:" << endl << endl;

	cout << "Для рисования вправо нажмите 'a' " << endl;
	cout << "Для рисования влево нажмите 'd' " << endl;
	cout << "Для рисования вверх нажмите 'w' " << endl;
	cout << "Для рисования вниз нажмите 's' " << endl;
	cout << "Для переключения режима рисования нажмите 'q' " << endl;
	cout << "Для завершения рисования нажмите 'e' " << endl << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");

	int x = 0; // Точки оси координат
	int y = 0;
	bool stop = false; // Завершить рисование
	bool motion = true; // Переменная переключения режима рисования
	
	Rules();

	cout << "Откуда начинаем рисовать? " << endl;
	cout << "Введите координату по оси x: ";
	cin >> x;
	cout << "Введите координату по оси y: ";
	cin >> y;

	system("cls");

	while (stop != true) { // Пока вечный цикл рисования
		gotoxy(x, y); // Перемещаем курсор на точки x, y
		if (_kbhit()) { // Проверяем наличие нажатой клавиши

			switch (_getch()) { // Отслеживаем нажатую клавишу и задаем им значения и действия
			case 'a':
				x--;
				break;
			case 'd':
				x++;
				break;
			case 'w':
				y--;
				break;
			case 's':
				y++;
				break;
			case 'q': // Эта клавиша переключает режим рисования (символ / пробел)
				if (motion == true) {
					motion = false;
				}
				else if (motion == false) {
					motion = true;
				}
				break;
			case 'e': // Эта кнопка завершает рисование
				stop = true;
				break;
			}

			if (motion == true) { // Определяем символ для рисования
				cout << '#';
			}
			else {
				cout << ' ';
			}
		}
	}
	return 0;
}