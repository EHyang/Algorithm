#include <iostream>
#include <algorithm>

using namespace std;

int maze[1001][1001] = { 0 };
int dp[1001][1001] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> maze[i][j];
		}
	}
	dp[1][1] = maze[1][1];
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1])) + maze[i][j];
		}
	}

	cout << dp[N][M];

	return 0;
}