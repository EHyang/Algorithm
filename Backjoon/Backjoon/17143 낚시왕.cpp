#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int R, C, M;
int r, c, s, d, z;

struct fish {
	int x; // 세로
	int y; // 가로
	int spd; // 속도
	int dir; // 방향 1 위 2 아 3 오 4 왼
	int siz; // 크기
	bool alive;
};

int visit[101][101];
vector<fish> shark;

bool compare(fish& a, fish& b)
{
	if (a.y < b.y)
	{
		return true;
	}
	if (a.y == b.y && a.x < b.x)
	{
		return true;
	}

	return false;
}

void move(int n)
{
	int x = shark[n].x;
	int y = shark[n].y;
	int speed = shark[n].spd;
	int dir = shark[n].dir;
	int size = shark[n].siz;

	for (int i = 0; i < speed; i++)
	{
		switch (dir)
		{
		case 1:
			if (x-1 < 1)
			{
				x++;
				dir = 2;
			}
			else x--;
			break;
		case 2:
			if (x + 1 > R)
			{
				x--;
				dir = 1;
			}
			else x++;
			break;
		case 3:
			if (y + 1 > C)
			{
				y--;
				dir = 4;
			}
			else y++;
			break;
		case 4:
			if (y - 1 < 1)
			{
				y++;
				dir = 3;
			}
			else y--;
			break;
		default:
			break;
		}
	}

	if (visit[x][y] == -1)
	{
		visit[x][y] = n;
		shark[n].x = x;
		shark[n].y = y;
		shark[n].dir = dir;
	}
	else
	{
		int t = visit[x][y];

		if (shark[t].siz < size)
		{
			visit[x][y] = n;
			shark[n].x = x;
			shark[n].y = y;
			shark[n].dir = dir;
			shark[t].alive = false;
		}
		else
		{
			shark[n].alive = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int res = 0;

	cin >> R >> C >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> s >> d >> z;
		shark.push_back({ r,c,s,d,z,true });
	}

	for (int i = 1; i <= C; i++)
	{
		sort(shark.begin(), shark.end(), compare);

		memset(visit, -1, sizeof(visit));

		for (auto j = shark.begin(); j!=shark.end(); j++) // 낚시하기
		{
			if ((*j).y == i)
			{
				res += (*j).siz;
				shark.erase(j);
				break;
			}
		}
		for (int j = 0; j < shark.size(); j++)// 이동하기
		{
			move(j);
		}
		auto j = shark.begin();
		for (;j != shark.end();) // 죽이기
		{
			if ((*j).alive)
			{
				j++;
				continue;
			}
			else if (!(*j).alive)
			{
				j = shark.erase(j);
				continue;
			}
		}
	}

	cout << res;

	return 0;
}