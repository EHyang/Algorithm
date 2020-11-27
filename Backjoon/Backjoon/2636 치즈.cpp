#include <iostream>
#include <string>

using namespace std;

int cheese[100][100];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int mx, my, answer, cnt = 0;

void debug(string a)
{
	cout << a << endl;
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			printf("%2d ", cheese[i][j]);
		}
		cout << endl;
	}

	cout << endl << endl << endl;
}

bool check(int x, int y)
{
	return (0 <= x && x < mx && 0 <= y && y < my);
}

void dfs(int x, int y)
{
	cheese[x][y] = -1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (check(nx, ny))
		{
			if (cheese[nx][ny] == 0)
			{
				dfs(nx, ny);
			}
		}
	}
}

void find_hole()
{
	dfs(0, 0);

	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			if (cheese[i][j] == 0)
				cheese[i][j] = 2;
		}
	}
}

void dfs_hole(int x, int y)
{
	cheese[x][y] = -1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (check(nx, ny))
		{
			if (cheese[nx][ny] == 2)
				dfs_hole(nx, ny);
		}
	}
}

void hole()
{
	//debug("hole");
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			if (cheese[i][j] == 2)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (check(nx, ny))
					{
						if (cheese[nx][ny] == -1)
						{
							dfs_hole(i, j);
							break;
						}
					}
				}
			}
		}
	}
}

void dfs_melt(int x, int y, int(*visit)[100])
{
	if (visit[x][y] == 1) return;
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (check(nx, ny))
		{
			if (cheese[nx][ny] == -1)
			{
				cheese[x][y] = 3;
			}
			else if (cheese[nx][ny] == 1)
			{
				dfs_melt(nx, ny, visit);
			}
		}
	}
}

void melt()
{
	//debug("melt");
	int visit[100][100] = { 0 };
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			if (cheese[i][j] == 1 && visit[i][j] == 0)
			{
				dfs_melt(i, j, visit);
			}
		}
	}

	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			if (cheese[i][j] == 3)
			{
				cheese[i][j] = -1;
			}
		}
	}
}

void count()
{
	cnt = 0;
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			if (cheese[i][j] == 1) cnt++;
		}
	}
}

void init()
{
	cin >> mx >> my;

	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			cin >> cheese[i][j];
			if (cheese[i][j] == 1) cnt++;
		}
	}
}

void solve()
{
	int time = 0;
	while (cnt)
	{
		answer = cnt;
		find_hole();
		melt();
		hole();
		count();
		time++;
		//debug("sovle");
	}

	cout << time << endl << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}