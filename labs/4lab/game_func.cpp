#include "game_func.h"
#include <iostream>
#include <time.h>
using namespace std;
Game initGame(char userChar)
{
	srand(time(NULL));
	Game new_game;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			new_game.bord[i][j] = ' ';
	new_game.isUserTurn = bool(rand() % 2);
	new_game.userChar = userChar;
	switch (new_game.userChar) 
	{
		case '0': new_game.botChar = 'X'; break;
		case 'X': new_game.botChar = '0'; break;
	}
	return new_game;

}
void updateDisplay(const Game game)
{
	system("cls");
	
	cout << "a  " << "b  " << "c " << endl;
	cout << "__________" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "| " << game.bord[i][j] << "";
		}
		cout << "[ " << i << endl << "__________" << endl;
	}
}
void botTurn(Game* game)
{
	/*
	*
	��������� ��� ����. � ��������� ������ ��������������� ������ ������� ������ ���.
	��� ������ ���������� ������, ������� ��� ��������� � ������� � ������ ������ ����� �������/������� � ������� ���� ���� ������. 
	���� �� ���� ��� ��� �����, ��� ������ ������� ���� ���� � �����. 
	� ��������� ������� ��� ����� ��������.
	*/
	bool isEmpty = true;
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (game->bord[i][j] != ' ')
			{
				isEmpty = 0; break;
			}
		} // �������� ������ �� ����
	if (isEmpty) game->bord[1][1] = game->botChar;
	else
	{
		
		for (int i = 0; i < 3; i++) // ������
		{
			int str = 0, col = 0;
			for (int j = 0; j < 3; j++)
			{
				if (game->bord[i][j] == game->userChar) str++;
				else if (game->bord[i][j] != game->userChar) col = j;
			}
			if (str == 2){ game->bord[i][col] = game->botChar; return;
		}
		}
		for (int i = 0; i < 3; i++) // �������
		{
			int str = 0, col = 0;
			for (int j = 0; j < 3; j++)
			{
				if (game->bord[j][i] == game->userChar) str++;
				else if (game->bord[j][i] != game->userChar) col = j;
			}
			if (str == 2) {
				game->bord[col][i] = game->botChar; return;
			}
		}
		for (int i = 0; i < 3; i++)//������� ��������� �������
		{
			int str = 0, col = 0;
			for (int j = 0; j < 3; j++)
			{
				if (game->bord[i][i] == game->userChar) str++;
				else if (game->bord[i][i] != game->userChar) col = i;
			}
			if (str == 2) { game->bord[col][col] = game->botChar; return; }
		}
		for (int i = 0; i < 3; i++) //�������� ��������� �������
		{
			int str = 0, col = 0;
			for (int j = 0; j < 3; j++)
			{
				if (game->bord[i][2-i] == game->userChar) str++;
				else if (game->bord[i][2-i] != game->userChar) col = i;
			}
			if (str == 2) {
				game->bord[col][2 - col] = game->botChar; return;
			}
		}
		int str = 0, col = 0;
		while (game->bord[str][col] != ' ')
		{
			str = rand() % 3;
			col = rand() % 3;
		}
		game->bord[str][col] = game->botChar;
	}
}
void userTurn(Game* game)
{
	int x_coord = 0, y_coord = 0;
	bool is_x = true, is_y = true, two_bools = true;
	while (two_bools)
	{
		while (is_x)
		{
			cout << "������� � " << endl;
			cin >> x_coord;
			if (x_coord < 0 || x_coord > 2) cout << "������ �����������, ��������� �������" << endl;
			else is_x = false;
		}
		while (is_y)
		{
			cout << "������� y " << endl;
			cin >> y_coord;
			if (y_coord < 0 || y_coord > 2) cout << "������ �����������, ��������� �������!" << endl;
			else is_y = false;
		} 
		if (game->bord[x_coord][y_coord] == ' ')two_bools = false;
		else
		{
			cout << "�������! :))" << endl;
			is_x = true;
			is_y = true;
		}
		
	}
	game->bord[x_coord][y_coord] = game->userChar;
}
bool updateGame(Game* game)
{
	return true;
}
