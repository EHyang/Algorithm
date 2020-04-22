#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		ll x, y;

		cin >> x >> y;

		ll cha = y - x;

		ll sum = 1;
		ll cnt = -1;
		ll last;
		for (ll i = 0; sum<=cha; i += 2)
		{
			last = sum;
			sum += i;
			cnt++;
		}

		ll mid = (sum + last) / 2;

		if (cha >= mid) cnt *= 2;
		else cnt = cnt * 2 - 1;

		cout << cnt << endl;
	}

	return 0;
}