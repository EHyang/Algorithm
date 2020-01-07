#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
	{
		ll tmp;

		cin >> tmp;

		tmp /= 2;

		tmp *= tmp;

		cout << "#" << tc << " " << tmp << '\n';
	}
	return 0;
}