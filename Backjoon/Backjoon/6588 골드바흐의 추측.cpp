#include <iostream>

using namespace std;

int arr[1000001];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	arr[1] = 1;
	for (int i = 2; i*i <= 1000000; i++) {
		int k = 2;
		if (!arr[i]) {
			while (i*k <= 1000000) {
				arr[i*k] = 1;
				k++;
			}
		}
	}

	int n;
	bool a;

	cin >> n;

	while (n)
	{
		a = true;
		for (int i = 3; i < n; i+=2)
		{
			if (!arr[i] && !arr[n - i])
			{
				cout << n << " = " << i << " + " << n - i << '\n';
				a = false;
				break;
			}
		}
		if (a) cout << "Goldbach's conjecture is wrong.\n";
		cin >> n;
	}

	return 0;
}