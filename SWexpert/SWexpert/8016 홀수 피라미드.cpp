#include <iostream>

using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	int testcase = 1;

	while (t--)
	{
		ll input;
		cin >> input;

		ll left=1, right=1;

		if (input != 1)
		{
			left += (input - 1)*(4 + 4 * (input - 2)) / 2;
			right = left + (4 * (input - 1));
		}
		
		cout <<"#"<<testcase++<<" "<< left << " " << right << endl;
	}

	return 0;
}