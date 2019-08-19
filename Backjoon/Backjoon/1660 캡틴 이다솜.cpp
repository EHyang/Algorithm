#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<int> four;
vector<int> dp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, tmp = 0, tri = 0;
	cin >> N;
	for (int i = 1; i <= 300000; i++)
	{
		tri += i;
		tmp += tri;
		if (tmp > 300000) break;
		four.push_back(tmp);
	}

	dp.assign(300001, 300001);
	dp[0] = 0;
	for (int i = 0; i < four.size(); i++)
	{
		for (int j = four[i]; j <= N; j++)
		{
			dp[j] = min(dp[j], dp[j - four[i]] + 1);
		}
	}

	cout << dp[N];

	return 0;
}