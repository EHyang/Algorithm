#include <iostream>

using namespace std;

int main()
{
	int N;
	int a, b;
	int idx = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;

		if (a == idx)
		{
			idx = b;
		}
		else if (b == idx)
		{
			idx = a;
		}
	}
	cout << idx;

	return 0;
}