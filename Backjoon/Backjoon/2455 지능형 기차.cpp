#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int sum = 0, max = -1;
	int in, out;

	for (int i = 0; i < 4; i++)
	{
		cin >> out >> in;
		sum -= out;
		sum += in;

		if (sum >= max)
			max = sum;
	}

	cout << max;
	return 0;
}