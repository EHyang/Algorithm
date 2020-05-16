#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
vector<int> op;

int N, Max_Value, Min_Value;

void calc()
{
	int res, idx;

	do {
		res = num[0];
		idx = 0;
		for (int i = 1; i < num.size(); i++)
		{
			switch (op[idx])
			{
			case 0:
				res += num[i];
				idx++;
				break;
			case 1:
				res -= num[i];
				idx++;
				break;
			case 2:
				res *= num[i];
				idx++;
				break;
			case 3:
				res /= num[i];
				idx++;
				break;
			default:
				break;
			}
		}

		Max_Value = max(Max_Value, res);
		Min_Value = min(Min_Value, res);

	} while (next_permutation(op.begin(), op.end()));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int test, tmp;
	cin >> test;

	for (int tc = 1; tc <= test; tc++)
	{
		cin >> N;

		Max_Value = -100000001;
		Min_Value = 100000001;

		for (int i = 0; i < 4; i++)
		{
			cin >> tmp;
			for (int j = 0; j < tmp; j++)
				op.push_back(i);
		}

		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			num.push_back(tmp);
		}

		calc();

		cout << "#" << tc << " " << Max_Value - Min_Value << endl;

		op.clear();
		num.clear();
	}

	return 0;
}