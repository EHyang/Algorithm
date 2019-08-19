#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

vector<long long> P;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	P.assign(101, 1);

	for (int i = 4; i <= 100; i++)
	{
		P[i] = P[i - 2] + P[i - 3];
	}

	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;

		cout << P[N] << endl;
	}

	return 0;
}