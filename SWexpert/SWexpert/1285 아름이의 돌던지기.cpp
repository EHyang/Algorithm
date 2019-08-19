#include <iostream>
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;

	for (int i = 1; i <= testcase; i++)
	{
		int n, temp;
		int min = 100001;
		int count = 1;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;

			temp = abs(temp);

			if (temp < min)
			{
				min = temp;
				count = 1;
			}
			else if (temp == min)
				count++;
		}

		printf("#%d %d %d\n", i, min, count);
	}
}