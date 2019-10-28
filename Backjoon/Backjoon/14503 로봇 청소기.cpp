#include <iostream>
using namespace std;

int map[50][50] = { 0 };

int N, M;
int Answer = 0;

int dx[4] = { 0, 1, 0,-1 };
int dy[4] = {-1, 0, 1, 0 };
int bac_x[4] = { 1,0,-1,0 };
int bac_y[4] = { 0,-1,0,1 };
void dfs(int r, int c, int d)
{
	if (map[r][c] == 0)
	{
		map[r][c] = -1;
		Answer++;
	}
	else if (map[r][c] == 1)
	{
		return;
	}

	int direct = d;

	for (int i = 0; i < 4; i++) // 0 ÀÌ¸י
	{
		int j = (4 - d + i >= 4 ? i-d:4-d+i);
		direct = (direct - 1 < 0 ? 3 : direct - 1);
		int x = r + dx[j];
		int y = c + dy[j];

		if (map[x][y] == 0)
		{
			dfs(x, y, direct);
			return;
		}
	}

	dfs(r + bac_x[d], c + bac_y[d], d);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int r, c, d;

	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	dfs(r, c, d);

	cout << Answer;
	return 0;
}