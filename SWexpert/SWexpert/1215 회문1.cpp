#include <iostream>
using namespace std;

int main()
{
	int N, count;
	char table[8][8];
	int result;
	int m, k;

	for (int t = 1; t <= 10; t++)
	{
		result = 0;
		cin >> N;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> table[i][j];
			}

		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j <= 8-N; j++)
			{
				count = 0;
				k = j + N - 1;
				m = j;
				while (count <N/2)
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
						if (count ==N/2)
							result++;
					}
				}
			}
		}


		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i <= 8 - N; i++)
			{
				count = 0;
				k = i + N - 1;
				m = i;
				while (count <N/2)
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
						if (count == N/2)
							result++;
					}
				}
			}
		}

		printf("#%d %d\n", t, result);

	}
}