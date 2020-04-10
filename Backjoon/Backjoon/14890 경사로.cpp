#include <iostream>
#include <vector>
using namespace std;

int N, L;
int map[101][101];
vector<int> v;
int ans = 0;

void solve()
{
	int cnt = 1;
	bool down = false;
	bool make = true;

	for (int i = 1; i < N; i++)
	{
		if (abs(v[i] - v[i - 1]) > 1) return;
		if (v[i] == v[i - 1])
		{
			cnt++;
			if (down)
			{
				if (cnt == L)
				{
					cnt = 0;
					down = false;
				}
				else if (cnt > L)
				{
					cnt -= L;
					down = false;
				}
			}
		}
		else if (v[i] == v[i - 1] + 1) // 오르막길
		{
			if (down)
			{
				if (cnt >= L)
				{
					cnt -= L;
					down = false;
				}
				else
					return;
			}
			if (cnt < L) return;
			else
			{
				cnt = 1;
			}
		}
		else if (v[i] == v[i - 1] - 1) // 내리막길
		{
			if (down)
			{
				if (cnt < L)
				{
					return;
				}
			}
			cnt = 1;
			down = true;
		}
	}
	if (make & down)
	{
		if (cnt < L)
			return;
	}

	if (make) ans++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;

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

	cout << ans;
}