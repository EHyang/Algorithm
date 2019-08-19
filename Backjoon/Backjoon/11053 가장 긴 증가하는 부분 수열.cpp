#include <iostream>
#include <vector>

using namespace std;

vector<int> A;
vector<int> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	int tmp;
	int count = 0, max = 0;

	cin >> N;

	A.assign(N, 0);
	dp.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	dp[0] = 1;

	for (int i = 1; i < N; i++)
	{
		max = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (A[i] > A[j])
			{
				if (max < dp[j] + 1) max = dp[j] + 1;
			}
		}
		dp[i] = max;
	}

	max = 0;
	for (int i = 0; i < N; i++)
	{
		if (dp[i] > max) max = dp[i];
	}

	cout << max;
	return 0;
}