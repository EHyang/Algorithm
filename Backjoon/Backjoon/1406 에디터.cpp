#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> L, R;
string input;
int M;

void init()
{
	cin >> input;
	cin >> M;

	for (char a : input)
	{
		L.push_back(a);
	}
}

void solve()
{
	char cmd, str;

	while (M--)
	{
		cin >> cmd;

		switch (cmd)
		{
		case 'L':
			if (L.empty()) break;
			R.push_back(L.back());
			L.pop_back();
			break;
		case 'D':
			if (R.empty()) break;
			L.push_back(R.back());
			R.pop_back();
			break;
		case 'B':
			if (L.empty()) break;
			L.pop_back();
			break;
		case 'P':
			cin >> str;
			L.push_back(str);
			break;
		default:
			break;
		}
	}

	while (!R.empty())
	{
		L.push_back(R.back());
		R.pop_back();
	}

	for (auto a : L)
		cout << a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}