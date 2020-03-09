#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int hobit[9];
	int idx_f = 0;
	int idx_s = idx_f;
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> hobit[i];
	}

	while (sum != 100)
	{
		sum = 0;
		idx_s++;
		if (idx_s == 9)
		{
			idx_f++;
			idx_s = idx_f + 1;
		}
		for (int i = 0; i < 9; i++)
		{
			if (i != idx_f && i != idx_s)
				sum += hobit[i];
		}
	}

	int idx = 0;
	int re[7];

	for (int i = 0; i < 9; i++)
	{
		if (i != idx_f && i != idx_s)
			re[idx++] = hobit[i];
	}
	sort(re, re + 7);

	for (int i = 0; i < 7; i++)
	{
		cout << re[i] << endl;
	}
	return 0;
}