#include <iostream>

using namespace std;

int cheese[100][100];
int X, Y, answer, cnt = 0;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool check(int x, int y)
{
	return (x >= 0 && x < X &&y >= 0 && y < Y);
}

void dfs(int x, int y)
{
	cheese[x][y] = -1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (check(nx, ny))
		{
			if (cheese[nx][ny] == 0)
			{
				dfs(nx, ny);
			}
		}
	}
}

void melt()
{
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			if (cheese[i][j] == -1)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (check(nx, ny))
					{
						if (cheese[nx][ny] == 1)
							cheese[nx][ny] = 0;
					}
				}
				cheese[i][j] = 0;
			}
		}
	}
}

void count()
{
	cnt = 0;
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			if (cheese[i][j] == 1) cnt++;
		}
	}
}

void init()
{
	cin >> X >> Y;

	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			cin >> cheese[i][j];
			if (cheese[i][j] == 1) cnt++;
		}
	}
}

void solve()
{
	int time = 0;
	while (cnt)
	{
		answer = cnt;
		dfs(0, 0);
		melt();
		time++;
		count();
	}

	cout << time << endl << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}