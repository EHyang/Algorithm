#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long long result = 0;
	long long dp[91][2];

	cin >> N;

	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0) dp[i][j] = dp[i - 1][0] + dp[i - 1][1];
			if (j == 1) dp[i][j] = dp[i - 1][0];
		}
	}
	result = dp[N][0] + dp[N][1];

	cout << result;
	return 0;
}