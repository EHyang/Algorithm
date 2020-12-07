#include <iostream>

using namespace std;

int dp[17][17][3];
int map[17][17];

int dx[] = { -1,-1,0 };
int dy[] = { -1,0,-1 };

int N;

void init()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}
}

void solve()
{
	int answer = 0;
	
	dp[1][2][0] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 3; j <= N; j++)
		{
			if (map[i][j] == 0)
			{
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];

				if (map[i - 1][j] == 0 && map[i][j - 1] == 0)
				{
					dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
				}

				dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		answer += dp[N][N][i];
	}

	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}