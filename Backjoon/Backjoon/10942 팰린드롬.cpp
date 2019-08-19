#include <iostream>
#define endl '\n'

using namespace std;

int dp[2001][2001] = { 0 }; // dp[start][end]
int input[2001] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, S, E;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> input[i];
		dp[i][i] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (input[i] == input[i + 1])
			dp[i][i + 1] = 1;
	}

	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j <= N - i; j++)
		{
			if (input[j] == input[j + i] && dp[j + 1][j + i - 1]) dp[j][j + i] = 1;
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> S >> E;

		cout << dp[S][E] << endl;

	}

	return 0;
}