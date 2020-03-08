#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, a, b;
	int round = 0;

	cin >> N >> a >> b;

	while (a != b)
	{
		round++;
		if (a % 2)
			a = (a + 1) / 2;
		else
			a = a / 2;

		if (b % 2)
			b = (b + 1) / 2;
		else
			b = b / 2;
	}

	cout << round;

	return 0;
}