#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
#define SIZE 150

using namespace std;

int N, M, K;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

struct cell {
	int born;
	int life;
	int die;
	int active;
	int state; // 0 die 1 live 2 act
	bool empty = true;
};

cell map[350][350];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc, a;
	cin >> tc;

	for (int test = 1; test <= tc; test++)
	{
		cell init;
		init.born = 0;
		init.life = 0;
		init.die = 0;
		init.active = 0;
		init.state = false;
		init.empty = true;

		for (int i = 0; i < 350; i++)
		{
			for (int j = 0; j < 350; j++)
			{
				map[i][j] = init;
			}
		}

		cin >> N >> M >> K;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> a;
				if (!a) continue;
				cell tmp;
				tmp.born = 0;
				tmp.life = a;
				tmp.die = 2 * a;
				tmp.active = a;
				tmp.state = 0;
				tmp.empty = false;

				map[i + SIZE][j + SIZE] = tmp;
			}
		}
		int time = 1;

		while (time <= K)
		{
			queue<pair<int, int>> q;

			for (int i = 0; i < 350; i++)
			{
				for (int j = 0; j < 350; j++)
				{
					if (map[i][j].state == 2)
						q.push({ i,j });
					if (map[i][j].die == time)
						map[i][j].state = 0;
					if (map[i][j].active == time)
						map[i][j].state = 2;
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

					if (nx >= 0 && ny >= 0 && nx < 350 && ny < 350)
					{
						if (map[nx][ny].empty)
						{
							map[nx][ny].life = map[x][y].life;
							map[nx][ny].born = time;
							map[nx][ny].die = time + 2 * map[x][y].life;
							map[nx][ny].active = time + map[x][y].life;
							map[nx][ny].empty = false;
							map[nx][ny].state = 1;
						}
						else if (map[nx][ny].born == time)
						{
							if (map[nx][ny].life < map[x][y].life)
							{
								map[nx][ny].life = map[x][y].life;
								map[nx][ny].die = time + 2 * map[x][y].life;
								map[nx][ny].active = time + map[x][y].life;
							}
						}
					}
				}
			}
			time++;
		}

		int cnt = 0;
		for (int i = 0; i < 350; i++)
		{
			for (int j = 0; j < 350; j++)
			{
				if (map[i][j].state != 0)
				{
					cnt++;
				}
			}
		}

		cout << "#" << test << " " << cnt << endl;
	}

	return 0;
}