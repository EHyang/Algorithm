#include <iostream>

using namespace std;

int dp[1000001] = { 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;

	cin >> N;

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[N];
	return 0;
}