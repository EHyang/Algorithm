#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long input_K[10001];
	long long K, N;
	long long start = 1, end = 0;
	long long mid, count, result;
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> input_K[i];
		if (end < input_K[i]) end = input_K[i];
	}

	for (;start<=end;)
	{
		count = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < K; i++)
		{
			count += input_K[i] / mid;
		}

		if (count >= N)
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