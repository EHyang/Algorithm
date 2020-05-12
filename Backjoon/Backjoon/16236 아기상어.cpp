#include <iostream>

#include <queue>

using namespace std;

int N;
int time = 0;
int space[21][21];
int tx, ty;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };

queue<pair<pair<int, int>, int>> q;
queue<pair<pair<int, int>, int>> av;

bool check(int x, int y)
{
	return x >= 1 && x <= N && y >= 1 && y <= N;
}

void print(int x, int y,int l, int f)
{
	cout << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == x && j == y) cout << "9 ";
			else
				cout << space[i][j] << " ";
		}
		cout << endl;
	}
	cout << "level = " << l << " feed = " << f;
	cout << endl;
}

void find()
{
	int x = av.front().first.first;
	int y = av.front().first.second;
	int d = av.front().second;
	av.pop();

	while (!av.empty())
	{
		int nx = av.front().first.first;
		int ny = av.front().first.second;
		int dd = av.front().second;
		av.pop();
		if (d == dd)
		{
			if (nx < x) {
				x = nx;
				y = ny;
			}
			else if (nx == x)
			{
				if (ny < y)
				{
					x = nx;
					y = ny;
				}
			}
		}
		if (d > dd)
		{
			d = dd;
			x = nx;
			y = ny;
		}
	}

	tx = x;
	ty = y;
}
void clear()
{
	while (!q.empty())
		q.pop();
}

void bfs(int a, int b, int level, int feed)
{
	clear();
	if (feed == level)
	{
		level += 1;
		feed = 0;
	}
	//print(a,b,level,feed);
	//cout << time << endl;


	// q( x, y, 먹을수 있냐, 거리)
	int visit[21][21] = { 0, };
	visit[a][b] = 1;
	q.push({ { a,b }, 0 });
	int last = 0;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();

		if (last != dir)
		{
			if (av.empty())
			{
				last = dir;
			}
			else
			{
				find();
				time += dir;
				space[tx][ty] = 0;
				bfs(tx, ty, level, feed + 1);
				return;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny) && visit[nx][ny] == 0)
			{
				if (space[nx][ny] != 0 && level > space[nx][ny]) // 먹을수 있어
				{
					q.push({ {nx,ny}, dir + 1 });
					visit[nx][ny] = 1;
					av.push({ {nx,ny},dir + 1 });
				}
				else if (space[nx][ny] != 0 && level == space[nx][ny]) // 먹을순 없고 갈수는 있어
				{
					q.push({ {nx,ny}, dir + 1 });
					visit[nx][ny] = 1;
				}
				else if (space[nx][ny] == 0) // 갈수만 있어
				{
					q.push({ { nx,ny }, dir + 1 });
					visit[nx][ny] = 1;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int x = 0, y = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == 9)
			{
				x = i;
				y = j;
				space[i][j] = 0;
			}
		}
	}

	if (x == 0 && y == 0)
	{
		cout << "0";
		return 0;
	}
	bfs(x, y, 2, 0);
	cout << time;
	return 0;
}