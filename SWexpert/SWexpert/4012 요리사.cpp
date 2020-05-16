#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, res;

int ingredient[16][16];

vector<int> visit;
vector<int> group_A;
vector<int> group_B;

int calc()
{
	int sum_A = 0;
	int sum_B = 0;

	for (int i = 0; i < N; i++)
	{
		if (visit[i] == 1)
			group_A.push_back(i);
		else
			group_B.push_back(i);
	}

	for (int i = 0; i < group_A.size(); i++)
	{
		for (int j = 0; j < group_A.size(); j++)
		{
			if (i == j) continue;

			sum_A += ingredient[group_A[i]][group_A[j]];
			sum_B += ingredient[group_B[i]][group_B[j]];
		}
	}

	group_A.clear();
	group_B.clear();

	return abs(sum_A - sum_B);
}

void dfs(int cur, int cnt)
{
	if (cur == N) return;
	if (cnt == N / 2)
	{
		res = min(res, calc());
		return;
	}

	visit[cur] = 1;
	dfs(cur + 1, cnt + 1);

	visit[cur] = 0;
	dfs(cur + 1, cnt);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int test;

	cin >> test;

	for (int tc = 1; tc <= test; tc++)
	{
		cin >> N;

		visit.assign(N, 0);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> ingredient[i][j];
			}
		}

		res = 99999999;
		dfs(0, 0);

		cout << "#" << tc << " " << res << endl;
	}

	return 0;
}