#include <iostream>
#include <string>
#define endl '\n'

typedef long long ll;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, test = 1;
	ll K;
	int result;

	cin >> T;
	
	while (T--)
	{
		cin >> K;
		ll N = K - 1;
		result = 0;
		while (N > 0)
		{
			if (N % 2 == 1) N = (N - 1) / 2;
			if (N % 4 == 0)
			{
				result = 0;
				break;
			}
			else if (N % 2 == 0) {
				result = 1;
				break;
			}
		}

		cout << "#" << test++ << " " << result << endl;
	}

	return 0;
}