#include <iostream>
#include <vector>

using namespace std;

vector<int> arr, dp;

int N, answer = 1;

void init()
{
	cin >> N;

	arr.assign(N, 0);
	dp.assign(N, 1);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

void solve()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] < arr[j])
			{
				dp[i] = dp[i] < dp[j] + 1 ? dp[j] + 1 : dp[i];
			}
		}
		answer = answer < dp[i] ? dp[i] : answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << answer;

	return 0;
}