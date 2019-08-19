#include <iostream>
#include <memory.h>
#define endl '\n'
using namespace std;

int map[51][51] = { 0 };
int check[51][51] = { 0 };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0, 1,-1 };
int T, M, N, K;
void dfs(int x, int y)
{
	map[x][y] = 0;
	check[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < M)
		{
			if (map[nx][ny] == 1)
			{
				dfs(nx, ny);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int count = 0;
	int x, y;

	cin >> T;

	while (T--)
	{
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 1)
				{
					dfs(i, j);
					count++;
				}
			}
		}

		cout << count << endl;
		count = 0;
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
	}

	return 0;
}