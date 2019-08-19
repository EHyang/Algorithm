#include <iostream>
#include <algorithm>

using namespace std;
int coin[101];
int dp[10001];
int main()
{
	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}
	for (int i = 0; i <= k; i++)
	{
		dp[i] = 100001;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{ 
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[k] == 100001) cout << -1;
	else
		cout << dp[k];
}