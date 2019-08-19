#include <iostream>
#include <set>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	set<int> result;
	int T, count = 1;

	cin >> T;

	while (T--)
	{
		string input;

		cin >> input;

		for (int i = 0; i < input.size(); i++)
		{
			result.insert(input[i] - '0');
		}

		cout << "#" << count++ << " " << result.size() << endl;
		result.clear();
	}

	return 0;
}