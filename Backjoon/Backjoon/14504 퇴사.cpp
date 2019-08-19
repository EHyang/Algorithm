// ���� ��Ǭ ������.
// 2019-05-12 2���� ����
// 2019-05-12 ���ͳ� �˻� �� 3���� �¸� ���پ˾����� ����
// 2019-05-12 �ٽ� �˻� �� ���� ���� �� �¸�
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;

	int a, b, day = 0, sum = 0;
	bool work[16] = { false };
	vector<int> t, p, dp;
	cin >> N;

	dp.assign(N + 1, 0);
	t.assign(N + 1, 0);
	p.assign(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> t[i] >> p[i];
		dp[i] = p[i];
	}
	dp[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (i - j >= t[j])
			{
				dp[i] = max(dp[i], dp[j] + p[i]);
			}
		}
	}
	int re;

	for (int i = 1; i <= N; i++)
	{
		if (t[i] + i - 1 > N)continue;

		re = max(re, dp[i]);
	}
	cout << re;

}