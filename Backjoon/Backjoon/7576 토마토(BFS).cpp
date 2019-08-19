#include <iostream>
#include <queue>

using namespace std;

int tomato[1001][1001];
int check[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> bfs;


int main()
{
	int M, N;
	int result = 0; 

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tomato[i][j];
			check[i][j] = -1;
			if (tomato[i][j] == 1)
			{
				bfs.push(make_pair(i, j));
				check[i][j] = 0;
			}

		}
	}

	while (!bfs.empty()) {
		int x = bfs.front().first;
		int y = bfs.front().second;

		bfs.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (check[nx][ny] == -1 && tomato[nx][ny] == 0)
				{
					check[nx][ny] = check[x][y] + 1;
					bfs.push(make_pair(nx, ny));
					if (check[nx][ny] > result)
						result = check[nx][ny];
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tomato[i][j] == 0 && check[i][j] == -1)
				result = -1;
		}
	}
	cout << result;

	return 0;
}