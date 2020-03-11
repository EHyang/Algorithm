#include <iostream>

using namespace std;

int snail[101][101];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

void make_snail(int N)
{
	int t = N-1;
	int count = 0;
	int dir = 0;
	int idx = 0;
	int x = 1, y = 1;

	snail[1][1] = 1;
	for (int i = 2; i <= N * N; i++)
	{
		x = x + dx[dir];
		y = y + dy[dir];

		snail[x][y] = i;

		idx++;

		if (idx == t)
		{
			if (t == N-1)
			{
				idx = 0;
				dir = (dir + 1 >= 4 ? 0 : dir + 1);
				count++;
				if (count == 3)
				{
					count = 0;
					t--;
				}
			}
			else
			{
				idx = 0;
				dir = (dir + 1 >= 4 ? 0 : dir + 1);
				count++;
				if (count == 2)
				{
					count = 0;
					t--;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc, N;

	cin >> tc;

	for (int testcase = 1; testcase <= tc; testcase++)
	{
		cin >> N;
		make_snail(N);

		cout << "#" << testcase << endl;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << snail[i][j] << " ";
			}
			cout << endl;
		}

	}
	return 0;
}