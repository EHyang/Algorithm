#include <iostream>

using namespace std;

int tc;

long long n;

void solve()
{
	cin >> tc;
	while (tc > 0) {
		long long dp[65][11];
		cin >> n;
		if (n == 1) {
			cout << 10 << '\n';
			tc--;
			continue;
		}
		for (int i = 1; i <= 10; i++) {
			dp[1][i] = i;
		}
		for (int i = 2; i < n; i++) {
			dp[i][1] = 1;
			for (int j = 2; j <= 10; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		long long sum = 0;
		for (int i = 1; i <= 10; i++)
			sum += dp[n - 1][i];
		cout << sum << '\n';
		tc--;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();

	return 0;
}
