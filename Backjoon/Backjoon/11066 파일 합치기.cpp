#include <iostream>
#include <algorithm>
using namespace std;

int input[501] = { 0 };
int sum[501] = { 0 };
int dp[501][501] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	int k;
	cin >> t;

	while (t--)
	{
		cin >> k;

		for (int i = 1; i <= k; i++)
		{
			cin >> input[i];
			sum[i] = sum[i - 1] + input[i];
		}

		for (int d = 1; d < k; d++)
		{
			for (int start = 1; start + d <= k; start++)
			{
				int end = start + d;
				dp[start][end] = INT_MAX;

				for (int mid = start; mid < end; mid++)
				{
					dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start-1]);
				}
			}
		}

		cout << dp[1][k] << '\n';
	}

	return 0;
}