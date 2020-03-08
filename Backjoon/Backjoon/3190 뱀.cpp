#include <iostream>
#include <deque>

using namespace std;
deque <pair<int, char>> q;
int board[101][101];
int direct[4][2] = { {2,3},{3,2},{1,0},{0,1} };
int snake_x = 1, snake_y = 1;
int N, K, L, X, dir = 0;
char C;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 }; // 0 ¿À 1 ¿Þ 2 À§ 3¾Æ·¡

void initial()
{
	int x, y;
	cin >> N >> K;
	board[1][1] = 1; // ¹ì 1
	for (int i = 0; i < K; i++)
	{
		cin >> x >> y;
		board[x][y] = -1; // »ç°ú -1
	}

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		cin >> X >> C;
		q.push_back({ X,C });
	}
}

void print()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%2d ",board[i][j]);
		}
		cout << endl;
	}
}

bool chk(int x, int y)
{
	if (x > 0 && x <= N && y > 0 && y <= N)
	{
		if (board[x][y] != 1)
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int time = 0;
	initial();

	deque<pair<int, int>> snake;
	snake.push_back({ 1,1 });

	while (!snake.empty())
	{
		time++;
		int nx = snake_x + dx[dir];
		int ny = snake_y + dy[dir];

		if (chk(nx, ny))
		{
			if (board[nx][ny] == -1)
			{
				snake.push_front({ nx,ny });
			}
			else
			{
				snake.push_front({ nx,ny });
				board[snake.back().first][snake.back().second] = 0;
				snake.pop_back();
			}
			board[nx][ny] = 1;
			snake_x = nx;
			snake_y = ny;
		}
		else break;

		if (!q.empty() && time == q.front().first)
		{
			char tmp = q.front().second;
			q.pop_front();

			if (tmp == 'L')
			{
				dir = direct[dir][0];
			}
			else if (tmp == 'D')
			{
				dir = direct[dir][1];
			}
		}
		//cout << time << endl;
		//print();
	}

	cout << time;
	return 0;
}