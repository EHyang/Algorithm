#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;

vector<int> result;
bool desc(int a, int b) { return a > b; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t, testcase = 1;
	cin >> t;

	while (t--)
	{
		int N, K, ro = 0, rotate, a;
		string str, tmp;
		
		cin >> N >> K;
		cin.ignore();

		rotate = N / 4;
		getline(cin, str);

		while (ro < rotate)
		{
			for (int i = ro; i + rotate <= N + ro; i += rotate)
			{
				tmp = "";
				for (int j = 0; j < rotate; j++)
				{
					tmp += str[i + j];
				}
				istringstream(tmp) >> hex >> a;
				result.push_back(a);
			}
			str += str[ro];
			ro++;
		}

		sort(result.begin(), result.end(), desc);
		unique(result.begin(), result.end());

		cout << "#" << testcase++ << " " << result[K - 1] << endl;
		result.clear();
	}

	return 0;
}