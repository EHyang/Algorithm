#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int>> dq[13][13];
deque<pair<int, int>>::iterator itr, tmp;

int N, K;

int board[13][13];
pair <int, int> pawn[11];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };

bool check(int x, int y)
{
	return (x >= 1 && x <= N && y >= 1 && y <= N);
}

int change(int d)
{
	switch (d)
	{
	case 1:
		return 2;
	case 2:
		return 1;
	case 3:
		return 4;
	case 4:
		return 3;
	}
}

void white(int x, int y, int nx, int ny)
{
	tmp = itr;
	for (; itr != dq[x][y].end(); itr++)
	{
		dq[nx][ny].push_back({ (*itr).first,(*itr).second });
		pawn[(*itr).first] = { nx,ny };
	}
	dq[x][y].erase(tmp, dq[x][y].end());
}

void red(int x, int y, int nx, int ny)
{
	tmp = itr;
	for (tmp = dq[x][y].end() - 1;; tmp--)
	{
		dq[nx][ny].push_back({ (*tmp).first, (*tmp).second });
		pawn[(*tmp).first] = { nx,ny };

		if (tmp == itr) break;
	}
	dq[x][y].erase(itr, dq[x][y].end());
}

void init()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	}

	for (int i = 1; i <= K; i++)
	{
		int x, y, d;

		cin >> x >> y >> d;
		pawn[i] = { x,y };
		dq[x][y].push_back({ i,d });
	}
}

void solve()
{
	int turn = 1;
	bool end = false;

	while (1)
	{
		for (int i = 1; i <= K; i++)
		{
			int x = pawn[i].first;
			int y = pawn[i].second;

			itr = dq[x][y].begin();

			for (;;)
			{
				if ((*itr).first == i)
					break;
				else itr++;
			}

			int nx = x + dx[(*itr).second];
			int ny = y + dy[(*itr).second];

			if (check(nx, ny))
			{
				tmp = itr;
				if (board[nx][ny] == 0)
				{
					white(x, y, nx, ny);
					if (dq[nx][ny].size() >= 4) end = true;
				}
				else if (board[nx][ny] == 1)
				{
					red(x, y, nx, ny);
					if (dq[nx][ny].size() >= 4) end = true;
				}
				else if (board[nx][ny] == 2)
				{
					(*itr).second = change((*itr).second);

					nx = x + dx[(*itr).second];
					ny = y + dy[(*itr).second];

					if (!check(nx, ny) || board[nx][ny] == 2)
					{
						continue;
					}

					if (board[nx][ny] == 0)
					{
						white(x, y, nx, ny);
						if (dq[nx][ny].size() >= 4) end = true;
					}

					else if (board[nx][ny] == 1)
					{
						red(x, y, nx, ny);
						if (dq[nx][ny].size() >= 4) end = true;
					}
				}
			}
			else
			{
				(*itr).second = change((*itr).second);

				nx = x + dx[(*itr).second];
				ny = y + dy[(*itr).second];

				if (!check(nx, ny) || board[nx][ny] == 2)
				{
					continue;
				}

				if (board[nx][ny] == 0)
				{
					white(x, y, nx, ny);
					if (dq[nx][ny].size() >= 4) end = true;
				}

				else if (board[nx][ny] == 1)
				{
					red(x, y, nx, ny);
					if (dq[nx][ny].size() >= 4) end = true;
				}
			}
		}
		if (end) break;
		turn++;
		if (turn > 1000)
		{
			turn = -1;
			break;
		}
	}

	cout << turn;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}