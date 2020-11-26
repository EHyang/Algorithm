#include <iostream>

using namespace std;

int dp[12];

void init()
{
	for (int i = 0; i < 12; i++)
	{
		dp[i] = 0;
	}
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
}

void solve(int n)
{
	init();

	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	cout << dp[n] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc, num;

	cin >> tc;

	for (; tc >= 1; tc--)
	{
		cin >> num;
		solve(num);
	}

	return 0;
}