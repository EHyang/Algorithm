#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;

vector<string> input;
vector<int> Alpha;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, test = 1;
	int N, max, max_idx, count;
	string a;
	cin >> T;
	Alpha.assign(26, 0);
	while (T--)
	{
		cin >> N;
		cin.ignore(100, '\n');
		max = 0;
		count = 0;

		for (int i = 0; i < N; i++)
		{
			getline(cin, a);
			input.push_back(a);
		}
		sort(input.begin(), input.end());
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < input[i].size(); j++)
			{
				if (input[i][j] != ' ' && input[i][j] != '\r')
				{
					Alpha[input[i][j] - 'A']++;
				}
			}

			for (int k = 0; k < 26; k++)
			{
				if (Alpha[k] != 0) count++;
			}

			if (count > max)
			{
				max = count;
				max_idx = i;
			}
			Alpha.clear();
			Alpha.assign(26, 0);
			count = 0;
		}
		cout << "#" << test++ << " " << input[max_idx] << endl;
		input.clear();
	}

	return 0;
}