#include<iostream>
#include<cstring>
#include<time.h>
using namespace std;

//Functions Prototype

//==========================GAME 1=============================

void start();

void movement1(string[][8], int);
void gameboard1(string[][8]);
void cords(int&, int&);

void rook(string[][8], int&, int&);
void king(string[][8], int&, int&);
void bishop(string[][8], int&, int&);
void knight(string[][8], int&, int&);
void queen(string[][8], int&, int&);

int repeatmovek(int&, int&, string[][8]);
int repeatmover(int&, int&, string[][8]);
int repeatmoveb(int&, int&, string[][8]);
int repeatmoven(int&, int&, string[][8]);
int repeatmoveq(int&, int&, string[][8]);

//==========================GAME 2=============================

void game(string[][8]);
void cords1(int&, int&);
int proceed(int*);

void player1(string[][8]);


void rook2(string[][8], int&, int&);
void king2(string[][8], int&, int&);
void bishop2(string[][8], int&, int&);
void knight2(string[][8], int&, int&);
void queen2(string[][8], int&, int&);

void player2(string[][8]);

void rook1(string[][8], int&, int&);
void king1(string[][8], int&, int&);
void bishop1(string[][8], int&, int&);
void knight1(string[][8], int&, int&);
void queen1(string[][8], int&, int&);

void checkmate(string[][8], int&);

//==========================GAME 1 Function definitions=============================

void start()
{	
	int op, size=8;
	string board[8][8] = { {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"}, {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"}, {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"}, {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"}, {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"}, {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"}, {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"}, {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"} };
	string board1[8][8] = { {"| r |", "| n |", "| b |", "| q |", "| k |", "| b |", "| n |", "| r |"}, {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"}, {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"}, {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"}, {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"}, {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"}, {"|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |", "|   |"}, {"| R |", "| N |", "| B |", "| Q |", "| K |", "| B |", "| N |", "| R |"} };
		
	cout << "Choose your gameplay mode: \n 1.Your next move \n2.Save the king\n";
	cin >> op;

	switch (op)
	{
		case 1:
			gameboard1(board);
			movement1(board, size);
			break;

		case 2:
			
			game(board1);
			break;
	}
}

void gameboard1(string board[][8])
{

	for (int i = 0; i < 8; i++)
	{
		cout << " ----------------------------------------\n" << (i + 1) << " ";
		for (int j = 0; j < 8; j++)
		{
			cout << board[i][j];
		}

		cout << endl;
	}
	cout << "  ----------------------------------------\n";
	cout << "    1    2    3    4    5    6    7    8\n";
		
}

void cords(int& x, int& y)
{
	cout << "Enter the cordinates of where you want to move your piece, row first:\n";
	cin >> y;

	while (!(y > 0) && (y < 9))
	{
		cout << "Input valid cords. Enter row: \n";
		cin >> y;

	}
	

	cout << "Enter column\n";
	cin >> x;

	while (!((x > 0) && (x < 9) && (y > 0) && (y < 9) ))
	{
		cout << "Input valid cords. Enter row: \n";
		cin >> y;

		cout << "Enter column: ";
		cin >> x;
	}
	y -= 1, x -= 1;
}

void movement1(string board[][8], int size)
{
	int x, y;
	char move;
	cout << "\nChoose any of the following: \n\tKing(type k)\n\tQueen(type q)\n\tBishop(type b)\n\tRook(type r)\n\tKnight(type N)\n";
	cin >> move;

	while (!(move == 'k' || move == 'K' || move == 'q' || move == 'Q' || move == 'n' || move == 'N' || move == 'b' || move == 'B' || move == 'r' || move == 'R'))
	{
		cout << "Enter a valid input: \n";
		cin >> move;
	}
	
	if (move == 'k' || move == 'K')
	{
		cords(x, y);
		king(board, x, y);
		gameboard1(board);
	}

	else if (move == 'r' || move == 'R')
	{
		cords(x, y);
		rook(board, x, y);
		gameboard1(board);
	}

	else if (move == 'b' || move == 'B')
	{
		cords(x, y);
		bishop(board, x, y);
		gameboard1(board);
	}

	else if (move == 'n' || move == 'N')
	{
		cords(x, y);
		knight(board, x, y);
		gameboard1(board);
	}

	else if (move == 'q' || move == 'Q')
	{
		cords(x, y);
		queen(board, x, y);
		gameboard1(board);
	}
}

//============================================================================

void king(string board[][8],int &x, int &y)
{
	board[y][x] = "| K |";
		
	for (int i = y - 1; i <= y + 1; i++)
	{
		for (int j = x - 1; j <= x + 1; j++)
		{
			if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
			{
				continue;
			}

			else
			{
				if (board[i][j] == "|   |")
				{
					board[i][j] = "| • |";
				}
			}
		}
	}
		gameboard1(board);
		repeatmovek(x, y, board);
}

int repeatmovek(int& x, int& y, string board[][8])
{
	int resume = 1;
	bool match = false;

	cout << "\nDo you wish to continue?\n1, Yes\t2. No\n";
	cin >> resume;

	while (resume != 2 && resume != 1)
	{
		cout << "Input 1 or 2 only. ";
		cin >> resume;
	}

	if (resume == 2)
	{
		return 0;
	}
	else
	{
		resume = 1;
	}

	for (int i = y - 1; i <= y + 1; i++)
	{
		for (int j = x - 1; j <= x + 1; j++)
		{
			if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
			{
				continue;
			}

			else
			{
				board[i][j] = "|   |";
			}
		}
	}
	int x1 = x, y1 = y;

	while (match == false)
	{
		cords(x, y);

		if ((y >= y1 - 1 && y <= y1 + 1) && (x >= x1 - 1 && x <= x1 + 1))
		{
			match = true;
				break;
		}

		else
			cout << "\nYou can't move there!\n";
	}

	board[y][x] = "| K |";

	for (int i = y - 1; i <= y + 1; i++)
	{
		for (int j = x - 1; j <= x + 1; j++)
		{
			if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
			{
				continue;
			}

			else
			{
				if (board[i][j] == "|   |")
				{
					board[i][j] = "| • |";
				}
			}
		}
	}

	gameboard1(board);
	repeatmovek(x, y, board);

return 0;
}	

void rook(string board[][8], int& x, int& y)
{
	board[y][x] = "| R |";

	for (int i = 0; i < 8; i++)
	{

		if (board[i][x] == "|   |")
		{
			board[i][x] = "| • |";
		}

		if (board[y][i] == "|   |")
		{
			board[y][i] = "| • |";
		}

	}

	board[y][x] = "| R |";
	gameboard1(board);
	repeatmover(x, y, board);
}

int repeatmover(int& x, int& y, string board[][8])
{
	int resume = 1;
	bool match = false;

	cout << "\nDo you wish to continue?\n1, Yes\t2. No\n";
	cin >> resume;

	while (resume > 2 || resume < 1)
	{
		cout << "Input 1 or 2 only. ";
		cin >> resume;
	}

	if (resume == 2)
	{
		return 0;
	}
		
	else
	{
		resume = 1;
	}

	for (int i = 0; i < 8; i++)
	{

		if (board[i][x] == "| • |")
		{
			board[i][x] = "|   |";
		}
	}

	for (int i = 0; i < 8; i++)
	{
		if (board[y][i] == "| • |")
		{
			board[y][i] = "|   |";
		}
	}

	board[y][x] = "|   |";
		
	int y1 = y, x1 = x;

	while (match == false)
	{
		cords(x, y);

		if(x==x1||y==y1)
		{
			match = true;
			break;
		}
		
		if (match == false)
		{
			cout << "\nYou can't move there!\n";
		}
	}
	
	for (int i = 0; i < 8; i++)
	{
		if ((i > 7) || (i < 0))
		{
			continue;
		}

		else 
		{
			board[y][i] = "| • |";
			board[i][x] = "| • |";
		}
		
		board[y][x] = "| R |";
			
	}

	gameboard1(board);
	repeatmover(x, y, board);

	return 0;
}

void bishop(string board[][8], int& x, int& y)
{	
	int i = x, j = y;

	for (i = x + 1, j = y + 1; j < 8 && i < 8; j++, i++)
	{			
		board[j][i] = "| • |";
	}

	for (i = x - 1, j = y - 1; j > -1 && i > -1; j--, i--)
	{
		board[j][i] = "| • |";
	}
			
	for (i=x-1, j = y + 1; j < 8 && i > -1; j++,  i--  )
	{
		board[j][i] = "| • |";
	}

	for (i = x + 1, j = y - 1; j > -1 && i < 8; j--, i++)
	{
		board[j][i] = "| • |";
	}

	board[y][x] = "| B |";

	gameboard1(board);

	repeatmoveb(x, y, board);
}

int repeatmoveb(int& x, int& y, string board[][8])
{
	int resume = 1;
	bool match = false;

	cout << "\nDo you wish to continue?\n1, Yes\t2. No\n";
	cin >> resume;

	while (resume > 2 || resume < 1)
	{
		cout << "Input 1 or 2 only. ";
		cin >> resume;
	}

	if (resume == 2)
	{
		return 0;
	}

	else
	{
		resume = 1;
	}

	int i = x, j = y;

	for (i = x + 1, j = y + 1; j < 8 && i < 8; j++, i++)
	{		
		board [j][i] = "|   |";
	}

	for (i = x - 1, j = y - 1; j > -1 && i > -1; j--, i--)
	{		
		board[j][i] = "|   |";
	}
			
	for (i=x-1, j = y + 1; j < 8 && i > -1; j++,  i-- )
	{
		board[j][i] = "|   |";
	}

	for (i = x + 1, j = y - 1; j > -1 && i < 8; j--, i++)
	{
		board[j][i] = "|   |";
	}

	board[y][x] = "|   |";

	int y1 = y, x1 = x;

	while (match == false)
	{
		cords(x, y);
		for (i = 0; i < 8; i++)
		{
			if ((x == x1 - i && y == y1 - i) || (x == x1 + i && y == y1 + i) || (x == x1 - i && y == y1 + i) || (x == x1 + i && y == y1 - i))
			{
				if (x >= 0 && x < 8)
				{
					match = true;
					break;
				}
			}
		}

		if (match == false)
		{
			cout << "\nYou can't move there!\n";
		}

	}

	board[y][x] = "| B |";


	for (i = x + 1, j = y + 1; j < 8 && i < 8; j++, i++)
	{

		board[j][i] = "| • |";

	}

	for (i = x - 1, j = y - 1; j > -1 && i > -1; j--, i--)
	{

		board[j][i] = "| • |";

	}

	for (i = x - 1, j = y + 1; j < 8 && i > -1; j++, i--)
	{
		board[j][i] = "| • |";
	}

	for (i = x + 1, j = y - 1; j > -1 && i < 8; j--, i++)
	{
		board[j][i] = "| • |";
	}

	board[y][x] = "| B |";

	gameboard1(board);
	repeatmoveb(x, y, board);

	return 0;
}

void knight(string board[][8], int& x, int& y)
{
	int i = x, j;
	j = y + 1;
	for (i=x-2; i<=x+2 ; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 2 || i == x + 2)
				board[j][i] = "| • |";
		}
	}

	j = y - 1;
	for (i = x - 2; i <= x + 2; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 2 || i == x + 2)
				board[j][i] = "| • |";
		}
	}

	j = y - 2;
	for (i = x - 1; i <= x + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 1 || i == x + 1)
				board[j][i] = "| • |";
		}
	}

	j = y + 2;
	for (i = x - 1; i <= x + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 1 || i == x + 1)
				board[j][i] = "| • |";
		}
	
	}

	board[y][x] = "| N |";

	gameboard1(board);

	repeatmoven(x, y, board);
}

int repeatmoven(int& x, int& y, string board[][8])
{
	int resume = 1, i = x, j = y;
	bool match = false;

	cout << "\nDo you wish to continue?\n1, Yes\t2. No\n";
	cin >> resume;

	while (resume > 2 || resume < 1)
	{
		cout << "Input 1 or 2 only. ";
		cin >> resume;
	}

	if (resume == 2)
	{
		return 0;
	}

	else
	{
		resume = 1;
	}

	j = y + 1;
	for (i = x - 2; i <= x + 2; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 2 || i == x + 2)
				board[j][i] = "|   |";
		}
	}

	j = y - 1;
	for (i = x - 2; i <= x + 2; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 2 || i == x + 2)
				board[j][i] = "|   |";
		}
	}

	j = y - 2;
	for (i = x - 1; i <= x + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 1 || i == x + 1)
				board[j][i] = "|   |";
		}
	}

	j = y + 2;
	for (i = x - 1; i <= x + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 1 || i == x + 1)
				board[j][i] = "|   |";
		}

	}
	board[y][x] = "|   |";


	int y1 = y, x1 = x;

	while (match == false)
	{
		cords(x, y);

		if (((x == x1 - 1 || x == x1 + 1) && (y == y1 - 2 || y == y1 + 2)) || ((x == x1 - 2 || x == x1 + 2) && (y == y1 + 1 || y == y1 - 1)))
		{			
			match = true;
			break;
		}
	
		if (match == false)
		{
			cout << "\nYou can't move there!\n";
		}

	}

	j = y + 1;
	for (i = x - 2; i <= x + 2; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 2 || i == x + 2)
				board[j][i] = "| • |";
		}
	}

	j = y - 1;
	for (i = x - 2; i <= x + 2; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 2 || i == x + 2)
				board[j][i] = "| • |";
		}
	}

	j = y - 2;
	for (i = x - 1; i <= x + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 1 || i == x + 1)
				board[j][i] = "| • |";
		}
	}

	j = y + 2;
	for (i = x - 1; i <= x + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 1 || i == x + 1)
				board[j][i] = "| • |";
		}

	}

	board[y][x] = "| N |";

	gameboard1(board);
	repeatmoven(x, y, board);

	return 0;
}

void queen(string board[][8], int& x, int& y)
{
	int i = x, j = y;

	for (i = x + 1, j = y + 1; j < 8 && i < 8; j++, i++)
	{
		board[j][i] = "| • |";
	}

	for (i = x - 1, j = y - 1; j > -1 && i > -1; j--, i--)
	{
		board[j][i] = "| • |";
	}

	for (i = x - 1, j = y + 1; j < 8 && i > -1; j++, i--)
	{
		board[j][i] = "| • |";
	}

	for (i = x + 1, j = y - 1; j > -1 && i < 8; j--, i++)
	{
		board[j][i] = "| • |";
	}

	for (int i = 0; i < 8; i++)
	{

		if (board[i][x] == "|   |")
		{
			board[i][x] = "| • |";
		}

		if (board[y][i] == "|   |")
		{
			board[y][i] = "| • |";
		}

	}

	board[y][x] = "| Q |";

	gameboard1(board);

	repeatmoveq(x, y, board);
}

int repeatmoveq(int& x, int& y, string board[][8])
{
	int resume = 1;
	bool match = false;

	cout << "\nDo you wish to continue?\n1, Yes\t2. No\n";
	cin >> resume;

	while (resume > 2 || resume < 1)
	{
		cout << "Input 1 or 2 only. ";
		cin >> resume;
	}

	if (resume == 2)
	{
		return 0;
	}

	else
	{
		resume = 1;
	}

	int i = x, j = y;

	for (i = x + 1, j = y + 1; j < 8 && i < 8; j++, i++)
	{
		board[j][i] = "|   |";
	}

	for (i = x - 1, j = y - 1; j > -1 && i > -1; j--, i--)
	{
		board[j][i] = "|   |";
	}

	for (i = x - 1, j = y + 1; j < 8 && i > -1; j++, i--)
	{
		board[j][i] = "|   |";
	}

	for (i = x + 1, j = y - 1; j > -1 && i < 8; j--, i++)
	{
		board[j][i] = "|   |";
	}

	for (int i = 0; i < 8; i++)
	{

		if (board[i][x] == "| • |")
		{
			board[i][x] = "|   |";
		}
	}

	for (int i = 0; i < 8; i++)
	{
		if (board[y][i] == "| • |")
		{
			board[y][i] = "|   |";
		}
	}

	board[y][x] = "|   |";

	int y1 = y, x1 = x;

	while (match == false)
	{
		cords(x, y);
		for (i = 0; i < 8; i++)
		{
			if (((x == x1 - i && y == y1 - i) || (x == x1 + i && y == y1 + i) || (x == x1 - i && y == y1 + i) || (x == x1 + i && y == y1 - i)) || (x == x1 || y == y1))
			{
				if (x >= 0 && x < 8)
				{
					match = true;
					break;
				}
			}
		}

		if (match == false)
		{
			cout << "\nYou can't move there!\n";
		}

	}

	board[y][x] = "| Q |";


	for (i = x + 1, j = y + 1; j < 8 && i < 8; j++, i++)
	{

		board[j][i] = "| • |";

	}

	for (i = x - 1, j = y - 1; j > -1 && i > -1; j--, i--)
	{

		board[j][i] = "| • |";

	}

	for (i = x - 1, j = y + 1; j < 8 && i > -1; j++, i--)
	{
		board[j][i] = "| • |";
	}

	for (i = x + 1, j = y - 1; j > -1 && i < 8; j--, i++)
	{
		board[j][i] = "| • |";
	}

	for (int i = 0; i < 8; i++)
	{
		if ((i > 7) || (i < 0))
		{
			continue;
		}

		else
		{
			board[y][i] = "| • |";
			board[i][x] = "| • |";
		}

		board[y][x] = "| R |";

	}

	board[y][x] = "| Q |";

	gameboard1(board);
	repeatmoveq(x, y, board);

	return 0;
}

//==========================GAME 2 Function definitions=============================

void game(string board1[][8])
{
	int resume = 1, count=0;
	
	while (resume != 2)
	{
		gameboard1(board1);
		player1(board1);
		count = 0;
		checkmate(board1, count);
		
		if (count == 1)
		{
			cout << "CHECKMATE!PLAYER 1 WINS" << endl;
				break;
		}
		gameboard1(board1);
		player2(board1);
		count = 0;
		checkmate(board1, count);
		if (count == 1)
		{
			cout << "CHECKMATE!PLAYER 2 WINS" << endl;
				break;
		}

		proceed(&resume);

	}

}

int proceed(int *resume)
{	
	cout << "\nDo you wish to continue?\n1, Yes\t2. No\n";
	cin >> *resume;

	while (*resume > 2 || *resume < 1)
	{
		cout << "Input 1 or 2 only. ";
		cin >> *resume;
	}

	if (*resume == 2)
	{
		return 0;
	}

	else
	{
		*resume = 1;
	}

	return *resume;
}

void cords1(int& x, int& y)
{
	cout << "\nEnter row\n";
	cin >> y;

	while (!(y > 0) && (y < 9))
	{
		cout << "Input valid cords. Enter row: \n";
		cin >> y;

	}

	cout << "Enter column\n";
	cin >> x;

	while (!((x > 0) && (x < 9) && (y > 0) && (y < 9)))
	{
		cout << "Input valid cords. Enter row: \n";
		cin >> y;

		cout << "Enter column: ";
		cin >> x;
	}
	y -= 1, x -= 1;
}

//============================================================================

void player2(string board1[][8])
{
	int x, y;

	cout << "\nPLAYER 2's TURN: \nInput the cords of the piece you want to move (small letter's)\n";
	
	cords1(x, y);

	while (board1[y][x] == "| R |" || board1[y][x] == "| N |" || board1[y][x] == "| B |" || board1[y][x] == "| Q |" || board1[y][x] == "| K |" || board1[y][x] == "|   |")
	{
		cout << "N a u r, enter your pieces co-ordinates only:\n";
		cords1(x, y);
	}

	if (board1[y][x] == "| r |")
	{
		rook1(board1, x, y);
	}

	else if (board1[y][x] == "| n |")
	{
		knight1(board1, x, y);

	}

	else if (board1[y][x] == "| b |")
	{
		bishop1(board1, x, y);

	}

	else if (board1[y][x] == "| q |")
	{
		queen1(board1, x, y);

	}

	else if (board1[y][x] == "| k |")
	{
		king1(board1, x, y);

	}
		
}

void rook1(string board1[][8], int& x, int& y)
{
	for (int i = x+1; i < 8; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y][i] == "|   |")
			board1[y][i] = "| • |";

		else
			break;
					
	}

	for (int i = x-1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y][i] == "|   |")
			board1[y][i] = "| • |";

		else
			break;
	}

	for (int i = y+1; i < 8; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x] == "|   |")
			board1[i][x] = "| • |";

		else
			break;
		
	}

	for (int i = y-1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x] == "|   |")
			board1[i][x] = "| • |";

		else
			break;
	}

	gameboard1(board1);

	int y1 = y, x1 = x;
	bool match = false;

	while (match == false)
	{
		cords1(x, y);

		if (x == x1 || y == y1)
		{
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
			{
				if (board1[y][x] == "| r |" || board1[y][x] == "| n |" || board1[y][x] == "| b |" || board1[y][x] == "| q |" || board1[y][x] == "| k |")
				{
					match = false;
				}

				else if (board1[y][x] == "| R |" || board1[y][x] == "| N |" || board1[y][x] == "| B |" || board1[y][x] == "| Q |" || board1[y][x] == "| K |")
				{
					match = true;
					break;
				}

				else
				{
					match = true;
					break;
				}
			}

		}
		if (match == false)
			cout << "\nYou can't move there!\n";
		
	}


	for (int i = x1 + 1; i <= 7; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y1][i] == "| • |")
			board1[y1][i] = "|   |";

		else
			break;

	}

	for (int i = x1 - 1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y1][i] == "| • |")
			board1[y1][i] = "|   |";

		else
			break;
	}

	for (int i = y1 + 1; i <= 7; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x1] == "| • |")
			board1[i][x1] = "|   |";

		else
			break;

	}


	for (int i = y1 - 1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x1] == "| • |")
			board1[i][x1] = "|   |";

		else
			break;

	}

board1[y1][x1] = "|   |";
board1[y][x] = "| r |";

	gameboard1(board1);
	
}

void bishop1(string board1[][8], int& x, int& y)
{

	int i = x, j = y;

	for (i = x + 1, j = y + 1; j < 8 && i < 8; j++, i++)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}

		else
			break;
	}

	for (i = x - 1, j = y - 1; j > -1 && i > -1; j--, i--)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}
		
		else
			break;
	}

	for (i = x - 1, j = y + 1; j < 8 && i > -1; j++, i--)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}
		
		
		else
			break;
	}

	for (i = x + 1, j = y - 1; j > -1 && i < 8; j--, i++)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}
		
		
		else
			break;
	}

	gameboard1(board1);

	int y1 = y, x1 = x;
	bool match = false;

	while (match == false)
	{
		cords1(x, y);
		for (i = 0; i < 8; i++)
		{
			if ((x == x1 - i && y == y1 - i) || (x == x1 + i && y == y1 + i) || (x == x1 - i && y == y1 + i) || (x == x1 + i && y == y1 - i))
			{
				if (x >= 0 && x < 8)
				{
					if (board1[y][x] == "| r |" || board1[y][x] == "| n |" || board1[y][x] == "| b |" || board1[y][x] == "| q |" || board1[y][x] == "| k |")
					{
						match = false;
					}

					if (board1[y][x] == "| R |" || board1[y][x] == "| N |" || board1[y][x] == "| B |" || board1[y][x] == "| Q |" || board1[y][x] == "| K |")
					{
						match = true;
						break;
					}

					else
					{
						match = true;
						break;
					}
				}
			}
		}

		if (match == false)
		{
			cout << "\nYou can't move there!\n";
		}
	}

	for (i = x1 + 1, j = y1 + 1; j < 8 && i < 8; j++, i++)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}
		
	}

	for (i = x1 - 1, j = y1 - 1; j > -1 && i > -1; j--, i--)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}
	}

	for (i = x1 - 1, j = y1 + 1; j < 8 && i > -1; j++, i--)
	{

		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}
	}

	for (i = x1 + 1, j = y1 - 1; j > -1 && i < 8; j--, i++)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}
	}

	board1[y][x] = "| b |";
	board1[y1][x1] = "|   |";

	gameboard1(board1);

}

void knight1(string board1[][8], int& x, int& y)
{
	int i = x, j;
	j = y + 1;

	for (i = x - 2; i <= x + 2; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 2 || i == x + 2 )
			{
				if (board1[j][i] == "|   |")
					board1[j][i] = "| • |";

				else if (board1[j][i] == "| R |" && board1[j][i] == "| N |" && board1[j][i] == "| B |" && board1[j][i] == "| Q |" && board1[j][i] == "| K |")
					continue;
				
			}
			
		}
	}

	j = y - 1;
	for (i = x - 2; i <= x + 2; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 2 || i == x + 2 && board1[j][i] == "|   |")
			{
				if (board1[j][i] == "|   |")
					board1[j][i] = "| • |";

				else if (board1[j][i] == "| R |" && board1[j][i] == "| N |" && board1[j][i] == "| B |" && board1[j][i] == "| Q |" && board1[j][i] == "| K |")
					continue;
			}
		}
	}

	j = y - 2;
	for (i = x - 1; i <= x + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 1 || i == x + 1 && board1[j][i] == "|   |")
			{
				if (board1[j][i] == "|   |")
					board1[j][i] = "| • |";

				else if (board1[j][i] == "| R |" && board1[j][i] == "| N |" && board1[j][i] == "| B |" && board1[j][i] == "| Q |" && board1[j][i] == "| K |")
					continue;
			}
		}
	}

	j = y + 2;
	for (i = x - 1; i <= x + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 1 || i == x + 1 && board1[j][i]=="|   |")
			{
				if (board1[j][i] == "|   |")
					board1[j][i] = "| • |";


				else if (board1[j][i] == "| R |" && board1[j][i] == "| N |" && board1[j][i] == "| B |" && board1[j][i] == "| Q |" && board1[j][i] == "| K |")
					continue;
			}
		}

	}

	gameboard1(board1);

	int y1 = y, x1 = x;
	bool match = false;

	while (match == false)
	{
		cords(x, y);

		if (((x == x1 - 1 || x == x1 + 1) && (y == y1 - 2 || y == y1 + 2)) || ((x == x1 - 2 || x == x1 + 2) && (y == y1 + 1 || y == y1 - 1)))
		{
			if (board1[y][x] == "| r |" || board1[y][x] == "| n |" || board1[y][x] == "| b |" || board1[y][x] == "| q |" || board1[y][x] == "| k |")
			{
				match = false;
			}

			if (board1[y][x] == "| R |" || board1[y][x] == "| N |" || board1[y][x] == "| B |" || board1[y][x] == "| Q |" || board1[y][x] == "| K |")
			{
				match = true;
				break;
			}

			else
			{
				match = true;
				break;
			}
		}

		if (match == false)
		{
			cout << "\nYou can't move there!\n";
		}

	}

	j = y1 + 1;
	for (i = x1 - 2; i <= x1 + 2; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x1 - 2 || i == x1 + 2)
			{
				if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
				{
					continue;
				}

				if (board1[j][i] != "| • |")
					continue;

				else
					board1[j][i] = "|   |";
			}
		}
	}

	j = y1 - 1;
	for (i = x1 - 2; i <= x1 + 2; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x1 - 2 || i == x1 + 2)
			{
				if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
				{
					continue;
				}

				if (board1[j][i] != "| • |")
					continue;

				else
					board1[j][i] = "|   |";
			}
		}
	}

	j = y1 - 2;
	for (i = x1 - 1; i <= x1 + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x1 - 1 || i == x1 + 1)
			{
				if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
				{
					continue;
				}

				if (board1[j][i] != "| • |")
					continue;

				else
					board1[j][i] = "|   |";
			}
		}
	}

	j = y1 + 2;
	for (i = x1 - 1; i <= x1 + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x1 - 1 || i == x1 + 1)
			{
				if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
				{
					continue;
				}

				if (board1[j][i] != "| • |")
					continue;

				else
					board1[j][i] = "|   |";
			}
		}

	}
	board1[y1][x1] = "|   |";
	board1[y][x] = "| n |";

}

void king1(string board1[][8], int& x, int& y)
{

	for (int j = y - 1; j <= y + 1; j++)
	{
		for (int i = x - 1; i <= x + 1; i++)
		{
			if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
			{
				continue;
			}

			else
			{
				if (board1[j][i] == "|   |")
					board1[j][i] = "| • |";

				else if (board1[j][i] == "| R |" && board1[j][i] == "| N |" && board1[j][i] == "| B |" && board1[j][i] == "| Q |" && board1[j][i] == "| K |")
					continue;
			}
		}
	}
	gameboard1(board1);

	int x1 = x, y1 = y;
	bool match = false;

	while (match == false)
	{
		cords(x, y);

		if ((y >= y1 - 1 && y <= y1 + 1) && (x >= x1 - 1 && x <= x1 + 1))
		{
			if (board1[y][x] == "| r |" || board1[y][x] == "| n |" || board1[y][x] == "| b |" || board1[y][x] == "| q |" || board1[y][x] == "| k |")
			{
				match = false;
			}

			if (board1[y][x] == "| R |" || board1[y][x] == "| N |" || board1[y][x] == "| B |" || board1[y][x] == "| Q |" || board1[y][x] == "| K |")
			{
				match = true;
				break;
			}

			else
			{
				match = true;
				break;
			}
		}

		if (match == false)
			cout << "\nYou can't move there!\n";

	}

	for (int i = y1 - 1; i <= y1 + 1; i++)
	{
		for (int j = x1 - 1; j <= x1 + 1; j++)
		{
			if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
			{
				continue;
			}

			if (board1[i][j] != "| • |")
				continue;

			else
				board1[i][j] = "|   |";
		}
	}

	board1[y1][x1] = "|   |";
	board1[y][x] = "| k |";

}

void queen1(string board1[][8], int& x, int& y)
{

	for (int i = x + 1; i < 8; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y][i] == "|   |")
			board1[y][i] = "| • |";

		else
			break;

	}

	for (int i = x - 1; i >= 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y][i] == "|   |")
			board1[y][i] = "| • |";

		else
			break;
	}

	for (int i = y + 1; i < 8; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x] == "|   |")
			board1[i][x] = "| • |";

		else
			break;

	}

	for (int i = y - 1; i >= 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x] == "|   |")
			board1[i][x] = "| • |";

		else
			break;
	}

	int i = x, j = y;

	for (i = x + 1, j = y + 1; j < 8 && i < 8; j++, i++)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}

		else
			break;
	}

	for (i = x - 1, j = y - 1; j > -1 && i > -1; j--, i--)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}

		else
			break;
	}

	for (i = x - 1, j = y + 1; j < 8 && i > -1; j++, i--)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}

		else
			break;
	}

	for (i = x + 1, j = y - 1; j > -1 && i < 8; j--, i++)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}

		else
			break;
	}

	gameboard1(board1);

	int y1 = y, x1 = x;
	bool match = false;

	while (match == false)
	{
		cords(x, y);
		for (i = 0; i < 8; i++)
		{
			if (((x == x1 - i && y == y1 - i) || (x == x1 + i && y == y1 + i) || (x == x1 - i && y == y1 + i) || (x == x1 + i && y == y1 - i)) || (x == x1 || y == y1))
			{
				if (x >= 0 && x < 8 && y >= 0 && y < 8)
				{
					if (board1[y][x] == "| r |" || board1[y][x] == "| n |" || board1[y][x] == "| b |" || board1[y][x] == "| q |" || board1[y][x] == "| k |")
					{
						match = false;
					}

					else if (board1[y][x] == "| R |" || board1[y][x] == "| N |" || board1[y][x] == "| B |" || board1[y][x] == "| Q |" || board1[y][x] == "| K |")
					{
						match = true;
						break;
					}

					else
					{
						match = true;
						break;
					}

				}
			}
		}

		if (match == false)
		{
			cout << "\nYou can't move there!\n";
		}

	}

	for (int i = x1 + 1; i < 8; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y1][i] == "| • |")
			board1[y1][i] = "|   |";

		else
			break;

	}

	for (int i = x1 - 1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y1][i] == "| • |")
			board1[y1][i] = "|   |";

		else
			break;
	}

	for (int i = y1 + 1; i < 8; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x1] == "| • |")
			board1[i][x1] = "|   |";

		else
			break;

	}

	for (int i = y1 - 1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x1] == "| • |")
			board1[i][x1] = "|   |";

		else
			break;
	}


	for (i = x1 + 1, j = y1 + 1; j < 8 && i < 8; j++, i++)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}

		else
			break;
	}

	for (i = x1 - 1, j = y1 - 1; j > -1 && i > -1; j--, i--)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}

		else
			break;
	}

	for (i = x1 - 1, j = y1 + 1; j < 8 && i > -1; j++, i--)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}

		else
			break;
	}

	for (i = x1 + 1, j = y1 - 1; j > -1 && i < 8; j--, i++)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}

		else
			break;
	}

	board1[y1][x1] = "|   |";
	board1[y][x] = "| q |";

}

//============================================================================

void player1(string board1[][8])
{
	int x, y;

	cout << "\nPLAYER 1's TURN: \nInput the cords of the piece you want to move (Capital letter's)\n";

	cords1(x, y);

	while (board1[y][x] == "| r |" || board1[y][x] == "| n |" || board1[y][x] == "| b |" || board1[y][x] == "| q |" || board1[y][x] == "| k |" || board1[y][x] == "|   |")
	{
		cout << "N a u r, enter your pieces co-ordinates only:\n";
		cords1(x, y);
	}

	if (board1[y][x] == "| R |")
	{
		rook2(board1, x, y);
	}

	else if (board1[y][x] == "| N |")
	{
		knight2(board1, x, y);
	}

	else if (board1[y][x] == "| B |")
	{
		bishop2(board1, x, y);
	}

	else if (board1[y][x] == "| Q |")
	{
		queen2(board1, x, y);
	}

	else if (board1[y][x] == "| K |")
	{
		king2(board1, x, y);
	}

}

void rook2(string board1[][8], int& x, int& y)
{
	for (int i = x + 1; i < 8; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y][i] == "|   |")
			board1[y][i] = "| • |";

		else
			break;

	}

	for (int i = x - 1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y][i] == "|   |")
			board1[y][i] = "| • |";

		else
			break;
	}

	for (int i = y + 1; i < 8; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x] == "|   |")
			board1[i][x] = "| • |";

		else
			break;

	}

	for (int i = y - 1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x] == "|   |")
			board1[i][x] = "| • |";

		else
			break;
	}

	gameboard1(board1);

	int y1 = y, x1 = x;
	bool match = false;

	while (match == false)
	{
		cords1(x, y);

		if (x == x1 || y == y1)
		{
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
			{
				if (board1[y][x] == "| R |" || board1[y][x] == "| N |" || board1[y][x] == "| B |" || board1[y][x] == "| Q |" || board1[y][x] == "| K |")
				{
					match = false;
				}

				else if (board1[y][x] == "| r |" || board1[y][x] == "| n |" || board1[y][x] == "| b |" || board1[y][x] == "| q |" || board1[y][x] == "| k |")
				{
					match = true;
					break;
				}

				else
				{
					match = true;
					break;
				}
			}

		}
		if (match == false)
			cout << "\nYou can't move there!\n";

	}


	for (int i = x1 + 1; i <= 7; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y1][i] == "| • |")
			board1[y1][i] = "|   |";

		else
			break;

	}

	for (int i = x1 - 1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y1][i] == "| • |")
			board1[y1][i] = "|   |";

		else
			break;
	}

	for (int i = y1 + 1; i <= 7; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x1] == "| • |")
			board1[i][x1] = "|   |";

		else
			break;

	}


	for (int i = y1 - 1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x1] == "| • |")
			board1[i][x1] = "|   |";

		else
			break;

	}

	board1[y1][x1] = "|   |";
	board1[y][x] = "| R |";

	gameboard1(board1);

}

void bishop2(string board1[][8], int& x, int& y)
{

	int i = x, j = y;

	for (i = x + 1, j = y + 1; j < 8 && i < 8; j++, i++)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}

		else
			break;
	}

	for (i = x - 1, j = y - 1; j > -1 && i > -1; j--, i--)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}

		else
			break;
	}

	for (i = x - 1, j = y + 1; j < 8 && i > -1; j++, i--)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}


		else
			break;
	}

	for (i = x + 1, j = y - 1; j > -1 && i < 8; j--, i++)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}


		else
			break;
	}

	gameboard1(board1);

	int y1 = y, x1 = x;
	bool match = false;

	while (match == false)
	{
		cords1(x, y);
		for (i = 0; i < 8; i++)
		{
			if ((x == x1 - i && y == y1 - i) || (x == x1 + i && y == y1 + i) || (x == x1 - i && y == y1 + i) || (x == x1 + i && y == y1 - i))
			{
				if (x >= 0 && x < 8)
				{
					if (board1[y][x] == "| R |" || board1[y][x] == "| N |" || board1[y][x] == "| B |" || board1[y][x] == "| Q |" || board1[y][x] == "| K |")
					{
						match = false;
					}

					else if (board1[y][x] == "| r |" || board1[y][x] == "| n |" || board1[y][x] == "| b |" || board1[y][x] == "| q |" || board1[y][x] == "| k |")
					{
						match = true;
						break;
					}

					else
					{
						match = true;
						break;
					}
				}
			}
		}

		if (match == false)
		{
			cout << "\nYou can't move there!\n";
		}
	}

	for (i = x1 + 1, j = y1 + 1; j < 8 && i < 8; j++, i++)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}

	}

	for (i = x1 - 1, j = y1 - 1; j > -1 && i > -1; j--, i--)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}
	}

	for (i = x1 - 1, j = y1 + 1; j < 8 && i > -1; j++, i--)
	{

		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}
	}

	for (i = x1 + 1, j = y1 - 1; j > -1 && i < 8; j--, i++)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}
	}

	board1[y][x] = "| B |";
	board1[y1][x1] = "|   |";

	gameboard1(board1);

}

void knight2(string board1[][8], int& x, int& y)
{
	int i = x, j;
	j = y + 1;

	for (i = x - 2; i <= x + 2; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 2 || i == x + 2)
			{
				if (board1[j][i] == "|   |")
					board1[j][i] = "| • |";

				else if (board1[j][i] == "| r |" && board1[j][i] == "| n |" && board1[j][i] == "| b |" && board1[j][i] == "| q |" && board1[j][i] == "| k |")
					continue;

			}

		}
	}

	j = y - 1;
	for (i = x - 2; i <= x + 2; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 2 || i == x + 2 && board1[j][i] == "|   |")
			{
				if (board1[j][i] == "|   |")
					board1[j][i] = "| • |";

				else if (board1[j][i] == "| r |" && board1[j][i] == "| n |" && board1[j][i] == "| b |" && board1[j][i] == "| q |" && board1[j][i] == "| k |")
					continue;
			}
		}
	}

	j = y - 2;
	for (i = x - 1; i <= x + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 1 || i == x + 1 && board1[j][i] == "|   |")
			{
				if (board1[j][i] == "|   |")
					board1[j][i] = "| • |";

				else if (board1[j][i] == "| r |" && board1[j][i] == "| n |" && board1[j][i] == "| b |" && board1[j][i] == "| q |" && board1[j][i] == "| k |")
					continue;
			}
		}
	}

	j = y + 2;
	for (i = x - 1; i <= x + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x - 1 || i == x + 1 && board1[j][i] == "|   |")
			{
				if (board1[j][i] == "|   |")
					board1[j][i] = "| • |";

				else if (board1[j][i] == "| r |" && board1[j][i] == "| n |" && board1[j][i] == "| b |" && board1[j][i] == "| q |" && board1[j][i] == "| k |")
					continue;
			}
		}

	}

	gameboard1(board1);

	int y1 = y, x1 = x;
	bool match = false;

	while (match == false)
	{
		cords(x, y);

		if (((x == x1 - 1 || x == x1 + 1) && (y == y1 - 2 || y == y1 + 2)) || ((x == x1 - 2 || x == x1 + 2) && (y == y1 + 1 || y == y1 - 1)))
		{
			if ((board1[y][x] == "| R |" || board1[y][x] == "| N |" || board1[y][x] == "| B |" || board1[y][x] == "| Q |" || board1[y][x] == "| K |"))
			{
				match = false;
			}

			else
			{
				match = true;
				break;
			}
		}

		if (match == false)
		{
			cout << "\nYou can't move there!\n";
		}

	}

	j = y1 + 1;
	for (i = x1 - 2; i <= x1 + 2; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x1 - 2 || i == x1 + 2)
			{
				if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
				{
					continue;
				}

				if (board1[j][i] != "| • |")
					continue;

				else
					board1[j][i] = "|   |";
			}
		}
	}

	j = y1 - 1;
	for (i = x1 - 2; i <= x1 + 2; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x1 - 2 || i == x1 + 2)
			{
				if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
				{
					continue;
				}

				if (board1[j][i] != "| • |")
					continue;

				else
					board1[j][i] = "|   |";
			}
		}
	}

	j = y1 - 2;
	for (i = x1 - 1; i <= x1 + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x1 - 1 || i == x1 + 1)
			{
				if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
				{
					continue;
				}

				if (board1[j][i] != "| • |")
					continue;

				else
					board1[j][i] = "|   |";
			}
		}
	}

	j = y1 + 2;
	for (i = x1 - 1; i <= x1 + 1; i++)
	{
		if (i >= 0 && i < 8 && j>0 && j < 8)
		{
			if (i == x1 - 1 || i == x1 + 1)
			{
				if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
				{
					continue;
				}

				if (board1[j][i] != "| • |")
					continue;

				else
					board1[j][i] = "|   |";
			}
		}

	}
	board1[y1][x1] = "|   |";
	board1[y][x] = "| N |";

}

void king2(string board1[][8], int& x, int& y)
{

	for (int j = y - 1; j <= y + 1; j++)
	{
		for (int i = x - 1; i <= x + 1; i++)
		{
			if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
			{
				continue;
			}

			else
			{
				if (board1[j][i] == "|   |")
					board1[j][i] = "| • |";

				else if (board1[j][i] == "| r |" && board1[j][i] == "| n |" && board1[j][i] == "| b |" && board1[j][i] == "| q |" && board1[j][i] == "| k |")
					continue;
			}
		}
	}
	gameboard1(board1);

	int x1 = x, y1 = y;
	bool match = false;

	while (match == false)
	{
		cords(x, y);

		if ((y >= y1 - 1 && y <= y1 + 1) && (x >= x1 - 1 && x <= x1 + 1))
		{
			if (board1[y][x] == "| R |" || board1[y][x] == "| N |" || board1[y][x] == "| B |" || board1[y][x] == "| Q |" || board1[y][x] == "| K |")
			{
				match = false;
			}

			else if (board1[y][x] == "| r |" || board1[y][x] == "| n |" || board1[y][x] == "| b |" || board1[y][x] == "| q |" || board1[y][x] == "| k |")
			{
				match = true;
				break;
			}

			else
			{
				match = true;
				break;
			}
		}

		if (match == false)
			cout << "\nYou can't move there!\n";

	}

	for (int i = y1 - 1; i <= y1 + 1; i++)
	{
		for (int j = x1 - 1; j <= x1 + 1; j++)
		{
			if ((i > 7) || (i < 0) || (j > 7) || (j < 0))
			{
				continue;
			}

			if (board1[i][j] != "| • |")
				continue;

			else
				board1[i][j] = "|   |";
		}
	}

	board1[y1][x1] = "|   |";
	board1[y][x] = "| K |";

}

void queen2(string board1[][8], int& x, int& y)
{

	for (int i = x + 1; i < 8; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y][i] == "|   |")
			board1[y][i] = "| • |";

		else
			break;

	}

	for (int i = x - 1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y][i] == "|   |")
			board1[y][i] = "| • |";

		else
			break;
	}

	for (int i = y + 1; i < 8; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x] == "|   |")
			board1[i][x] = "| • |";

		else
			break;

	}

	for (int i = y - 1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x] == "|   |")
			board1[i][x] = "| • |";

		else
			break;
	}

	int i = x, j = y;

	for (i = x + 1, j = y + 1; j < 8 && i < 8; j++, i++)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}

		else
			break;
	}

	for (i = x - 1, j = y - 1; j > -1 && i > -1; j--, i--)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}

		else
			break;
	}

	for (i = x - 1, j = y + 1; j < 8 && i > -1; j++, i--)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}

		else
			break;
	}

	for (i = x + 1, j = y - 1; j > -1 && i < 8; j--, i++)
	{
		if (board1[j][i] == "|   |")
		{
			board1[j][i] = "| • |";
		}

		else
			break;
	}

	gameboard1(board1);

	int y1 = y, x1 = x;
	bool match = false;

	while (match == false)
	{
		cords1(x, y);
		for (i = 0; i < 8; i++)
		{
			if (((x == x1 - i && y == y1 - i) || (x == x1 + i && y == y1 + i) || (x == x1 - i && y == y1 + i) || (x == x1 + i && y == y1 - i)) || (x == x1 || y == y1))
			{
				if (x >= 0 && x < 8 && y >= 0 && y < 8)
				{
					if (board1[y][x] == "| R |" || board1[y][x] == "| N |" || board1[y][x] == "| B |" || board1[y][x] == "| Q |" || board1[y][x] == "| K |")
					{
						match = false;
					}

					else if (board1[y][x] == "| r |" || board1[y][x] == "| n |" || board1[y][x] == "| b |" || board1[y][x] == "| q |" || board1[y][x] == "| k |")
					{
						match = true;
						break;
					}

					else
					{
						match = true;
						break;
					}
				}
			}
		}

		if (match == false)
		{
			cout << "\nYou can't move there!\n";
		}

	}

	for (int i = x1 + 1; i < 8; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y1][i] == "| • |")
			board1[y1][i] = "|   |";

		else
			break;

	}

	for (int i = x1 - 1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[y1][i] == "| • |")
			board1[y1][i] = "|   |";

		else
			break;
	}

	for (int i = y1 + 1; i < 8; i++)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x1] == "| • |")
			board1[i][x1] = "|   |";

		else
			break;

	}

	for (int i = y1 - 1; i > 0; i--)
	{
		if (i < 0 || i > 8)
			break;

		if (board1[i][x1] == "| • |")
			board1[i][x1] = "|   |";

		else
			break;
	}

	
	for (i = x1 + 1, j = y1 + 1; j < 8 && i < 8; j++, i++)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}

		else
			break;
	}

	for (i = x1 - 1, j = y1 - 1; j > -1 && i > -1; j--, i--)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}

		else
			break;
	}

	for (i = x1 - 1, j = y1 + 1; j < 8 && i > -1; j++, i--)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}

		else
			break;
	}

	for (i = x1 + 1, j = y1 - 1; j > -1 && i < 8; j--, i++)
	{
		if (board1[j][i] == "| • |")
		{
			board1[j][i] = "|   |";
		}

		else
			break;
	}

	board1[y1][x1] = "|   |";
	board1[y][x] = "| Q |";

}

//===========================================================================

void checkmate(string board1[][8], int &count)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board1[i][j] == "| K |" )
				count++;

			if (board1[i][j] == "| k |")
				count++;			
		}

		cout << endl;
	}

	cout << endl <<count;
	
}

//============================================================================

//=========== useless, i think (just like me) ============

/*void player2(string board[][8])
{
	int x8, y8, x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6;
	srand(time(0));

	unsigned int i = ((rand() % 8) + 1);
	unsigned int j = i - 1;
	i = ((rand() % 8) + 1);
	i -= 1;

	while (board[j][i] != "|   |")
	{
		i = ((rand() % 7) + 1);
		j = i;
	}

	board[j][i] = "| B |";
	y8 = j, x8 = i;

	//================================================

	i = ((rand() % 8) + 1);
	j = i - 1;
	i = ((rand() % 8) + 1);
	i -= 1;

	while (board[j][i] != "|   |")
	{
		i = ((rand() % 7) + 1);
		j = i;
	}

	board[j][i] = "| b |";
	y1 = j, x1 = i;

	//================================================

	i = ((rand() % 8) + 1);
	j = i - 1;
	i = ((rand() % 8) + 1);
	i -= 1;

	while (board[j][i] != "|   |")
	{
		i = ((rand() % 7) + 1);
		j = i;

	}
	board[j][i] = "| N |";
	y2 = j, x2 = i;

	//================================================

	i = ((rand() % 8) + 1);
	j = i - 1;
	i = ((rand() % 8) + 1);
	i -= 1;

	while (board[j][i] != "|   |")
	{
		i = ((rand() % 7) + 1);
		j = i;

	}
	board[j][i] = "| n |";
	y3 = j, x3 = i;

	//================================================

	i = ((rand() % 8) + 1);
	j = i - 1;
	i = ((rand() % 8) + 1);
	i -= 1;

	while (board[j][i] != "|   |")
	{
		i = ((rand() % 7) + 1);
		j = i;
	}

	board[j][i] = "| R |";
	y4 = j, x4 = i;

	//================================================

	i = ((rand() % 8) + 1);
	j = i - 1;
	i = ((rand() % 8) + 1);
	i -= 1;

	while (board[j][i] != "|   |")
	{
		i = ((rand() % 7) + 1);
		j = i;
	}

	board[j][i] = "| r |";
	y5 = j, x5 = i;

	//=================================================

	i = ((rand() % 8) + 1);
	j = i - 1;
	i = ((rand() % 8) + 1);
	i -= 1;

	while (board[j][i] != "|   |")
	{
		i = ((rand() % 7) + 1);
		j = i;
	}

	board[j][i] = "| Q |";
	y6 = j, x6 = i;

	//================================================

	bool match = false;


	gameboard1(board);

}*/

//============================================================================
int main()
{
	start();

	return 0;
}