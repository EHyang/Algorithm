#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, M;
	long long h[1000001];
	long long start = 1, end = 0;
	long long mid, result = 0, sum;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> h[i];
		if (end < h[i]) end = h[i];
	}

	for (; start <= end; )
	{
		sum = 0;
		mid = (start + end) / 2;
		for (long long i = 0; i < N; i++)
		{
			if (h[i] < mid) continue;
			else sum += h[i] - mid;
		}

		if (sum >= M)
		{
			result = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << result;

	return 0;
}