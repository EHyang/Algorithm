#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;

	cin >> t;

	for (int tc = 1; tc <= t; tc++)
	{
		int k, tmp;
		int sum = 0;
		cin >> k;

		vector<int> v;

		for (int i = 0; i < k; i++)
		{
			cin >> tmp;

			if (tmp)
			{
				v.push_back(tmp);
			}
			else
			{
				v.pop_back();
			}
		}

		for (auto i : v)
		{
			sum += i;
		}

		cout << "#" << tc << " " << sum << '\n';
	}

	return 0;
}