#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int map[100][100];
int check[100][100] = { 0 };
int dx[] = {1,-1,0,0};
int dy[] = {0,0, 1,-1 };
int result = 999999999;

queue<pair<int, int>> b;

void dfs(int x, int y, int c)
{
	map[x][y] = 0;
	check[x][y] = c;
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (map[nx][ny] == 1)
			{
				dfs(nx, ny, c);
			}
		}
	}
}

void bfs(int x, int y, int c)
{
	b.push(make_pair(x, y));

	int visit[100][100] = { false };
	int count = 0;
	visit[x][y] = true;

	while (!b.empty())
	{
		int size = b.size();
		while (size--)
		{
			x = b.front().first;
			y = b.front().second;
			b.pop();

			if (check[x][y] != 0 && check[x][y] != c)
			{
				result = min(result, count);
			}

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (0 <= nx && nx < N && 0 <= ny && ny < N)
				{
					if (check[nx][ny] != c && visit[nx][ny] == 0)
					{
						visit[nx][ny] = true;
						b.push(make_pair(nx, ny));
					}
				}
			}
		}
		count++;
	}
}

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int time = 1;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			//if (map[i][j] == 0) map[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1)
			{
				dfs(i, j, time);
				time++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (check[i][j] == 0)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (0 <= nx && nx < N && 0 <= ny && ny < N)
					{
						if (check[nx][ny] != 0)
						{
							bfs(nx, ny, check[nx][ny]);
							break;
						}

					}
				}
			}
		}
	}

	cout << result - 1;
}