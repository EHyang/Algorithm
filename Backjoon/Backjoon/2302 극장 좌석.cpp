#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
	vector<bool> seat;
	int dp[41];
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 40; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int N, M, tmp;
	int result = 1;
	int count = 0;
	cin >> N >> M;
	seat.assign(N+1, 0);

	for (int i = 1; i <= M; i++)
	{
		cin >> tmp;
		seat[tmp] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!seat[i]) count++;
		else
		{
			result *= dp[count];
			count = 0;
		}
	}
	if (count != 0) result *= dp[count];

	cout << result;
	return 0;
}