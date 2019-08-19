#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { -2,-1,1,2,-2,-1,1,2 };

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T, l;
	int start_x, start_y;
	int dest_x, dest_y;

	cin >> T;
	while (T--)
	{
		cin >> l >> start_x >> start_y >> dest_x >> dest_y;

		queue<pair<int, int>> q;
		int table[301][301] = { 0 };

		q.push(make_pair(start_x, start_y));

		while (!q.empty())
		{

			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == dest_x && y == dest_y) break;

			for (int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < l && ny < l && !table[nx][ny])
				{
					q.push(make_pair(nx, ny));
					table[nx][ny] = table[x][y] + 1;
				}
			}
		}
		cout << table[dest_x][dest_y] << endl;
	}

	return 0;
}