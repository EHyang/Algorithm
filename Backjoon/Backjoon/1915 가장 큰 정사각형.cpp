#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int rec[1001][1001];
int dp[1001][1001];
int N, M;

void init()
{
	cin >> N >> M;

	string s;

	for (int i = 1; i <= N; i++)
	{
		cin >> s;
		for (int j = 1; j <= M; j++)
		{
			rec[i][j] = dp[i][j] = s[j-1] - '0';
		}
	}
}

void solve()
{
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (rec[i][j] == 0)
			{
				dp[i][j] = 0;
				continue;
			}

			dp[i][j] = min(dp[i-1][j-1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans * ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}