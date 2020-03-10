#include <iostream>

using namespace std;

int dp[201][201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		dp[i][1] = 1;
	}
	for (int i = 1; i <= K; i++)
	{
		dp[1][i] = i;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= K; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}

	cout << dp[N][K]%1000000000;
	return 0;
}