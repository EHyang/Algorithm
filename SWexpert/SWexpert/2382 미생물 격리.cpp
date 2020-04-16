#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<long, int>> q[102][102];
vector<pair<long, int>> a;
vector<vector<pair<long, int>>> map;
// first = 미생물수 second = 방향

// 상 1 하 2 좌 3 우 4
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
long total = 0;

int N, M, K;

bool check(int x, int y)
{
	return x > 0 && x < N - 1 && y > 0 && y < N - 1;
}

void calc()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			total += map[i][j].first;
		}
	}
}

void arrange()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int max = 0;
			int dir = 0;
			while (!q[i][j].empty())
			{
				int val = q[i][j].front().first;
				int d = q[i][j].front().second;
				q[i][j].pop();
				if (val > max)
				{
					max = val;
					dir = d;
				}

				map[i][j].first += val;
			}
			map[i][j].second = dir;
		}
	}
}
void solve(int time)
{
	if (time == 0)
	{
		calc();
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j].first == 0) continue;

			int nx = i + dx[map[i][j].second];
			int ny = j + dy[map[i][j].second];

			if (!check(nx, ny))
			{
				if (nx == 0)
				{
					q[nx][ny].push({ map[i][j].first / 2,2 });
				}
				else if (nx == N - 1)
				{
					q[nx][ny].push({ map[i][j].first / 2,1 });
				}
				else if (ny == 0)
				{
					q[nx][ny].push({ map[i][j].first / 2,4 });
				}
				else if (ny == N - 1)
				{
					q[nx][ny].push({ map[i][j].first / 2,3 });
				}
			}
			else
				q[nx][ny].push({ map[i][j].first,map[i][j].second });
		}
	}

	map.assign(N, a);
	arrange();
	solve(time - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
	{
		cin >> N >> M >> K;
		a.assign(N, { 0,0 });
		map.assign(N, a);
		int x, y;

		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			cin >> map[x][y].first >> map[x][y].second;
		}

		solve(M);

		cout << "#" << tc << " " << total << endl;
		total = 0;
	}

	return 0;
}