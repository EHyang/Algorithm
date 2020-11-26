#include <iostream>
#include <vector>

using namespace std;

vector<int> arr, dp;

int N, answer;

void init()
{
	cin >> N;

	arr.assign(N, 0);
	dp.assign(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

void solve()
{
	dp[0] = arr[0];
	answer = dp[0];

	for (int i = 1; i < N; i++)
	{
		int m = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] > arr[j])
			{
				m = dp[j] > m ? dp[j] : m;
			}
		}
		dp[i] = m + arr[i];
		answer = dp[i] > answer ? dp[i] : answer;
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