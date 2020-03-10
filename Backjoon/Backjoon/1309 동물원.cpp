#include <iostream>

using namespace std;

int dp[100001][3]; // 0 ¾Õ

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = dp[i - 1][0] % 9901 + dp[i - 1][2] % 9901;
		dp[i][2] = dp[i - 1][0] % 9901 + dp[i - 1][1] % 9901;
	}

	int answer = dp[N][0] % 9901 + dp[N][1] % 9901 + dp[N][2] % 9901;

	cout << answer%9901;
	return 0;
}