#include <iostream>
#include <vector>

using namespace std;

vector<int> input, dp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int max;

	cin >> N;

	input.assign(N, 0);
	dp.assign(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
		dp[i] = input[i];
	}
	max = input[0];
	for (int i = 1; i < N; i++)
	{
		if (dp[i - 1] > 0)
		{
			if (dp[i - 1] + dp[i] > 0)
				dp[i] += dp[i - 1];
		}
		if (dp[i] > max) max = dp[i];
	}

	cout << max; 
}