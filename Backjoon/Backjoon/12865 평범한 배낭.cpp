#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;

int dp[100000];
vector<pair<int, int>> input;

void init()
{
	cin >> N >> K;

	int w, v;

	for (int i = 0; i < N; i++)
	{
		cin >> w >> v;
		input.push_back({ w,v });
	}
}

void solve()
{
	for (int i = 0; i <= N; i++) {
		for (int j = K; j >= 0; j--) {
			if (input[i].first <= j) {
				dp[j] = max(dp[j], dp[j - input[i].first] + input[i].second);
			}
		}
	}

	cout << dp[K];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}