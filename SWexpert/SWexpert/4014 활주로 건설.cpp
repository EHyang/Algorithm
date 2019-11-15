#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int map[20][20] = { 0 };

int ans = 0;

int N, X;

vector<int> v;

void solve() {
	int cnt = 1;
	bool make = true;
	bool down = false;

	for (int i = 1; i < N && make; i++)
	{
		if (v[i] == v[i - 1])
		{
			cnt++;
			if (cnt == X && down)
			{
				down = false;
				cnt = 0;
			}
		}
		else if (v[i] == v[i - 1] - 1) // ³·¾ÆÁü
		{
			if (!down)
			{
				down = true;
				cnt = 1;
			}
			else
			{
				make = false;
			}
		}
		else if (v[i] == v[i - 1] + 1)//³ô¾ÆÁü
		{
			if (cnt >= X) cnt = 1;
			else
				make = false;
		}
		else make = false;
	}
	if (make & down)
	{
		if (cnt < X) make = false;
	}

	if (make) ans++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; test++)
	{

		cin >> N >> X;
		ans = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				v.push_back(map[i][j]);
			}
			solve();
			v.clear();
			for (int j = 0; j < N; j++)
			{
				v.push_back(map[j][i]);
			}
			solve();
			v.clear();
		}

		cout << "#" << test << " " << ans << endl;;
	}

	return 0;
}