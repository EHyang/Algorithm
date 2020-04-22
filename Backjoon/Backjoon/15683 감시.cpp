#include <iostream>
#include <vector>

using namespace std;

struct camera
{
	int cam;
	int x;
	int y;
};
vector<camera> v;

int room[9][9];
int N, M;
int cnt_cam;
int blind = 64;

void print_map(int(*m)[9])
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void run_cam(int(*m)[9], int dir, int x, int y)
{
	// 0 À§ 1 ¿Þ 2 ¾Æ 3 ¿À
	if (m[x][y] == 6 || (x<1 || x>N || y<1 || y>M)) return;

	if (m[x][y] == 0)
		m[x][y] = 7;
	switch (dir)
	{
	case 0:
	{
		x = x - 1;
		run_cam(m, dir, x, y);
		break;
	}
	case 1:
	{
		y = y - 1;
		run_cam(m, dir, x, y);
		break;
	}
	case 2:
	{
		x = x + 1;
		run_cam(m, dir, x, y);
		break;
	}
	case 3:
	{
		y = y + 1;
		run_cam(m, dir, x, y);
		break;
	}
	default:
		break;
	}
}

void run(int(*m)[9], int cam, int x, int y, int dir)
{
	switch (cam)
	{
	case 1:
	{
		run_cam(m, dir, x, y);
		break;
	}
	case 2:
	{
		int t_d = dir + 2;
		if (t_d >= 4) t_d -= 4;

		run_cam(m, dir, x, y);
		run_cam(m, t_d, x, y);
		break;
	}
	case 3:
	{
		int t_d = dir + 1;
		if (t_d >= 4) t_d -= 4;

		run_cam(m, dir, x, y);
		run_cam(m, t_d, x, y);
		break;
	}
	case 4:
	{
		int td = dir + 1;
		int ttd = dir + 2;
		if (td >= 4) td -= 4;
		if (ttd >= 4)ttd -= 4;

		run_cam(m, dir, x, y);
		run_cam(m, td, x, y);
		run_cam(m, ttd, x, y);
		break;
	}
	case 5:
	{
		run_cam(m, 0, x, y);
		run_cam(m, 1, x, y);
		run_cam(m, 2, x, y);
		run_cam(m, 3, x, y);
		break;
	}
	default:
		break;
	}
}

void copy_room(int(*a)[9], int(*b)[9])
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

void count_blind_side(int(*m)[9])
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (m[i][j] == 0)
				cnt++;
		}
	}
	blind = blind > cnt ? cnt : blind;
}

void dfs(int(*map)[9], int cnt)
{
	if (cnt == cnt_cam)
	{
		count_blind_side(map);
		return;
	}

	int cp_room[9][9];
	if (v[cnt].cam == 5)
	{
		copy_room(map, cp_room);
		run(map, v[cnt].cam, v[cnt].x, v[cnt].y, 0);
		dfs(map, cnt + 1);
		copy_room(cp_room, map);
	}
	else if (v[cnt].cam == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			copy_room(map, cp_room);
			run(map, v[cnt].cam, v[cnt].x, v[cnt].y, i);
			dfs(map, cnt + 1);
			copy_room(cp_room, map);
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			copy_room(map, cp_room);
			run(map, v[cnt].cam, v[cnt].x, v[cnt].y, i);
			dfs(map, cnt + 1);
			copy_room(cp_room, map);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cam = 0;

	cin >> N >> M;
	camera c;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> room[i][j];
			if (1 <= room[i][j] && room[i][j] <= 5)
			{
				c.cam = room[i][j];
				c.x = i;
				c.y = j;
				v.push_back(c);
			}
		}
	}
	cnt_cam = v.size();

	dfs(room, 0);

	cout << blind;

	return 0;
}