#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;

int save[11][11];
int land[11][11];

vector<int> tree[11][11];
queue<pair<pair<int, int>, int>> q;
vector<int>::iterator itr;

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

bool check(int x, int y)
{
	return (x >= 1 && x <= N && y >= 1 && y <= N);
}

void init()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> save[i][j];
			land[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x, y, age;
		cin >> x >> y >> age;
		tree[x][y].push_back(age);
	}
}

void young()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			sort(tree[i][j].begin(), tree[i][j].end());
		}
	}
}

void spring()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (tree[i][j].empty()) continue;
			itr = tree[i][j].begin();

			for (; itr != tree[i][j].end();)
			{
				if (land[i][j] >= *itr)
				{
					land[i][j] -= *itr;
					*itr += 1;
					itr++;
				}
				else
				{
					q.push({ {i,j}, *itr / 2 });
					itr = tree[i][j].erase(itr);
				}
			}
		}
	}
}

void summer()
{
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int poo = q.front().second;

		q.pop();

		land[x][y] += poo;
	}
}

void fall()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (tree[i][j].empty()) continue;

			for (int k = 0; k < tree[i][j].size(); k++)
			{
				if (tree[i][j][k] == 0) continue;

				if (tree[i][j][k] % 5 != 0) continue;

				for (int t = 0; t < 8; t++)
				{
					int nx = i + dx[t];
					int ny = j + dy[t];

					if (check(nx, ny))
					{
						tree[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}

void winter()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			land[i][j] += save[i][j];
		}
	}
}

int result()
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (tree[i][j].empty()) continue;
			else
				cnt += tree[i][j].size();
		}
	}

	return cnt;
}

void solve()
{
	int answer;
	while (K--)
	{
		young();
		spring();
		summer();
		fall();
		winter();
		answer = result();
	}

	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}
