#include <iostream>

using namespace std;

int T, k;
int dp[10001];
pair<int, int> coin[100];

void init()
{
	cin >> T >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> coin[i].first >> coin[i].second;
	}

	dp[0] = 1;
}

void solve()
{
	for (int i = 0; i < k; i++)
	{
		int val = coin[i].first;
		int cnt = coin[i].second;

		for (int j = T; j >= 0; j--)
		{
			for (int x = 1; x <= cnt && j >= val * x; x++)
			{
				dp[j] = dp[j] + dp[j - val * x];
			}
		}
	}

	cout << dp[T];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}