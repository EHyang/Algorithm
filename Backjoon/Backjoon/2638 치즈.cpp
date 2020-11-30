#include <iostream>

using namespace std;

int cheese[100][100];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int N, M, cnt = 0;

bool check(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < M);
}

void clear_air()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (cheese[i][j] == -1) cheese[i][j] = 0;
		}
	}
}

void dfs(int x, int y)
{
	cheese[x][y] = -1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!check(nx, ny)) continue;

		if (cheese[nx][ny] == 0)
		{
			dfs(nx, ny);
		}
	}
}

void melt()
{
	int side;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (cheese[i][j] == 1)
			{
				side = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (!check(nx, ny)) continue;

					if (cheese[nx][ny] == -1)
						side++;

					if (side >= 2)
					{
						cheese[i][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void count_cheese()
{
	cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (cheese[i][j] == 1) cnt++;
		}
	}
}

void init()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> cheese[i][j];
			if (cheese[i][j] == 1) cnt++;
		}
	}
}

void solve()
{
	int time = 0;
	while (cnt != 0)
	{
		clear_air();
		dfs(0, 0);
		melt();
		time++;
		count_cheese();
	}

	cout << time;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}