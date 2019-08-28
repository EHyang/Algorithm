#include <iostream>
using namespace std;

int com[101][101] = { 0 };
int check[101] = { 0 };
int N;
int result = 0;

void dfs(int x, int y)
{
	if (check[y] == 1)
		return;

	check[y] = 1;
	result++;

	for (int i = 1; i <= N; i++)
	{
		if (com[y][i] == 1)
			dfs(y, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int pa, x, y;

	cin >> N >> pa;

	for (int i = 0; i < pa; i++)
	{
		cin >> x >> y;
		com[x][y] = 1;
		com[y][x] = 1;
	}
	check[1] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (com[1][i] == 1) dfs(1, i);
	}
	
	cout << result;

	return 0;
}