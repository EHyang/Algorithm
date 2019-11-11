#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;


int N, W, H;
int ans = 1000;
int map[15][12] = { 0 };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void copy(int(*a)[12], int(*b)[12])
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}
bool check_range(int x, int y) {
	if (x >= 0 && y >= 0 && x < H && y < W)
		return true;
	else
		return false;

}
void drop_down()
{
	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 1; j--) {
			for (int k = j - 1; k >= 0; k--) {
				if (map[j][i] != 0) break;
				if (map[k][i] != 0) {
					map[j][i] = map[k][i];
					map[k][i] = 0;
					break;
				}
			}
		}
	}
}

void boom(int x, int y)
{
	if (!map[x][y]) return;
	int range = map[x][y];
	map[x][y] = 0;
	for (int r = 0; r < range; r++)
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i] * r;
			int ny = y + dy[i] * r;

			if (check_range(nx,ny))
			{
				if (map[nx][ny] != 0)
					boom(nx, ny);
			}
		}
	}
}

void solve(int n)
{
	int copy_map[15][12] = { 0 };
	copy(map, copy_map);
	if (n == N)
	{
		int cnt = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (map[i][j] != 0) cnt++;
			}
		}

		ans = ans > cnt ? cnt : ans;

		return;
	}

	for (int i = 0; i < W; i++)
	{
		int x = 0, y = i;
		while (map[x][y] == 0 && check_range(x,y))
			x++;
		boom(x, y);
		drop_down();
		solve(n + 1);
		copy(copy_map, map);
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test)
	{
		ans = 1000;
		cin >> N >> W >> H;

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> map[i][j];
			}
		}

		solve(0);

		cout << "#" << test << " " << ans << endl;

	}
	return 0;
}

