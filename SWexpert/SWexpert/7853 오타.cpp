#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t;
	string input;
	long long result = 1;
	int Test = 1;
	cin >> t;

	while (t--)
	{
		cin >> input;
		if (input[0] != input[1]) result *= 2;
		if (input[input.size() - 2] != input[input.size() - 1]) result *= 2;
		for (int i = 1; i < input.size()-1; i++)
		{
			if (input[i - 1] != input[i + 1] && input[i - 1] != input[i] && input[i+1] != input[i])
			{
				result *= 3;
				result %= 1000000007;
			}
			else if (input[i - 1] == input[i + 1] && input[i - 1] != input[i])
			{
				result *= 2;
				result %= 1000000007;
			}
			else if (input[i - 1] != input[i + 1] && input[i - 1] == input[i])
			{
				result *= 2;
				result %= 1000000007;
			}
			else if (input[i - 1] != input[i + 1] && input[i + 1] == input[i])
			{
				result *= 2;
				result %= 1000000007;
			}
		}

		cout << "#" << Test++ << " " << result % (10000000007) << endl;
		result = 1;
	}

	return 0;
}