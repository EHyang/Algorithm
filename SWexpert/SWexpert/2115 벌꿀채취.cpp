#include <iostream>

using namespace std;

int N, M, C;
int honey[11][11];
int first_sel[6], sec_sel[6];
int first_profit = 0, sec_profit = 0;
int hap = 0;

void dfs_f(bool visit[6], int goal, int cho, int idx)
{
	if (goal == cho)
	{
		int chk = 0, val = 0;
		for (int i = 1; i <= M; i++)
		{
			if (visit[i])
			{
				chk += first_sel[i];
				val += (first_sel[i] * first_sel[i]);
			}
		}

		if (chk != 0 && chk <= C)
		{
			first_profit = first_profit < val ? val : first_profit;
		}

		return;
	}
	if (idx > M) return;

	visit[idx] = true;
	dfs_f(visit, goal, cho + 1, idx + 1);
	visit[idx] = false;
	dfs_f(visit, goal, cho, idx + 1);
}

void dfs_s(bool visit[6], int goal, int cho, int idx)
{
	if (goal == cho)
	{
		int chk = 0, val = 0;
		for (int i = 1; i <= M; i++)
		{
			if (visit[i])
			{
				chk += sec_sel[i];
				val += (sec_sel[i] * sec_sel[i]);
			}
		}

		if (chk != 0 && chk <= C)
		{
			sec_profit = sec_profit < val ? val : sec_profit;
		}

		return;
	}
	if (idx > M) return;

	visit[idx] = true;
	dfs_s(visit, goal, cho + 1, idx + 1);
	visit[idx] = false;
	dfs_s(visit, goal, cho, idx + 1);
}

void select(int x, int y)
{
	int start_idx = y + M;

	if (start_idx + M - 1 > N)
	{
		x += 1;
	}
	else
	{
		int idx = 1;
		for (int j = start_idx; j <= N && idx <= M; j++)
		{
			sec_sel[idx++] = honey[x][j];
		}
		for (int k = 1; k <= M; k++)
		{
			bool visit[6] = { false, };
			dfs_s(visit, k, 0, 1);
		}
		hap = hap < first_profit + sec_profit ? first_profit + sec_profit : hap;
		sec_profit = 0;
		x += 1;
	}

	for (int i = x; i <= N; i++)
	{
		for (int j = 1; j + M - 1 <= N; j++)
		{
			int idx = 1;
			for (int k = j; k <= N && idx <= M; k++)
			{
				sec_sel[idx++] = honey[i][k];
			}

			for (int k = 1; k <= M; k++)
			{
				bool visit[6] = { false, };
				dfs_s(visit, k, 0, 1);
			}
			hap = hap < first_profit + sec_profit ? first_profit + sec_profit : hap;
			sec_profit = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int test;
	cin >> test;

	for (int tc = 1; tc <= test; tc++)
	{
		cin >> N >> M >> C;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> honey[i][j];
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j + M - 1 <= N; j++)
			{
				int idx = 1;
				for (int k = j; k <= N && idx <= M; k++)
				{
					first_sel[idx++] = honey[i][k];
				}

				for (int k = 1; k <= M; k++)
				{
					bool visit[6] = { false, };
					dfs_f(visit, k, 0, 1);
				}
				select(i, j);

				first_profit = 0;
			}
		}

		cout << "#" << tc << " " << hap << endl;
		hap = 0;
	}

	return 0;
}