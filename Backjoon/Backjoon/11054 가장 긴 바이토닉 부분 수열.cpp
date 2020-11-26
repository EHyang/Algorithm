#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<vector<int>> dp;

int N, answer = 0;

void init()
{
	cin >> N;

	arr.assign(N, 1);
	dp.assign(2, arr);

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
			if (arr[i] > arr[j])
			{
				dp[0][i] = dp[0][i] > dp[0][j] + 1 ? dp[0][i] : dp[0][j] + 1;
			}
		}
	}

	for (int i = N - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[1][i] = dp[1][i] > dp[1][j] + 1 ? dp[1][i] : dp[1][j] + 1;
			}
		}
	}

	for (int i = 1; i < N - 1; i++)
	{
		answer = answer > dp[0][i] + dp[1][i] - 1 ? answer : dp[0][i] + dp[1][i] - 1;
	}

	answer = dp[1][0] > answer ? dp[1][0] : answer;
	answer = dp[0][N - 1] > answer ? dp[0][N - 1] : answer;
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