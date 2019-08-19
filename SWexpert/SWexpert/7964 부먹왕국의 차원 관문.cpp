#include <iostream>
#include <vector>
using namespace std;

vector<int> nation;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, test = 1;
	cin >> T;
	while (T--)
	{
		int N, D, tmp;
		cin >> N >> D;
		int count = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			nation.push_back(tmp);
		}

		for (int i = 0; i < N; i++)
		{
			bool right = false;
			int idx;

			if (i == N - 1) right = true;

			for (int k = i + 1; k <= i + D; k++)
			{
				if (k >= N) break;

				if (nation[k] == 1) right = true;
				idx = k;
			}
			if (i == 0 && nation[i] == 0)
			{
				if (idx == i + D)
				{
					nation[0] = 1;
					count++;
				}
			}
			if (!right)
			{
				nation[idx] = 1;
				count++;
			}
		}

		cout << "#" << test++ << " " << count << '\n';
		nation.clear();
	}
	return 0;
}