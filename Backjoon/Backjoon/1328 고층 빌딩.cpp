#include <iostream>

using namespace std;

int N, L, R;

long long dp[101][101][101];

long long sol = 1000000007;

void init()
{
	cin >> N >> L >> R;

	dp[1][1][1] = 1;
}

void solve()
{
	for (int n = 2; n <= N; n++)
	{
		for (int l = 1; l <= L; l++)
		{
			for (int r = 1; r <= R; r++)
			{
				if (r == 1 && l == 1)
				{
					dp[n][l][r] = 0;
				}
				else
				{
					dp[n][l][r] = dp[n - 1][l][r - 1] % sol + dp[n - 1][l - 1][r] % sol + (dp[n - 1][l][r] * (n - 2)) % sol;
				}
				//cout << "dp[" << n << "][" << l << "][" << r << "] = dp[" << n - 1 << "][" << l << "][" << r - 1 << "] % sol + dp[" << n - 1 << "][" << l - 1 << "][" << r << "] % sol + (dp[" << n - 1 << "][" << l << "][" << r << "] * (" << n - 2 << ")) % sol = " << dp[n][l][r] << endl;
			}
		}
	}

	cout << dp[N][L][R]%sol;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}