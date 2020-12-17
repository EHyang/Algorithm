#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000][3];
int max_dp[3], min_dp[3], tmp[3];
int N;

void copy(int a[3], int b[3])
{
	for (int i = 0; i < 3; i++)
	{
		a[i] = b[i];
	}
}

void init()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	max_dp[0] = min_dp[0] = arr[0][0];
	max_dp[1] = min_dp[1] = arr[0][1];
	max_dp[2] = min_dp[2] = arr[0][2];
}

void solve()
{
	int max_val, min_val;

	for (int i = 1; i < N; i++)
	{
		copy(tmp, max_dp);

		tmp[0] = max(max_dp[0], max_dp[1]) + arr[i][0];
		tmp[1] = max(max_dp[0], max(max_dp[1], max_dp[2])) + arr[i][1];
		tmp[2] = max(max_dp[1], max_dp[2]) + arr[i][2];

		copy(max_dp, tmp);
		copy(tmp, min_dp);

		tmp[0] = min(min_dp[0], min_dp[1]) + arr[i][0];
		tmp[1] = min(min_dp[0], min(min_dp[1], min_dp[2])) + arr[i][1];
		tmp[2] = min(min_dp[1], min_dp[2]) + arr[i][2];

		copy(min_dp, tmp);
	}

	max_val = max(max_dp[0], max(max_dp[1], max_dp[2]));
	min_val = min(min_dp[0], min(min_dp[1], min_dp[2]));

	cout << max_val << " " << min_val;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}