#include <iostream>
#include <map>

using namespace std;

map<pair<int,int>,pair<int,int>> hole;
int board[101][101];
int N;
int max_count = 0;
int crash = 0;

int start_x;
int start_y;
bool first = true;

int nx, ny, nd;

void init()
{
	int x, y;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
		}
	}
}

void trans(int c, int x, int y, int dir)
{
	switch (c)
	{
	case 1:
		switch (dir)
		{
		case 0:
			nx = x + 1;	ny = y;	nd = 2;	break;
		case 1:
			nx = x - 1; ny = y; nd = 0; break;
		case 2:
			nx = x; ny = y + 1; nd = 3; break;
		case 3:
			nx = x; ny = y - 1; nd = 1; break;
		}
		break;
	case 2:
		switch (dir)
		{
		case 0:
			nx = x; ny = y + 1; nd = 3; break;
		case 1:
			nx = x + 1; ny = y; nd = 2; break;
		case 2:
			nx = x - 1; ny = y; nd = 0; break;
		case 3:
			nx = x; ny = y - 1; nd = 1; break;
		}
		break;
	case 3:
		switch (dir)
		{
		case 0:
			nx = x; ny = y - 1; nd = 1; break;
		case 1:
			nx = x; ny = y + 1; nd = 3; break;
		case 2:
			nx = x - 1; ny = y; nd = 0; break;
		case 3:
			nx = x + 1; ny = y; nd = 2; break;
		}
		break;
	case 4:
		switch (dir)
		{
		case 0:
			nx = x + 1; ny = y; nd = 2; break;
		case 1:
			nx = x; ny = y + 1; nd = 3; break;
		case 2:
			nx = x; ny = y - 1; nd = 1; break;
		case 3:
			nx = x - 1; ny = y; nd = 0; break;
		}
		break;
	case 5:
		switch (dir)
		{
		case 0:
			nx = x + 1; ny = y; nd = 2; break;
		case 1:
			nx = x; ny = y + 1; nd = 3; break;
		case 2:
			nx = x - 1; ny = y; nd = 0; break;
		case 3:
			nx = x; ny = y - 1; nd = 1; break;
		}
		break;
	default:
		break;
	}
}

void worm(int m, int x, int y)
{
	board[x][y] = -2;
	for(int i = 1; i<=N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (board[i][j] == m)
			{
				nx = i; ny = j; board[x][y] = m;
				return;
			}
		}
}

void play(int x, int y, int dir)
{
	if (x == start_x && y == start_y && !first)
		return;

	first = false;
	/*°¡ÀåÀÚ¸®¿¡ ºÎµú*/
	if (x == 0 || x > N || y == 0 || y > N)
	{
		if (x == 0)
		{
			crash++;
			play(x + 1, y, 2);
		}
		else if (x > N)
		{
			crash++;
			play(x - 1, y, 0);
		}
		else if (y == 0)
		{
			crash++;
			play(x, y + 1, 3);
		}
		else if (y > N)
		{
			crash++;
			play(x, y - 1, 1);
		}
	}

	else if (board[x][y] == -1) return; // ºí·¢È¦

	/*Æ¨±â´Â ¼ýÀÚ*/
	else if (1 <= board[x][y] && board[x][y] <= 5)
	{
		crash++;
		trans(board[x][y], x, y, dir);
		play(nx, ny, nd);
	}

	/*¿úÈ¦*/
	else if (6 <= board[x][y] && board[x][y] <= 10)
	{
		worm(board[x][y], x, y);
		switch (dir)
		{
		case 0:
			play(nx - 1, ny, 0);
			break;
		case 1:
			play(nx, ny - 1, 1);
			break;
		case 2:
			play(nx + 1, ny, 2);
			break;
		case 3:
			play(nx, ny + 1, 3);
			break;
		default:
			break;
		}
	}

	/*°Á °¥¶§*/
	else
	{
		switch (dir)
		{
		case 0:
			play(x - 1, y, 0);
			break;
		case 1:
			play(x, y - 1, 1);
			break;
		case 2:
			play(x + 1, y, 2);
			break;
		case 3:
			play(x, y + 1, 3);
			break;
		default:
			break;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
	{
		cin >> N;
		init();
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (board[i][j] == 0)
				{
					for (int d = 0; d < 4; d++)
					{
						crash = 0;
						first = true;
						start_x = i;
						start_y = j;
						play(i, j, d);
						max_count = max_count < crash ? crash : max_count;
					}
				}
			}
		}

		cout << "#" << tc << " " <<max_count<<endl;
		max_count = 0;
	}

	return 0;
}