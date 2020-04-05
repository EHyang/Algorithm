#include <iostream>
#include <queue>

using namespace std;

int fam[101][101] = { 0 };
int check[101] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, parent, son, m;
	int first, second;
	int answer = -1;
	cin >> n;
	cin >> first >> second;
	cin >> m;

	queue<pair<int,int>> q;

	for (int i = 0; i < m; i++)
	{
		cin >> parent >> son;
		fam[parent][son] = 1;
	}

	q.push({ first,0 });
	
	while (!q.empty())
	{
		int chon = q.front().second;
		int now = q.front().first;
		check[now] = 1;
		if (now == second)
		{
			answer = chon;
			break;
		}
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (fam[now][i] && check[i] == 0) q.push({ i, chon + 1 });
			else if (fam[i][now]) q.push({ i, chon + 1 });
		}
	}
	
	cout << answer;

	return 0;
}