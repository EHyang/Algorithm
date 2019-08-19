#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int result = 0;
	int dp[1001][10];

	cin >> N;

	for (int i = 0; i <= 9; i++) dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			dp[i][j] = 0;
			for (int k = 0; k <= j; k++)
				dp[i][j] += dp[i-1][k];

			dp[i][j] %= 10007;
		}
	}

	for (int i = 0; i <= 9; i++)
		result += dp[N][i];

	cout << result % 10007;
}