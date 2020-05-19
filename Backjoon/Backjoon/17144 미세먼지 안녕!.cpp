#include <iostream>
#include <memory.h>
using namespace std;

int R, C, T;
int air_1, air_2;
int res = 0;
int map[51][51];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool check(int x, int y)
{
	return x >= 1 && x <= R && y >= 1 && y <= C;
}

void init(int(*tmp)[51])
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			map[i][j] = tmp[i][j];
		}
	}

	map[air_1][1] = map[air_2][1] = -1;
}
void count()
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (map[i][j] != -1)
				res += map[i][j];
		}
	}
}

void clear()
{
	int temp[51][51] = { 0, };
	//위에 공기청정
	for (int i = 1; i <= air_1; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (i == 1)
			{
				if (j < C)
					temp[i][j] = map[i][j + 1];
				else if (j == C)
					temp[i][j] = map[i + 1][j];
			}
			else if (i == air_1)
			{
				if (j == 1) continue;
				if (j == 2) temp[i][j] = 0;
				else
					temp[i][j] = map[i][j - 1];
			}
			else
			{
				if (j == 1)
					temp[i][j] = map[i - 1][j];
				else if (j == C)
					temp[i][j] = map[i + 1][j];
				else temp[i][j] = map[i][j];
			}
		}
	}
	// 아래꺼
	for (int i = air_2; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (i == air_2)
			{
				if (j == 1) continue;
				if (j == 2) temp[i][j] = 0;
				else
					temp[i][j] = map[i][j - 1];
			}
			else if (i == R)
			{
				if (j == C)
					temp[i][j] = map[i - 1][j];
				else
					temp[i][j] = map[i][j + 1];
			}
			else
			{
				if (j == 1)
					temp[i][j] = map[i + 1][j];
				else if (j == C)
					temp[i][j] = map[i - 1][j];
				else
					temp[i][j] = map[i][j];
			}

		}
	}

	init(temp);
}

void solve(int t)
{
	if (t == T)
	{
		count();
		return;
	}
	int temp[51][51] = { 0, };

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (map[i][j] != -1 && map[i][j] != 0)
			{
				int part = map[i][j] / 5;

				for (int t = 0; t < 4; t++)
				{
					int nx = i + dx[t];
					int ny = j + dy[t];

					if (check(nx, ny) && map[nx][ny] != -1)
					{
						temp[nx][ny] += part;
						map[i][j] -= part;
					}
				}
				temp[i][j] += map[i][j];
			}
		}
	}

	init(temp);

	clear();

	solve(t + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> T;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				air_2 = i;
			}
		}
	}

	air_1 = air_2 - 1;

	solve(0);
	cout << res;

	return 0;
}