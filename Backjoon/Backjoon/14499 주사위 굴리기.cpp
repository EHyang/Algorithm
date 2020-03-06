#include <iostream>

using namespace std;

int dice[7];
int map[21][21];
int command[1001];

int dx[] = { 0,0,0,-1,1 }; // 1 µ¿ 2 ¼­ 3 ºÏ 4 ³²
int dy[] = { 0,1,-1,0,0 };

void Play(int dir)
{
	int tmp;
	switch (dir)
	{
	case 1:
		tmp = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = tmp;
		break;
	case 2:
		tmp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = tmp;
		break;
	case 3:
		tmp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = tmp;
		break;
	case 4:
		tmp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = tmp;
		break;
	default:
		break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, K, x, y;

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		cin >> command[i];
	}

	for (int i = 0; i<K; i++)
	{
		int cmd = command[i];

		x = x + dx[cmd];
		y = y + dy[cmd];

		if (x >= 0 && x < N && y >= 0 && y < M)
		{
			Play(cmd);
			if (map[x][y] == 0) map[x][y] = dice[1];
			else
			{
				dice[1] = map[x][y];
				map[x][y] = 0;
			}

			cout << dice[6] << endl;
		}
		else
		{
			x = x - dx[cmd];
			y = y - dy[cmd];
		}
	}

	return 0;
}