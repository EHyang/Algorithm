#include <iostream>
using namespace std;

char table[100][100];

int solve(int N)
{
	int count;
	int m, k;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j <= 100 - N; j++)
		{
			count = 0;
			k = j + N - 1;
			m = j;
			while (count <N / 2)
			{
				if (table[i][m] != table[i][k])
				{
					break;
				}
				else
				{
					m++;
					count++;
					k--;
					if (count == N / 2)
						return N;
				}
			}
		}
	}

	for (int j = 0; j < 100; j++)
	{
		for (int i = 0; i <= 100 - N; i++)
		{
			count = 0;
			k = i + N - 1;
			m = i;
			while (count <N / 2)
			{
				if (table[m][j] != table[k][j])
				{
					break;
				}
				else
				{
					m++;
					count++;
					k--;
					if (count == N / 2)
						return N;
				}
			}
		}
	}

	return 0;
}

int main()
{

	int temp;

	int result;
	int m, k;

	for (int t = 1; t <= 10; t++)
	{
		result = 0;
		cin >> temp;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> table[i][j];
			}

		}

		for (int i = 100; i > 1; i--)
		{
			result = solve(i);
			if (result !=0)
			{
				break;
			}
		}

		printf("#%d %d\n", t, result);

	}
}