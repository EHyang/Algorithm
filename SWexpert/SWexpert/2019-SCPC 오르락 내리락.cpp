#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
int Answer;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	int A, B;
	vector<int> result;
	result.assign(1000000, 0);

	cin >> T;

	result[1] = 0;
	result[2] = 1;
	result[3] = 3;

	for (int test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> A >> B;
		for (int i = 4; i <= B; i++)
		{
			if (result[B] != 0) break;
			if (i % 2 == 0 && result[i] == 0)
			{
				result[i] = result[i / 2] + 1;
			}
			else if (i % 2 == 1 && result[i] == 0)
			{
				result[i + 1] = result[(i + 1) / 2] + 1;
				result[i] = result[i + 1] + 1;
			}
		}

		for (int j = A; j <= B; j++)
		{
			Answer += result[j];
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}