#include <iostream>
#define endl '\n'

using namespace std;

int map[50][50] = { 0 };

int dx[] = { 0,0,-1,1,-1,-1,1,1 };
int dy[] = { -1,1,0,0,-1,1,-1,1 };
int w, h;
void dfs(int x, int y)
{
	if (!map[x][y]) return;

	map[x][y] = 0;

	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < h && ny < w)
		{
			if (map[nx][ny]) dfs(nx, ny);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (;;)
	{
		int count = 0;
		cin >> w >> h;
		if (!(w || h)) break;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j])
				{
					dfs(i, j);
					count++;
				}
			}
		}

		cout << count << endl;
	}

	return 0;
}