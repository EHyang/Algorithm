#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, t;
	int result = 0;
	int v[501][501] = { 0 };
	int dp[501][501] = { 0 };

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> v[i][j];
		}
	}

	dp[1][1] = v[1][1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + v[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dp[n][i] > result) result = dp[n][i];
	}

	cout << result;

	return 0;
}