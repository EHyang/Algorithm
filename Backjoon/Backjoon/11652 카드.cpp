#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, tmp;
	long long max = 0, count = 1;
	long long max_value;
	vector<long long> input;


	cin >> N;
	for (long long i = 0; i < N; i++)
	{
		cin >> tmp;
		input.push_back(tmp);
	}

	sort(input.begin(), input.end());

	for (long long i = 1; i < N; i++)
	{
		if (input[i] == input[i - 1])
		{
			count++;
		}
		else
		{
			if (max < count)
			{
				max = count;
				max_value = input[i - 1];
			}
			count = 1;

		}
	}
	if (count > max)
	{
		max_value = input[N-1];
	}
	cout << max_value;
}