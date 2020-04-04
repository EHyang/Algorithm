#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int home[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> home[i];
	}

	sort(home, home + N);

	int ans, left = 1;
	int right = home[N - 1];

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int start = home[0];
		int count = 1;

		for (int i = 1; i < N; i++)
		{
			if (home[i] - start >= mid)
			{
				count++;
				start = home[i];
			}
		}

		if (count >= C)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans;
	return 0;
}