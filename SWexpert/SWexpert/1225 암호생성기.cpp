#include <iostream>
#include <vector>

using namespace std;

int main()
{
	for (int t = 1; t <= 10; t++)
	{
		vector <int> pw;
		int temp, min = 2147483647;
		int minus = 1;
		bool check = true;
		bool fifteen = true;

		cin >>temp;
		for (int i = 0; i < 8; i++)
		{
			cin >> temp;
			pw.push_back(temp);
			if (temp < min)
				min = temp;
			if (temp % 15 == 0)
				fifteen = false;
			if (min - 15 < 1)
				check = false;
		}

		if (check & fifteen)
		{
			temp = min / 15;
			
			for (int i = 0; i < 8; i++)
			{
				pw[i] = pw[i] - (15 * temp);
			}
			while (true)
			{
				temp = pw[0];
				pw.erase(pw.begin());
				if ((temp - minus) <= 0)
				{
					pw.push_back(0);
					break;
				}
				else
					pw.push_back(temp - minus);

				minus++;
				if (minus == 6)
					minus = 1;
			}
		}
		else if (check & !fifteen)
		{
			temp = (min / 15) -1;

			for (int i = 0; i < 8; i++)
			{
				pw[i] = pw[i] - (15 * temp);
			}
			while (true)
			{
				temp = pw[0];
				pw.erase(pw.begin());
				if ((temp - minus) <= 0)
				{
					pw.push_back(0);
					break;
				}
				else
					pw.push_back(temp - minus);

				minus++;
				if (minus == 6)
					minus = 1;
			}
		}
		else
		{
			while (true)
			{
				temp = pw[0];
				pw.erase(pw.begin());
				if ((temp - minus) <= 0)
				{
					pw.push_back(0);
					break;
				}
				else
					pw.push_back(temp - minus);

				minus++;
				if (minus == 6)
					minus = 1;
			}
		}

		printf("#%d ", t);
		for (int i = 0; i < 8; i++)
		{
			printf("%d ", pw[i]);
		}
		printf("\n");
		pw.clear();
	}

	return 0;
}