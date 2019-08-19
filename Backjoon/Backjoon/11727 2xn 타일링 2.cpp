#include <iostream>

using namespace std;

int main()
{
	int dp[1001][3];//0 세로 1 가로 2 2x2

	int N;

	cin >> N;

	dp[1][0] = 1;
	dp[1][1] = 0;
	dp[1][2] = 0;
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;

	for (int i = 3; i <= N; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2])%10007;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2])%10007;
		dp[i][2] = (dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2])%10007;
	}

	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 10007;
}