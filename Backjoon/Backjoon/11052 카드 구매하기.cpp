#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dp[1001];
	int P[10001];
	int N;
	int max = -1;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
	}

	dp[1] = P[1];
	
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (dp[i - j] + P[j] > max)
				max = dp[i - j] + P[j];
		}
		dp[i] = max;
		max = -1;
	}

	cout << dp[N];
}