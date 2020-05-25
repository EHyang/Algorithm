/*

Simulation
2020-05-25
 - 3개가 모일 경우를 고려해야함

*/

#include <iostream>
#include <memory.h>
using namespace std;

int N, x, y, d, K;

int result = 0;

// 상 0 하 1 좌 2 우 3
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };

int map[2001][2001] = { 0, };

struct Atom {
	int x;
	int y;
	int dir;
	int power;
	bool die;
} atom[1001];


bool limit(int x, int y) // 범위 파악
{
	return x >= 0 && x <= 2000 && y >= 0 && y <= 2000;
}

bool empty_check(int x, int y)
{
	return map[x][y] == 0;
}

bool reverse(int a, int b)
{
	int a_dir = atom[a].dir;
	int b_dir = atom[b].dir;

	switch (a_dir)
	{
	case 0:
	case 1:
		return (a_dir + b_dir) == 1;
	case 2:
	case 3:
		return (a_dir + b_dir) == 5;
	}
}

void move(int num)
{
	int x = atom[num].x;
	int y = atom[num].y;

	map[x][y] = 0;

	int nx = x + dx[atom[num].dir];
	int ny = y + dy[atom[num].dir];

	if (limit(nx, ny))
	{
		if (!empty_check(nx, ny))
		{
			if (reverse(num, map[nx][ny])) // 방향이 반대라면?
			{
				// 0.5초에 터져야함

				result += atom[num].power;
				result += atom[map[nx][ny]].power;

				atom[num].die = true;
				atom[map[nx][ny]].die = true;

				map[nx][ny] = 0;
			}
			else // 안터짐
			{
				atom[num].x = nx;
				atom[num].y = ny;
			}
		}
		else // 안터짐
		{
			atom[num].x = nx;
			atom[num].y = ny;
		}
	}
	else
	{
		atom[num].die = true;
	}
}

void solution(int time)
{
	if (time > 2001) return;

	for (int i = 1; i <= N; i++)
	{
		if (atom[i].die) continue;

		move(i);		
	}
	for (int i = 1; i <= N; i++)
	{
		if (atom[i].die) continue;

		int x = atom[i].x;
		int y = atom[i].y;

		if (map[x][y] == 0) map[x][y] = i;
		else
		{
			result += atom[i].power;
			if(!atom[map[x][y]].die)
				result += atom[map[x][y]].power;

			atom[i].die = true;
			atom[map[x][y]].die = true;

			map[x][y] = i;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (atom[i].die)
		{
			int x = atom[i].x;
			int y = atom[i].y;

			if (map[x][y] != 0) map[x][y] = 0;
		}
	}

	solution(time + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int test;

	cin >> test;

	for (int tc = 1; tc <= test; tc++)
	{
		cin >> N;

		for (int n = 1; n <= N; n++)
		{
			cin >> x >> y >> d >> K;
			atom[n] = { x + 1000, y + 1000, d, K, false };
			// +1000 음수처리 위함
			map[x + 1000][y + 1000] = n;
		}

		result = 0;
		solution(1);
		memset(map, 0, sizeof(map));
		cout << "#" << tc << " " << result << endl;
	}

	return 0;
}