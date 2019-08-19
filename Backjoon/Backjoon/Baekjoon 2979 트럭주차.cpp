#include <iostream>

using namespace std;

int main()
{
	int time[101] = { 0 };
	int begin, end;
	int begin_min=100, end_max=0;
	int costA, costB, costC;
	int cost = 0;

	cin >> costA >> costB >> costC;

	for (int car = 0; car < 3; car++)
	{
		cin >> begin >> end;

		if (begin < begin_min) begin_min = begin;
		if (end > end_max) end_max = end;

		for (int i = begin; i < end; i++)
		{
			time[i]++;
		}
	}

	for (int i = begin_min; i <= end_max; i++)
	{
		if (time[i] == 1)
			cost += costA;
		else if (time[i] == 2)
			cost += costB * 2;
		else if (time[i] == 3)
			cost += costC * 3;
	}

	cout << cost;
}