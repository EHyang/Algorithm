#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string N;
	vector<string> v;

	cin >> N;

	v.push_back("4");
	v.push_back("7");
	int i = 1;

	int start = 0;
	int end = 2;
	int idx = start;
	int fir = 0;
	int count = 0;
	int w = 2;
	while (stoi(v[i]) <= stoi(N))
	{
		i++;
		v.push_back(v[fir] + v[idx]);

		idx++;
		if (idx == end)
		{
			count++;
			if (count == 2)
			{
				count = 0;
				start = end;
				end = end + pow(2, w++);
			}
			idx = start;
			fir++;
			if (fir == 2) fir = 0;
		}
	}

	if (stoi(v[i]) > stoi(N)) cout << v[i - 1];
	else cout << v[i];

	return 0;
}