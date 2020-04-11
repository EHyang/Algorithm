#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> pokemon1;
vector<pair<string,int>> pokemon2;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string temp;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		pokemon1.push_back(temp);
		pokemon2.push_back({ temp,i });
	}
	sort(pokemon2.begin(), pokemon2.end());

	for (int i = 0; i < M; i++)
	{
		cin >> temp;

		int num;

		if ('0' <= temp[0] && temp[0] <= '9')
		{
			num = stoi(temp);
			cout << pokemon1[num - 1] << "\n";
			continue;
		}
		else
		{
			int left = 0;
			int right = N - 1;
			int mid;

			while (left <= right)
			{
				mid = (left + right) / 2;
				if (pokemon2[mid].first == temp)
				{
					cout << pokemon2[mid].second << "\n";
					break;
				}
				if (pokemon2[mid].first < temp)
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
	}

	return 0;
}