#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int map[1001][1001];
int result[1001][1001][2] = { 0 };

queue<pair<pair<int,int>,int>> bfs;

void myPush(int x, int y, int c)
{
	bfs.push(make_pair(make_pair(x, y), c));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	char tmp;
	int answer = -1;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
	}
	myPush(1, 1, 0);
	result[1][1][0] = 1; // xx0 안부수고 온거 xx1 부수고 온거
	while (!bfs.empty())
	{
		int x = bfs.front().first.first;
		int y = bfs.front().first.second;
		int check = bfs.front().second;
		bfs.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 1 && ny >= 1 && nx <= N && ny <= M)
			{
				if (map[nx][ny] == 1 && check == 0)
				{
					result[nx][ny][1] = result[x][y][check] + 1; // 안부수고 도착한애들
					myPush(nx, ny, 1);
				}
				else if (map[nx][ny] == 0 && result[nx][ny][check] == 0)
				{
					result[nx][ny][check] = result[x][y][check] + 1; // 부수고 오든가 말든가
					myPush(nx, ny, check);
				}
			}
		}
	}

	if (result[N][M][0] | result[N][M][1])
	{
		if (result[N][M][0] != 0 && result[N][M][1] != 0)
		{
			answer = result[N][M][0] > result[N][M][1] ? result[N][M][1] : result[N][M][0];
		}
		else
		{
			answer = result[N][M][0] == 0 ? result[N][M][1] : result[N][M][0];
		}
	}

	cout << answer;

	return 0;
}