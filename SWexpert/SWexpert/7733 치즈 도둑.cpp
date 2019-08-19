#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
vector<int> tmp;
vector<vector<int>> cheese;
vector<vector<int>> check;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int N;

void dfs(int x, int y)
{
	check[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < N && ny < N && nx >= 0 && ny >= 0)
		{
			if (check[nx][ny] != 1 && cheese[nx][ny] != -1)
				dfs(nx, ny);
		}
	}
}

int main()
{
	int T, test = 1;
	int max, count = 0;
	int input_max = 0;
	cin >> T;

	while (T--)
	{
		cin >> N;
		tmp.assign(N, 0);
		cheese.assign(N, tmp);
		check.assign(N, tmp);
		max = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> cheese[i][j];
				if (cheese[i][j] > input_max) input_max = cheese[i][j];
			}
		}

		for (int i = 0; i <= input_max; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					if (cheese[j][k] <= i)
						cheese[j][k] = -1;
				}
			}

			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					if (cheese[j][k] != -1 && check[j][k] == 0)
					{
						dfs(j, k);
						count++;
					}
				}
			}
			max = count > max ? count : max;

			count = 0;
			check.clear();
			check.assign(N, tmp);
		}

		cout << "#" << test++ << " " << max << endl;
	}

	return 0;
}