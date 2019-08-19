#include <iostream>

using namespace std;

int main()
{
	int testcase;
	cin >> testcase;

	for (int i = 1; i <= testcase; i++)
	{
		int p, q, r, s, w;
		int cost1, cost2;
		int result;

		cin >> p >> q >> r >> s >> w;

		cost1 = p * w;

		if (w <= r)
		{
			cost2 = q;
		}
		else
		{
			cost2 = q + (w - r)*s;
		}

		if (cost1 > cost2) result = cost2;
		else result = cost1;

		printf("#%d %d\n", i, result);
	}
}