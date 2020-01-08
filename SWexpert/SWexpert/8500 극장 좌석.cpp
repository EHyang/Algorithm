#include <iostream>
#include <algorithm>
using namespace std;

int input[10000] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
	{
		int N, tmp;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> input[i];
		}

		sort(input,input+(N));

		int result = 0;

		for (int i = 0; i < N; i++)
		{
			result += input[i];
			result++;
		}
		result += input[N - 1];

		cout << "#" << tc << " " << result << '\n';
	}
	
	return 0;
}