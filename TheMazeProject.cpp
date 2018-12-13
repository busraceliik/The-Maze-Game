#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#include <stdlib.h>
#include<fstream>
#include <time.h>
#include <stdio.h>

using namespace std;
const int row = 20;
const  int colum = 20;

bool game1 = true;
bool youwon1 = true;
int *car;

int x, y;

int score = 0;

int maze[row][colum]
{
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 5, 6, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5 },
	{ 5, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5 },
	{ 5, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5 },
	{ 5, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5 },
	{ 5, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5 },
	{ 5, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 5 },
	{ 5, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 5 },
	{ 5, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 5 },
	{ 5, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 5 },
	{ 5, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5 },
	{ 5, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 5 },
	{ 5, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 5 },
	{ 5, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 5 },
	{ 5, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 5 },
	{ 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5 },
	{ 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7 },
	{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 7 },
	{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 7 },
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7 },


};


void randommaze() {

	srand(time(0));

	int size = colum * row;

	int *controller;

	controller = &maze[0][0];

	int count = 0;

	for (int i = 0; i < size; i++) {

		if (*(controller + i) == 2) {

			*(controller + i) = rand() % 2 + 1;

		}

		else if (*(controller + i) == 1 && count < 6) {//putting foods part

			if (rand() % 33 == 1) {

				*(controller + i) = 3;

				count++;

			}

			else if (rand() % 29 == 3) {

				*(controller + i) = 4;

				count++;
			}
		}
	}
}

void printmaze() {


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < colum; j++) {

			switch (maze[i][j]) {
			case 1://path
				cout << " ";
				break;
			case 2://inside wall
				cout << char(219);
				break;
			case 3://food which give +
				cout << "$";
				break;
			case 4://food which give -
				cout << "$";
				break;
			case 5://outside wall
				cout << char(219);
				break;
			case 6://enter
				cout << "C";
				break;
			case 7://out
				cout << " ";
				break;

			}

		}
		cout << " " << endl;

	}

}

void movement() {

	srand(time(NULL));

	int ways[4] = { 1,2,3,4 };
	//1 left,2 rigth,3 up,4 down

	int dirction;

	dirction = rand() % 4 + 1;

	x = 1;

	y = 1;

	car = &maze[x][y];

	int milisec = 0;
	int sec = 0;
	int min = 0;

	while (game1) {

		system("cls");
		printmaze();

		{
			dirction = rand() % 4 + 1;


			if (dirction == 1) {//left


				if (*(car - 1) == 1) {

					int temp = 0;

					temp = *car;
					*car = *(car - 1);
					*(car - 1) = temp;
					car = (car - 1);


				}

				else if (*(car - 1) == 7) {//if it is exit

					int temp = 0;

					temp = *car;
					*car = *(car - 1);
					*(car - 1) = temp;
					car = (car - 1);

					youwon1 = false;


				}

				else if (*(car - 1) == 2 || *(car - 1) == 5) {

					game1 = true;

				}

				else if (*(car - 1) == 3 || *(car - 1) == 4) {

					int temp = 0;

					temp = *car;
					*car = 1;
					*(car - 1) = temp;
					car = car - 1;

					if (*(car - 1) == 3) {

						score = score + 5;
					}
					else if (*(car - 1) == 4) {

						score = score - 5;
					}

				}


			}
			if (dirction == 2) {//riight

				if (*(car + 1) == 1) {

					int temp = 0;

					temp = *car;
					*car = *(car + 1);
					*(car + 1) = temp;
					car = (car + 1);

				}

				else if (*(car + 1) == 7) {//if it is exit

					int temp = 0;

					temp = *car;
					*car = *(car + 1);
					*(car + 1) = temp;
					car = (car + 1);

					youwon1 = false;


				}
				else if (*(car + 1) == 2 || *(car + 1) == 5) {


					game1 = true;

				}

				else if (*(car + 1) == 3 || *(car + 1) == 4) {

					int temp = 0;

					temp = *car;
					*car = 1;
					*(car + 1) = temp;
					car = car + 1;

					if (*(car + 1) == 3) {

						score = score + 5;
					}
					else if (*(car + 1) == 4) {

						score = score - 5;
					}
				}


			}
			if (dirction == 3) {//up

				if (*(car - 20) == 1) {

					int temp = 0;

					temp = *car;
					*car = *(car - 20);
					*(car - 20) = temp;
					car = (car - 20);

				}

				else if (*(car - 20) == 7) {//if it is exit

					int temp = 0;

					temp = *car;
					*car = *(car - 20);
					*(car - 20) = temp;
					car = (car - 20);

					youwon1 = false;

				}

				else if (*(car - 20) == 2 || *(car - 20) == 5) {

					game1 = true;


				}
				else if (*(car - 20) == 3 || *(car - 20) == 4) {

					int temp = 0;

					temp = *car;
					*car = 1;
					*(car - 20) = temp;
					car = car - 20;

					if (*(car - 20) == 3) {

						score = score + 5;
					}
					else if (*(car - 20) == 4) {

						score = score - 5;
					}
				}
			}
			if (dirction == 4) {//down

				if (*(car + 20) == 1) {

					int temp = 0;

					temp = *car;
					*car = *(car + 20);
					*(car + 20) = temp;
					car = (car + 20);

				}

				else if (*(car + 20) == 7) {//if it is exit

					int temp = 0;

					temp = *car;
					*car = *(car + 20);
					*(car + 20) = temp;
					car = (car + 20);

					youwon1 = false;



				}
				else if (*(car + 20) == 2 || *(car + 20) == 5) {

					game1 = true;

				}
				else if (*(car + 20) == 3 || *(car + 20) == 4) {

					int temp = 0;

					temp = *car;
					*car = 1;
					*(car + 20) = temp;
					car = car + 20;

					if (*(car + 20) == 3) {

						score = score + 5;
					}
					else if (*(car + 20) == 4) {

						score = score - 5;
					}
				}
			}

		}

		{
			if (milisec == 10) {
				++sec;
				milisec = 0;
			}
			if (sec == 60) {
				++min;
				sec = 0;
			}

			cout << "Time : " << min << " : " << sec << " : " << milisec << endl;
			if (min == 2) {
				game1 = false;
				cout << "Time is up.You lost." << endl;
				cout << "Your Score is: " << score << endl;
			}

			milisec++;
			Sleep(20);
		}
		if (youwon1 == false) {

			game1 = false;


		}

	}
}

const int row2 = 20;
const  int colum2 = 20;

bool game2;
bool youwon2 = true;
int *car2;

int x2, y2;

int score2 = 0;

int maze2[row2][colum2]
{
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 5, 6, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5 },
	{ 5, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5 },
	{ 5, 1, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5 },
	{ 5, 1, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5 },
	{ 5, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 5 },
	{ 5, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 5 },
	{ 5, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 5 },
	{ 5, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 2, 2, 2, 5 },
	{ 5, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 2, 2, 2, 5 },
	{ 5, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 5 },
	{ 5, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 5 },
	{ 5, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 5 },
	{ 5, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 5 },
	{ 5, 1, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 5 },
	{ 5, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 5 },
	{ 5, 1, 1, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 5 },
	{ 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7 },
	{ 5, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 7 },
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7 },


};

void randommaze2() {

	srand(time(0));

	int size2 = colum2 * row2;

	int *controller2;

	controller2 = &maze2[0][0];

	int count2 = 0;

	for (int i2 = 0; i2 < size2; i2++) {

		if (*(controller2 + i2) == 2) {

			*(controller2 + i2) = rand() % 2 + 1;

		}

		else if (*(controller2 + i2) == 1 && count2 < 6) {//putting foods part

			if (rand() % 43 == 1) {

				*(controller2 + i2) = 3;

				count2++;

			}

			else if (rand() % 47 == 3) {

				*(controller2 + i2) = 4;

				count2++;
			}
		}
	}
}

void printmaze2() {


	for (int i2 = 0; i2 < row2; i2++) {
		for (int j2 = 0; j2 < colum2; j2++) {

			switch (maze2[i2][j2]) {
			case 1://path
				cout << " ";
				break;
			case 2://inside wall
				cout << char(219);
				break;
			case 3://food which give +
				cout << "$";
				break;
			case 4://food which give -
				cout << "$";
				break;
			case 5://outside wall
				cout << char(219);
				break;
			case 6://enter
				cout << "C";
				break;
			case 7://out
				cout << " ";
				break;
			}

		}
		cout << " " << endl;

	}

}

void movement2() {

	srand(time(NULL));

	int ways2[4] = { 1,2,3,4 };
	//1 left,2 rigth,3 up,4 down

	int dirction2;

	dirction2 = rand() % 4 + 1;

	x2 = 1;

	y2 = 1;

	car2 = &maze2[x2][y2];

	int milisec2 = 0;
	int sec2 = 0;
	int min2 = 0;

	while (game2) {

		system("cls");
		printmaze2();

		{
			dirction2 = rand() % 4 + 1;


			if (dirction2 == 1) {//left


				if (*(car2 - 1) == 1) {

					int temp2 = 0;

					temp2 = *car2;
					*car2 = *(car2 - 1);
					*(car2 - 1) = temp2;
					car2 = (car2 - 1);


				}

				else if (*(car2 - 1) == 7) {//if it is exit

					int temp2 = 0;

					temp2 = *car2;
					*car2 = *(car2 - 1);
					*(car2 - 1) = temp2;
					car2 = (car2 - 1);

					youwon2 = false;


				}

				else if (*(car2 - 1) == 2 || *(car2 - 1) == 5) {

					game2 = true;

				}

				else if (*(car2 - 1) == 3 || *(car2 - 1) == 4) {

					int temp2 = 0;

					temp2 = *car2;
					*car2 = 1;
					*(car2 - 1) = temp2;
					car2 = car2 - 1;

					if (*(car2 - 1) == 3) {
						score2 = score2 + 5;
					}
					else if (*(car2 - 1) == 4) {
						score2 = score2 - 5;
					}

				}


			}
			if (dirction2 == 2) {//riight

				if (*(car2 + 1) == 1) {

					int temp2 = 0;

					temp2 = *car2;
					*car2 = *(car2 + 1);
					*(car2 + 1) = temp2;
					car2 = (car2 + 1);

				}

				else if (*(car2 + 1) == 7) {//if it is exit

					int temp2 = 0;

					temp2 = *car2;
					*car2 = *(car2 + 1);
					*(car2 + 1) = temp2;
					car2 = (car2 + 1);

					youwon2 = false;


				}
				else if (*(car2 + 1) == 2 || *(car2 + 1) == 5) {


					game2 = true;

				}

				else if (*(car2 + 1) == 3 || *(car2 + 1) == 4) {

					int temp2 = 0;

					temp2 = *car2;
					*car2 = 1;
					*(car2 + 1) = temp2;
					car2 = car2 + 1;

					if (*(car2 + 1) == 3) {
						score2 = score2 + 5;
					}
					else if (*(car2 + 1) == 4) {
						score2 = score2 - 5;
					}
				}


			}
			if (dirction2 == 3) {//up

				if (*(car2 - 20) == 1) {

					int temp2 = 0;

					temp2 = *car2;
					*car2 = *(car2 - 20);
					*(car2 - 20) = temp2;
					car2 = (car2 - 20);

				}

				else if (*(car2 - 20) == 7) {//if it is exit

					int temp2 = 0;

					temp2 = *car2;
					*car2 = *(car2 - 20);
					*(car2 - 20) = temp2;
					car2 = (car2 - 20);

					youwon2 = false;

				}

				else if (*(car2 - 20) == 2 || *(car2 - 20) == 5) {

					game2 = true;


				}
				else if (*(car2 - 20) == 3 || *(car2 - 20) == 4) {

					int temp2 = 0;

					temp2 = *car2;
					*car2 = 1;
					*(car2 - 20) = temp2;
					car2 = car2 - 20;

					if (*(car2 - 20) == 3) {
						score2 = score2 + 5;
					}
					else if (*(car2 - 20) == 4) {
						score2 = score2 - 5;
					}
				}
			}
			if (dirction2 == 4) {//down

				if (*(car2 + 20) == 1) {

					int temp2 = 0;

					temp2 = *car2;
					*car2 = *(car2 + 20);
					*(car2 + 20) = temp2;
					car2 = (car2 + 20);

				}

				else if (*(car2 + 20) == 7) {//if it is exit

					int temp2 = 0;

					temp2 = *car2;
					*car2 = *(car2 + 20);
					*(car2 + 20) = temp2;
					car2 = (car2 + 20);

					youwon2 = false;



				}
				else if (*(car2 + 20) == 2 || *(car2 + 20) == 5) {

					game2 = true;

				}
				else if (*(car2 + 20) == 3 || *(car2 + 20) == 4) {

					int temp2 = 0;

					temp2 = *car2;
					*car2 = 1;
					*(car2 + 20) = temp2;
					car2 = car2 + 20;

					if (*(car2 + 20) == 3) {
						score2 = score2 + 5;
					}
					else if (*(car2 + 20) == 4) {
						score2 = score2 - 5;
					}
				}
			}

		}

		{
			if (milisec2 == 10) {
				++sec2;
				milisec2 = 0;
			}
			if (sec2 == 60) {
				++min2;
				sec2 = 0;
			}
			cout << "Time : " << min2 << " : " << sec2 << " : " << milisec2 << endl;
			if (min2 == 1) {
				game2 = false;
				cout << "Time is up.You lost." << endl;
				cout << "Your Total Score is: " << score + score2 << endl;
			}

			milisec2++;
			Sleep(20);
		}
		if (youwon2 == false) {

			game2 = false;

			cout << "CONGRULATIONS YOU WIN!" << endl;
			cout << "Your Yotal score is " << score + score2 << endl;
		}

	}
}


int main() {

	randommaze();
	printmaze();
	movement();

	if (youwon1 == false && game1 == false) {

		game2 = true;

		randommaze2();
		printmaze2();
		movement2();
	}
	system("PAUSE");
	return 0;

}
