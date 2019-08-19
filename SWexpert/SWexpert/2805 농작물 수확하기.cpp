#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int count = 1;
	int t;
	int N;
	int temp;
	int M;
	int result;

	string num;

	vector<int> row;
	vector<vector<int>> col;
	cin >> t;
	while (t--)
	{
		result = 0;
		cin >> N;
		M = (N / 2);

		for (int i = 0; i < N; i++)
		{
			cin >> num;
			for (int j = 0; j < N; j++)
			{
				temp = num[j] - 48;
				row.push_back(temp);
				if (i <= M)
				{
					if (M - i <= j && j <= M + i)
					{
						result += temp;
					}
				}
				if (i > M)
				{
					if (i - M <= j && j < N - (i - M))
					{
						result += temp;
					}
				}
			}
			col.push_back(row);
			row.clear();
			num.clear();
		}
		printf("#%d %d\n", count++, result);
		col.clear();
	}
}