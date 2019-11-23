#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <memory.h>

#define endl '\n'

using namespace std;

int N, M, T;
int all_sum = 0;
double all_avg = 0;
bool del_chk = false;

deque<int> dq;
vector<deque<int>> v;
queue<pair<int, int>> q;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int visit[51][50] = { 0 };

void init_visit()
{
	for (int i = 0; i < 51; i++)
		memset(visit[i], 0, sizeof(int) * 50);
}

void rotate(int n, int dir, int k)
{
	if (!dir)//시계방향 맨뒤 -> 맨앞
	{
		for (int i = 0; i < k; i++)
		{
			v[n].push_front(v[n].back());
			v[n].pop_back();
		}
	}
	else // 반시계 맨앞 -> 맨뒤
	{
		for (int i = 0; i < k; i++)
		{
			v[n].push_back(v[n].front());
			v[n].pop_front();
		}
	}
}

void same_check(int x, int y)
{
	bool ch = false;
	bool fir = false;
	if (!visit[x][y])
	{
		q.push({ x,y });
		visit[x][y] = 1;
	}
	else
	{
		fir = true;
		visit[x][y] = 1;
	}


	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		if (nx == 0 || nx > N) continue;
		int ny = y + dy[i];
		if (ny == M) ny = 0;
		else if (ny < 0) ny = M - 1;

		if (v[x][y] == v[nx][ny] && !visit[nx][ny])
		{
			ch = true;
			same_check(nx, ny);
		}
	}
	if (fir & ch)
		q.push({ x,y });
}

void del_number()
{
	del_chk = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		v[x][y] = 0;
	}
}

void init_sum()
{
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			all_sum += v[i][j];
			if (v[i][j]) count++;
		}
	}


	if (all_sum == 0) all_avg = 0;
	else
		all_avg = (double)all_sum / (double)count;
}

void no_same()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (v[i][j] != 0 && v[i][j] < all_avg)
				v[i][j]++;
			else if (v[i][j] != 0 && v[i][j] > all_avg)
				v[i][j]--;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tmp;

	dq.push_back(0);
	v.push_back(dq);
	dq.clear();

	cin >> N >> M >> T;

	//입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tmp;
			dq.push_back(tmp);
		}
		v.push_back(dq);
		dq.clear();
	}

	for (int t = 0; t < T; t++)
	{
		int x, d, k;
		del_chk = false;
		all_sum = 0;
		cin >> x >> d >> k;
		// 회전
		for (int num = x; num <= N; num += x)
		{
			rotate(num, d, k);
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (v[i][j] != 0)
				{
					init_visit();
					visit[i][j] = 1;
					same_check(i, j);
					if (!q.empty())
					{
						del_number();
					}
				}
			}
		}
		init_sum();
		if (!del_chk) no_same();
	}
	all_sum = 0;
	init_sum();

	cout << all_sum;

	return 0;
}