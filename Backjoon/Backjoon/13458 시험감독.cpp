#include <iostream>

using namespace std;
typedef long long ll;

ll A[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll N, B, C;

	cin >> N;

	for (ll i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	cin >> B >> C;

	ll cmd, sur_cmd = 0;

	cmd = N;

	for (ll i = 1; i <= N; i++)
	{
		A[i] -= B;
		if (A[i] <= 0) continue;
		if (A[i] % C != 0) sur_cmd += (A[i] / C + 1);
		else sur_cmd += (A[i] / C);
	}

	ll answer = cmd + sur_cmd;

	cout << answer;
	return 0;
}