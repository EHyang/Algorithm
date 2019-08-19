#include <iostream>

using namespace std;

int main()
{
	bool a = true;
	int year = 0;
	int E, S, M;
	int e = 1, s = 1, m = 1;
	cin >> E >> S >> M;

	while (a)
	{
		year++;
		if (e == E && s == S && M == m) a = false;
		e++; s++; m++;

		if (e == 16) e = 1;
		if (s == 29) s = 1;
		if (m == 20) m = 1;
	}
	cout << year;
}