#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

//setup, draw

const int width = 20;
const int height = 20;
int score, x, y, fruitX, fruitY;
bool gameOver;
enum directions {
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

void Setup() {
	gameOver = false; //OYUNU BURDAN BASLATIYORUZ
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
}

void Draw() {
	system("cls");
	for (int i = 0; i < width; i++) {
		cout << "#";
	}
	cout << endl;
	for (int k = 0; k < height; k++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1)cout << "#";
			else if (k == x && j == y)cout << "O";
			else if (k == fruitX && j == fruitY)cout << "F";
			else cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++) {
		cout << "#";
	}
	cout << endl << "Score: " << score << endl;
}

void Input() {
	if (_kbhit()) { //if keyboard hit then return 1
		switch (_getch()) { //get character from keyboard
		case 'w':
			x--;
			break;
		case 'a':
			y--;
			break;
		case 's':
			x++;
			break;
		case 'd':
			y++;
			break;
		case 'x':
			gameOver = true;
			break;
		default:
			break;
		}
		if (x >= height - 1 || y >= width - 1) {
			gameOver = true;
		}
	}
}

int main() {
	srand(time(0));
	Setup();
	while (!gameOver) {
		Draw();
		Input();
	}
	//Sleep(10);
	return 0;
}