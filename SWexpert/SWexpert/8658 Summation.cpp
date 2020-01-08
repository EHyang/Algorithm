#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	cin.ignore();
	for (int tc = 1; tc <= t; tc++)
	{
		string input, tmp;
		stringstream ss;

		getline(cin, input);
		ss.str(input);
		int max = -1;
		int min = 9999999;
		while (ss >> tmp)
		{
			int ans = 0;
			for (int i = 0; i < tmp.size(); i++)
			{
				ans += tmp[i] - 48;
			}

			if (ans > max) max = ans;
			if (ans < min) min = ans;
		}


		cout << "#" << tc << " " << max << " " << min << '\n';
	}

	return 0;
}