#include <iostream>

using namespace std;

long long game[101][101];
long long dp[101][101] = { 0 };

long long dx[] = { 0,1 };
long long dy[] = { 1,0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long N;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> game[i][j];
		}
	}

	dp[1][1] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int val = game[i][j];
			if (val == 0) break;
			int nx = val + i;
			int ny = val + j;
			if (nx <= N) dp[nx][j] += dp[i][j];
			if (ny <= N) dp[i][ny] += dp[i][j];
		}
	}
	
	cout << dp[N][N];
}