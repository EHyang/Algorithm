#include <iostream>
#include <string>

using namespace std;

int main()
{
	string day[] = { "SUN", "MON","TUE","WED","THU","FRI","SAT" };
	int count = 0;
	int x, y;

	cin >> x >> y;

	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= 31; j++)
		{
			count++;
			if (i == x && j == y) break;
			else if (i == 2 && j == 28) break;
			else if (i == 4 || i == 6 || i == 9 || i == 11)
			{
				if (j == 30) break;
			}
		}
	}
	cout << day[count % 7];
}