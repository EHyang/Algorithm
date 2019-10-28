#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int want, base = 64, count = 0;

	cin >> want;

	while (want > 0)
	{
		if (base > want)
		{
			base /= 2;
		}
		else
		{
			want -= base;
			base /= 2;
			count++;
		}
	}
	cout << count;

	return 0;
}