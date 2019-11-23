#include <iostream>
#include <deque>
#include <vector>
#include <memory.h>

#define endl '\n'

using namespace std;

deque<int> dq;
vector<deque<int>> v;

int N, M, T, tmp;
int all_sum = 0;
float all_ave = 0;
bool same_check = false; // DFS 돌때 같아서 들어온거면 0으로 바꿔주기 위함
bool samesame = false; // 전체 같은수 있는지 확인용

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int visit[51][50] = { 0 };

void initial_visit()
{
	for (int i = 0; i < 51; i++)
	{
		memset(visit[i], 0, sizeof(int) * 50);
	}
}

//반시계, 시계 도는 함수
void spin(int n, int dir, int k)
{
	if (!dir)
	{
		for (int i = 0; i < k; i++)
		{
			v[n].push_front(v[n].back());
			v[n].pop_back();
		}
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			v[n].push_back(v[n].front());
			v[n].pop_front();
		}
	}
}

// 근처에 같은 수 있는지 확인하는 함수
void check_near(int x, int y)
{
	if (v[x][y] == 0) return;
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		if (x + dx[i] == 0 || x + dx[i] > N)
			continue;
		int nx = x + dx[i];
		int ny;
		if (y + dy[i] == M) ny = 0;
		else if (y + dy[i] < 0) ny = M - 1;
		else
			ny = y + dy[i];

		if (v[x][y] == v[nx][ny] && visit[nx][ny] != 1)
		{
			samesame = true;
			same_check = true;
			check_near(nx, ny);
		}
	}

	if (same_check) v[x][y] = 0;
}

//같은수 없을경우 평균비교후 더하거나 빼는함수
void nosamesame()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (v[i][j] == 0) continue;

			if (v[i][j] < all_ave)
				v[i][j]++;
			else if (v[i][j] > all_ave)
				v[i][j]--;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	dq.push_back(0);
	v.push_back(dq);
	dq.clear();

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++) // 입력
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tmp;
			dq.push_back(tmp);
		}
		v.push_back(dq);
		dq.clear();
	}

	for (int i = 0; i < T; i++)
	{
		samesame = false;
		int x, d, k;
		cin >> x >> d >> k;
		for (int n = x; n <= N; n += x)
		{
			spin(n, d, k);
		}
		for (int k = 1; k <= N; k++)//1.0 부터 돌면서 같은수 있는지 체크
		{
			for (int j = 0; j < M; j++)
			{
				same_check = false;
				if (v[k][j] != 0)
				{
					initial_visit();
					check_near(k, j);
				}
			}
		}
		int count = 0;
		all_sum = 0;
		for (int k = 1; k <= N; k++)
		{
			for (int j = 0; j < M; j++)
			{
				if (v[k][j])
				{
					count++;
					all_sum += v[k][j];
				}
			}
		}
		if (count == 0) all_ave = 0; //제로디바이드 방지
		else
			all_ave = (float)all_sum / (float)count;

		if (!samesame) nosamesame();
	}
	all_sum = 0;
	for (int k = 1; k <= N; k++)
	{
		for (int j = 0; j < M; j++)
		{
			if (v[k][j])
			{
				all_sum += v[k][j];
			}
		}
	}

	cout << all_sum << endl;
	return 0;
}