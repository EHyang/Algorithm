#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int check[26][26];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
char a[26][26];
int cnt[26*26];
vector<int> result;
void dfs(int x, int y,int t) {
	a[x][y] = '0';
	check[x][y] = 1;
	cnt[t]++;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (a[nx][ny] == '1' && check[nx][ny] == 0)
			{
				dfs(nx, ny, t);
			}
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}
	int time = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] == '1')
			{
				dfs(i, j,time);
				result.push_back(cnt[time]);
				time++;
			}
		}
	}

	cout << time << '\n';
	sort(result.begin(), result.end());

	for (int i = 0; i < time; i++)
	{
		cout << result[i] << '\n';
	}
}