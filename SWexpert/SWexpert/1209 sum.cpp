#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> result;
	for (int test = 1; test <= 10; test++)
	{
		int arr[100][100] = { 0 };
		int max = 0;
		int sum = 0;
		int sumD = 0;
		int t;
		cin >> test;
		for (int i = 0; i < 100; i++)
		{
			sum = 0;

			for (int j = 0; j < 100; j++)
			{
				cin >> arr[i][j];
				sum += arr[i][j];
				if (i == j)
					sumD += arr[i][j];
			}
			if (sum > max)
				max = sum;
			if (sumD > max)
				max = sumD;
		}

		for (int j = 0; j < 100; j++)
		{
			sum = 0;
			for (int i = 0; i < 100; i++)
			{
				sum += arr[i][j];

			}
			if (sum > max)
				max = sum;
		}
		sum = 0;
		for (int i = 99; i >= 0; i--)
		{
			sum += arr[i][99 - i];
		}
		if (sum > max)
			max = sum;

		result.push_back(max);
	}

	for (int i = 0; i < 10; i++)
	{
		printf("#%d %d\n",i+1, result[i]);
	}
}