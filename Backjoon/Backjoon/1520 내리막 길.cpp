/*
	DFS로 풀면 금방 풀리는데 DFS로만 풀면 지나갔던 곳도 다시 체크해서
	시간초과가 생김
	DP로 저장해가면서 풀어야함.
*/

#include <iostream>

using namespace std;
int map[501][501];
int dp[501][501];
int check[501][501];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int M, N;

int find(int x, int y)
{
	if (dp[x][y] != -1) return dp[x][y];
	if (x == M && y == N) return 1;

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > 0 && ny > 0 && nx <= M && ny <= N)
		{
			if (!check[nx][ny] && map[nx][ny] < map[x][y])
			{
				check[nx][ny] = 1;
				dp[x][y] += find(nx, ny);
				check[nx][ny] = 0;
			}
		}
	}

	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
	check[1][1] = 1;


	cout << find(1, 1);
}