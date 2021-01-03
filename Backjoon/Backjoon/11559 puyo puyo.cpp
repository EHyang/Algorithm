#include <iostream>
#include <vector>

using namespace std;

vector<char> a;
vector<vector<char>> field;

vector<pair<int, int>> v;

int cnt = 0;

int visit[6][12];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool check(int x, int y)
{
	return (x >= 0 && x < 6 && y >= 0 && y < 12);
}

void clear()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			visit[i][j] = 0;
		}
	}
}

void dfs(char a,int x, int y, int c)
{
	v.push_back({ x, y });

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (check(nx, ny))
		{
			if (field[nx][ny] == a && visit[nx][ny] == 0)
			{
				visit[nx][ny] = 1;
				dfs(a, nx, ny, ++c);
			}
		}
	}
}

void rename()
{
	for (auto a : v)
	{
		field[a.first][a.second] = 'a';
	}
}

void bot(bool a)
{
	vector<char>::iterator itr;

	if (!a) return;

	for (int i = 0; i < 6; i++)
	{
		itr = field[i].begin();

		for (; itr != field[i].end();)
		{
			if (*itr == 'a')
			{
				itr = field[i].erase(itr);
			}
			else if (*itr == '.') break;
			else
				itr++;
		}

		while (field[i].size() < 12)
			field[i].push_back('.');
	}

	cnt++;
}

void init()
{
	a.assign(12, 0);
	field.assign(6, a);

	for (int i = 11; i >= 0; i--)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> field[j][i];
		}
	}
}

void solve()
{
	bool stop = true;
	while (stop)
	{
		stop = false;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				v.clear();
				if (field[i][j] != '.')
				{
					visit[i][j] = 1;
					dfs(field[i][j], i, j, 1);
				}
				clear();
				if (v.size() >= 4)
				{
					stop = true;
					rename();
					v.clear();
				}
			}
		}
		bot(stop);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << cnt;

	return 0;
}