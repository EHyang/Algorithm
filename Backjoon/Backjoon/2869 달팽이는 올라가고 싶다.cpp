#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll A, B, V;
	ll day = 0;

	cin >> A >> B >> V;

	if (V - A <= 0) {
		cout << "1";
		return 0;
	}

	V = V - A;

	ll temp = A - B;
	ll av = V / (temp);

	if (V - (temp * av) > 0)
		day = av + 2;
	else
		day = av + 1;

	cout << day;

	return 0;
}