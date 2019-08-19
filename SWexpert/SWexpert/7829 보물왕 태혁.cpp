#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
	int t, count = 1, p,tmp;

	cin >> t;
	while (t--)
	{
		int min = 1000000;
		int max = 0;

		cin >> p;

		while (p--)
		{
			cin >> tmp;
			if (tmp >= max) max = tmp;
			if (tmp <= min) min = tmp;
		}
		cout << "#" << count++ << " " << min * max << endl;
	}
}
