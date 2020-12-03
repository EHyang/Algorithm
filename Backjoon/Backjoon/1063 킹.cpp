#include <iostream>
#include <string>
#include <map>

using namespace std;

int board[9][9] = { 0 };

int dx[] = { -1, -1, -1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

map<string, int> cmd;
pair<int, int> k, st;

int time;

string King, Stone;

bool check(int x, int y)
{
	return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}

void move(int a)
{
	int nx = k.first + dx[a];
	int ny = k.second + dy[a];

	if (check(nx, ny))
	{
		if (board[nx][ny] == 0)
		{
			board[nx][ny] = 1;
			board[k.first][k.second] = 0;

			k.first = nx; k.second = ny;
		}
		else if (board[nx][ny] == 2)
		{
			int x = st.first + dx[a];
			int y = st.second + dy[a];

			if (check(x, y))
			{
				board[nx][ny] = 1;
				board[x][y] = 2;

				board[k.first][k.second] = 0;
				k.first = nx; k.second = ny;
				st.first = x; st.second = y;
			}
		}
	}
}

void make_answer()
{
	King += (k.second + 64);
	King += (9 - k.first + '0');
	
	Stone += (st.second + 64);
	Stone += (9 - st.first + '0');
}

void init()
{
	string king, stone;

	cin >> king >> stone >> time;

	k.first = 9-(king[1] - '0');
	k.second = king[0] - 64;
	st.first = 9-(stone[1] - '0');
	st.second = stone[0] - 64;

	board[k.first][k.second] = 1;
	board[st.first][st.second] = 2;

	cmd.insert({ "LT", 0 });
	cmd.insert({ "T", 1 });
	cmd.insert({ "RT", 2 });
	cmd.insert({ "L", 3 });
	cmd.insert({ "R", 4 });
	cmd.insert({ "LB", 5 });
	cmd.insert({ "B", 6 });
	cmd.insert({ "RB", 7 });
}

void solve()
{
	string c;

	while (time--)
	{
		cin >> c;

		move(cmd[c]);
	}
	
	make_answer();

	cout << King << endl << Stone;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}