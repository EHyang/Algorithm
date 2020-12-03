#include <iostream>
#include <string>

#define LT 0
#define T 1
#define RT 2
#define L 3
#define R 4
#define LB 5
#define B 6
#define RB 7

using namespace std;

int board[9][9] = { 0 };

int dx[] = { -1, -1, -1, 0,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,0,1,-1,0,1 };

int time;

void check(int x, int y)
{
	return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}

void move()
{

}

void init()
{
	string king, stone;

	cin >> king >> stone >> time;

	board[king[1] - '0'][king[0] - 64] = 1;
	board[stone[1] - '0'][stone[0] - 64] = 2;
}

void solve()
{
	string cmd;

	while (time--)
	{
		cin >> cmd;
	}



}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}