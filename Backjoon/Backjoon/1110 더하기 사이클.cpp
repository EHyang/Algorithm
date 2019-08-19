#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, d, o, td, to;
	int M;
	int count = 1;

	cin >> N;

	M = N;
	for (;;)
	{
		d = M / 10; // 10의자리
		o = M % 10; // 1의자리

		if (d + o >= 10) to = (d + o) % 10;
		else to = d + o;

		td = o;

		if (N == (td * 10 + to)) break;

		M = (td * 10 + to);
		count++;
	}
	cout << count;
}
