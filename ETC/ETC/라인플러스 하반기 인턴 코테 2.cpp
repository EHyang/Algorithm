#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num, n;
	vector<int> v;

	cin >> num;

	int tmp;

	for (int i = 0; i < num; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	cin >> n;

	sort(v.begin(), v.end());

	for (int i = 1; i < n; i++)
	{
		next_permutation(v.begin(), v.end());
	}
	for (auto a : v) cout << a;

	return 0;
}