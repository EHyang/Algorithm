#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define endl '\n'
using namespace std;

vector<int> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, test = 1;
	int N, count;
	string input;
	string str;

	cin >> T;
	while (T--)
	{
		bool check = false;
		cin >> N;
		cin.ignore(100, '\n');

		getline(cin, input);
		stringstream ss;
		ss.str(input);
		count = 0;
		while (ss >> str)
		{
			if ('A' <= str[0] && str[0] <= 'Z') check = true;
			for (int k = 1; k < str.size(); k++)
			{
				if ('a' <= str[k] && str[k] <= 'z') continue;
				else if (str[k] == '!' || str[k] == '.' || str[k] == '?')
				{
					if (check)
						count++;
					result.push_back(count);
					count = 0;
					check = false;
					break;
				}
				else check = false;
			}
			if (check) count++;
			check = false;
		}
		cout << "#" << test++ << " ";
		for (int i = 0; i < N; i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
		result.clear();
	}
	return 0;
}