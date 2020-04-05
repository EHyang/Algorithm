#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> toilet;

bool check(int s, int e, int n)
{
	return n >= s && n <= e;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int start, end;
	int count = 0;
	int max = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		toilet.push_back({ start,end-1 });
	}
	for (int i = 1; i <= 150; i++)
	{
		count = 0;
		for (int j = 0; j < N; j++)
		{
			if (check(toilet[j].first, toilet[j].second, i))
				count++;
		}

		max = max < count ? count : max;
	}

	cout << max;

	return 0;
}