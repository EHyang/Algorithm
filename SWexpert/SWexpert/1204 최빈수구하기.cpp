#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int T;
	int tc;
	vector <int> result;

	cin >> T;

	for (int test = 0; test < T; test++)
	{
		int count[101] = { 0 };
		int MaxFre = 0;
		int MaxSco;
		int tmp;
		cin >> tc;
		for (int i = 0; i < 1000; i++)
		{
			cin >> tmp;
			count[tmp]++;
		}

		for (int i = 0; i < 101; i++)
		{
			if (count[i] >= MaxFre)
			{
				MaxFre = count[i];
				MaxSco = i;
			}
		}
		result.push_back(MaxSco);
	}

	for (int test = 0; test < T; test++)
	{
		printf("#%d %d\n", test + 1, result[test]);
	}
}