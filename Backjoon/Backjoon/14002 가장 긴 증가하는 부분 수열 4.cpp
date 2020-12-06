#include <iostream>
#include <vector>

using namespace std;

int N, max_idx;

vector<int> arr;
vector<int> dp;
vector<vector<int>> idx;

void init()
{
	int tmp;
	
	cin >> N;

	idx.assign(N, dp);
	dp.assign(N, 1);
	
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;

		arr.push_back(tmp);
	}
}

void solve()
{
	int max = 1;
	max_idx = 0;
	idx[0].push_back(0);

	dp[0] = 1;

	for (int i = 1; i < N; i++)
	{
		bool check = true;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] > arr[j])
			{
				check = false;
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					idx[i] = idx[j];
					idx[i].push_back(i);

					if (dp[i] > max)
					{
						max = dp[i];
						max_idx = i;
					}
				}
			}
		}
		if (check) idx[i].push_back(i);
	}

	cout << idx[max_idx].size() << endl;
	for (auto a : idx[max_idx])
	{
		cout << arr[a] << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}