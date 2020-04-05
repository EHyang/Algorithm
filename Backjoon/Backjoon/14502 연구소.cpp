#include <iostream>
#include <queue>
using namespace std;

int lab[8][8];
int copy_lab[8][8];
int N, M;

int max_safezone = 0;

queue <pair<int, int>> q;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool check(int x, int y)
{
	return 0 <= x && 0 <= y && x < N && y < M;
}

void copy()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			copy_lab[i][j] = lab[i][j];
		}
	}
}

int count_safezone()
{
	int safezone = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (copy_lab[i][j] == 0)
				safezone++;
		}
	}

	return safezone;
}

void BFS()
{
	copy();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (copy_lab[i][j] == 2)
				q.push({ i,j });
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny) && copy_lab[nx][ny] == 0)
			{
				q.push({ nx,ny });
				copy_lab[nx][ny] = 2;
			}
		}
	}
}

void wall(int cnt)
{
	if (cnt == 3)
	{
		BFS();
		int safe = count_safezone();
		max_safezone = max_safezone < safe ? safe : max_safezone;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (lab[i][j] == 0)
			{
				lab[i][j] = 1;
				wall(cnt + 1);
				lab[i][j] = 0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> lab[i][j];
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (lab[i][j] == 0)
			{
				lab[i][j] = 1;
				wall(1);
				lab[i][j] = 0;
			}
		}
	}

	cout << max_safezone;

	return 0;
}