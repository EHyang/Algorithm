#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int paper[101][101] = { 0 };
int check[101][101] = { 0 };
int result[101] = { 0 };

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int M, N, K; // N이 세로 M 이 가로
int a, b, x, y;

void dfs(int x, int y, int area)
{
	result[area]++;
	check[x][y] = 1;
	paper[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && ny < M && nx < N)
		{
			if (paper[nx][ny] != 1 && check[nx][ny] == 0)
			{
				dfs(nx, ny, area);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int count = 0;
	int idx = 0;
	int area = 0;
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> a >> b >> x >> y;

		for (int j = a; j < x; j++)
		{
			for (int k = b; k < y; k++)
			{
				paper[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (paper[i][j] == 0)
			{
				count++;
				dfs(i, j, area++);
			}
		}
	}

	cout << count << endl;
	sort(result, result + (count));
	for (int i = 0; i < count; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}