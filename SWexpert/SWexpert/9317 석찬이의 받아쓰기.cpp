#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
	{
		int N, count;

		cin >> N;
		count = N;
		string Q, A;
		cin.ignore();

		getline(cin, Q);
		getline(cin, A);

		for (int i = 0; i < Q.size(); i++)
		{
			if (Q[i] != A[i]) count--;
		}

		cout << "#" << tc << " " << count << endl;
	}

	return 0;
}