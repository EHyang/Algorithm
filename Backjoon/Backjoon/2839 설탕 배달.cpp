#include <iostream>

using namespace std;

int main()
{
	int N;
	int a;
	int sam, oh;
	int result = 0;

	cin >> N;

	oh = N / 5;

	for (;;)
	{
		a = N - (5 * oh);

		sam = a / 3;

		if (5 * oh + 3 * sam == N) break;
		else if (oh != 0) oh--;

		else
		{
			oh = -1;
			sam = 0;
			break;
		}
	}

	cout << oh + sam;
}