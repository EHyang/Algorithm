#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	bool z, o, t, th, f;
	z = o = t = th = f = false;

	int input;

	for (int i = 0; i < 5; i++)
	{
		cin >> input;

		int mod = input % 5;
		if (mod < 0) mod += 5;

		switch (mod)
		{
		case 0:
			z = true;
			break;
		case 1:
			o = true;
			break;
		case 2:
			t = true;
			break;
		case 3:
			th = true;
			break;
		case 4:
			f = true;
			break;
		default:
			break;
		}
	}

	if (z&o&t&th&f) cout << "yes";
	else cout << "no";

	return 0;
}