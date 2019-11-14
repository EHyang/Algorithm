#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	int a, b;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;

		v.push_back({ b,a });
	}

	sort(v.begin(), v.end());

	int cnt = 1;

	int end = v[0].first;

	for (int i = 1; i < N; i++)
	{
		if (v[i].second >= end)
		{
			cnt++;
			end = v[i].first;
		}
	}

	cout << cnt;
	return 0;
}