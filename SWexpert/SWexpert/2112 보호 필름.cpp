#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int D, W, K;
bool ch;
int ret;
int c[13][20];

void copy(int(*a)[20], int(*b)[20])
{
	for (int i = 0; i < D; i++)
	{
		for (int j = 0; j < W; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

int calc(int(*a)[20])
{
	int check = 0;
	bool c = false;
	for (int i = 0; i < W; i++)
	{
		c = false;
		int cnt = 1;
		for (int j = 1; j < D; j++)
		{
			if (a[j][i] == a[j - 1][i])
			{
				cnt++;
			}
			else
			{
				cnt = 1;
			}

			if (cnt >= K)
			{
				check++;
				c = true;
				break;
			}
		}
		if (!c) return check;
	}

	return check;
}

void dfs(int(*a)[20], int cur, int cnt)
{
	if (cur > D || cnt > K || cnt > ret)
	{
		return;
	}
	if (cur == D && cnt <= K)
	{
		if (calc(a) == W) // 조건이 완성됨.
		{
			ret = min(ret, cnt);
			return;
		}
		return;
	}

	int copy_c[13][20];

	dfs(a, cur + 1, cnt); // 약품 안하고 다음줄부터 돌려보기

	copy(a, copy_c);
	
	for (int i = 0; i < W; i++) // cur줄 A로 약품 사용
	{
		copy_c[cur][i] = 0;
	}

	dfs(copy_c, cur + 1, cnt + 1); // 상태 확인후 cur 다음줄부터 약품을 바꾸거나 해보기.

	for (int i = 0; i < W; i++) // cur줄 B로 약품 사용
	{
		copy_c[cur][i] = 1;
	}

	dfs(copy_c, cur + 1, cnt + 1); // 상태 확인 후 cur 다음줄..
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int test;

	cin >> test;

	for (int tc = 1; tc <= test; tc++)
	{
		cin >> D >> W >> K;

		ret = 987654321;

		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> c[i][j];
			}
		}

		if (K == 1) ret = 0;
		else
			dfs(c, 0, 0);
		cout << "#" << tc << " " << ret << endl;
	}

	return 0;
}