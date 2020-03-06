#include <iostream>

using namespace std;

int min_value = 33;
int N, M;

char board[51][51];

void solve(int x, int y)
{
	int count = 0;
	int tmp_x = x - 1;
	int tmp_y = y - 1;


	for (int i = x; i <= x + 7; i++)
	{
		for (int j = y; j <= y + 7; j++)
		{
			if ((i - tmp_x) % 2 == 1)
			{
				if ((j - tmp_y) % 2 == 1 && board[i][j] != 'W') count++;
				else if ((j - tmp_y) % 2 == 0 && board[i][j] != 'B') count++;
			}
			else
			{
				if ((j - tmp_y) % 2 == 1 && board[i][j] != 'B') count++;
				else if ((j - tmp_y) % 2 == 0 && board[i][j] != 'W') count++;
			}
		}
	}
	min_value = (min_value > count ? count : min_value);
	count = 0;

	for (int i = x; i <= x + 7; i++)
	{
		for (int j = y; j <= y + 7; j++)
		{
			if ((i - tmp_x) % 2 == 1)
			{
				if ((j - tmp_y) % 2 == 1 && board[i][j] != 'B') count++;
				else if ((j - tmp_y) % 2 == 0 && board[i][j] != 'W') count++;
			}
			else
			{
				if ((j - tmp_y) % 2 == 1 && board[i][j] != 'W') count++;
				else if ((j - tmp_y) % 2 == 0 && board[i][j] != 'B') count++;
			}
		}
	}

	min_value = (min_value > count ? count : min_value);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	// W = 0, B = 1;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 1; i + 7 <= N; i++)
	{
		for (int j = 1; j + 7 <= M; j++)
		{
			solve(i, j);
		}
	}

	cout << min_value;

	return 0;
}