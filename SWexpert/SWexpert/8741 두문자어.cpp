#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, testcase = 1;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s, tmp, ans;
		stringstream ss;
		getline(cin, s);

		ss.str(s);
		while (ss >> tmp)
		{
			ans += tmp[0] - 32;
		}
		cout << "#" << testcase++ << " " << ans << '\n';
	}
	return 0;
}
