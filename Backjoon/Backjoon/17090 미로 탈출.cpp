#include <iostream>
#include <cstdio>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int N, M;
int c;
vector<vector<char>> maze;
vector<char> input;

vector<vector<int>> check;
vector<int> ch;

vector<vector<int>> result;
vector<int> re;

int available = 0;

void dep(int n, int m)
{
	if (n < N && n >= 0 && m < M&&m >= 0)
	{
		if (result[n][m] != 0)
		{
			c++;
			available = 1;
			return;
		}
	}

	if (n >= N || m >= M || n < 0 || m < 0)
	{
		c++;
		available = 1;
	}
	else if (check[n][m] != 0)
	{
		available = 0;
		return;
	}
	else
	{
		switch (maze[n][m])
		{
		case 'D':
			check[n][m]++;
			dep(n + 1, m);
			result[n][m] = available;
			check[n][m]--;
			break;
		case 'R':
			check[n][m]++;
			dep(n, m + 1);
			result[n][m] = available;
			check[n][m]--;
			break;
		case 'U':
			check[n][m]++;
			dep(n - 1, m);
			result[n][m] = available;
			check[n][m]--;
			break;
		case 'L':
			check[n][m]++;
			dep(n, m - 1);
			result[n][m] = available;
			check[n][m]--;
			break;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string tm;
	int ttt;

	scanf("%d %d", &N, &M);

	input.assign(M, '\0');
	maze.assign(N, input);

	ch.assign(M, 0);
	check.assign(N, ch);

	re.assign(M, 0);
	result.assign(N, re);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf(" %c", &maze[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			ttt = c;
			dep(i, j);
			if (c != ttt)
				result[i][j]++;
		}
	}
	printf("%d", c);
}