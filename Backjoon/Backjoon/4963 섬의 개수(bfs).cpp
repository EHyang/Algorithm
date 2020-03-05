#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 0,0,-1,1,-1,-1,1,1 };
int dy[] = { -1,1,0,0,-1,1,-1,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int w, h;
	int island = 0;
	int map[51][51];
	queue<pair<int, int>> q;


	while (true)
	{
		cin >> w >> h;
		if (!(w || h)) break;

		island = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1)
				{
					q.push({ i,j });
					map[i][j] = 0;
					island++;
				}

				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 8; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx >= 0 && nx < h && ny >= 0 && ny < w)
						{
							if (map[nx][ny] == 1)
							{
								q.push({ nx,ny });
								map[nx][ny] = 0;
							}
						}
					}

				}
			}
		}

		cout << island << endl;
	}

	return 0;
}