#include <iostream>
#include <queue>
#include <vector>
using namespace std;



int main()
{
	queue<pair<int, int>> bfs;
	char maze[101][101];
	int check[101][101];

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	int N, M;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maze[i][j];
			check[i][j] = 0;
		}
	}
	bfs.push(make_pair(0, 0));
	check[0][0] = 1;
	while (!bfs.empty())
	{
		int x = bfs.front().first;
		int y = bfs.front().second;
		bfs.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (maze[nx][ny] == '1' && check[nx][ny]==0)
				{
					bfs.push(make_pair(nx, ny));
					check[nx][ny] = check[x][y] + 1;
				}
			}
		}

		if (x == N-1 && y == M-1) break;
	}

	cout << check[N-1][M-1];
}