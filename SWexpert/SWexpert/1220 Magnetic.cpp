#include <iostream>

using namespace std;

#define ccc 100

int main()
{
	for (int t = 1; t <= 10; t++)
	{
		int table[ccc][ccc];
		int check_N[ccc] = { 0 };
		int check_S[ccc] = { 0 };
		int check = 1;
		int count = 0;
		int temp;

		cin >> temp;
		for (int i = 0; i < ccc; i++)
		{
			for (int j = 0; j < ccc; j++)
			{
				cin >> table[i][j];
				if (table[i][j] == 1)
					check_N[j]++;
				else if (table[i][j] == 2 && check_N[j] == 0)
				{
					table[i][j] = 0;
				}
			}
		}

		for (int j = ccc - 1; j >= 0; j--)
		{
			for (int i = ccc - 1; i >= 0; i--)
			{
				if (table[i][j] == 2)
					check_S[j]++;
				else if (table[i][j] == 1 && check_S[j] == 0)
				{
					table[i][j] = 0;
				}
			}
		}

		for (int j = 0; j < ccc; j++)
		{
			for (int i = 0; i < ccc; i++)
			{
				if (table[i][j] == 1)
					check = 2;
				else if (table[i][j] == 2 && check == 2)
				{
					count++;
					check = 1;
				}
			}
		}

		printf("#%d %d\n",t, count);
	}
}