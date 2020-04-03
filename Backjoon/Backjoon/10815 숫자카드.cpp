#include <iostream>

using namespace std;

bool N[10000001][2] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, temp;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		if (temp >= 0) N[temp][0] = true;
		else N[-temp][1] = true;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;

		if (temp >= 0 && N[temp][0]) cout << "1 ";
		else if (temp < 0 && N[-temp][1]) cout << "1 ";
		else cout << "0 ";
	}

	return 0;
}