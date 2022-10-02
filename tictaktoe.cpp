#include <bits/stdc++.h>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
// two dimetional character array
char current_marker;
int current_player;

void drawBoard()
{
	cout << endl;
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "----------" << endl;
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "----------" << endl;
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
	cout << endl;
}

bool placeMarker(int slot)
{
	int row = (slot - 1) / 3;
	int col = (slot - 1) % 3;

	// to check if slot is already filled or not.
	if (board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = current_marker;
		return true;
	}
	else
		return false;
}

int winner()
{
	for (int i = 0; i < 3; i++)
	{
		// rows
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return current_player;
		// columns
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return current_player;
	}
	if (board[0][0] == board[1][1] && board[2][2] == board[0][0])
		return current_player;
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1])
		return current_player;
	return 0;
}
void swap_player_and_marker()
{
	if (current_marker == 'X')
		current_marker = 'O';
	else
		current_marker = 'X';

	if (current_player == 1)
		current_player = 2;
	else
		current_player = 1;
}
void game()
{
	drawBoard();
	cout << "Player one, choose your marker either 'X' or 'O': ";
	char marker_p1;
	cin >> marker_p1;
	while (marker_p1 != 'X' && marker_p1 != 'O')
	{
		cout << "Invalid Marker Choosen, Please select either 'X' or 'O' ";
		cin >> marker_p1;
		cout << endl;
	}

	current_player = 1;
	current_marker = marker_p1;

	int player_won;
	int i = 0;
	while (i < 9)
	{
		cout << "It's player " << current_player << " turn. Enter your slot: ";
		int slot;
		cin >> slot;

		if (slot < 1 || slot > 9)
		{
			cout << "That slot is invalid! Try another slot!\n";
			continue;
		}

		if (!placeMarker(slot))
		{
			cout << "That slot occupied! Try another slot!\n";
			continue;
		}
		drawBoard();

		player_won = winner();

		if (player_won == 1)
		{
			cout << "Player one won!\n";
			break;
		}
		if (player_won == 2)
		{
			cout << "Player two won!\n";
			break;
		}

		swap_player_and_marker();
		i++;
	}

	if (player_won == 0)
		cout << "That is a tie game!\n";
}

int main()

{
	game();
}