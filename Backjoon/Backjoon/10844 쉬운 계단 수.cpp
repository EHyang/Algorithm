#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	long long result = 0;
	long long dp[101][10];

	cin >> N;

	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}

	for (long long i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j > 0 && j < 9)
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			dp[i][j] %= 1000000000;
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		result += dp[N][i];
	}
	
	cout << result%1000000000;
}