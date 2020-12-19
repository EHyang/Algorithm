#include <iostream>
#include <vector>

using namespace std;

vector<int> arr, dp;
vector<int>::iterator itr;

int N, cnt = 0;

void init()
{
	cin >> N;

	arr.assign(N + 1, 0);
	dp.assign(N + 1, 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
}

void solve()
{
	int max = 1;

	/*
	�� �κ��� �ʿ� ���� ����

	4 1 2 3

	�� ��쿡�� 4�� �ǵڷ� �ű�� ��.

	������ �ڵ��� ��� 1�� ���� ������ �ű��, 4�� �ǵڷ� �ű�� �۾��� �ؼ� 2���� �������� �ҿ��.

	�׳� �����ϴ� ���� �� �κм����� ���� ���ϸ� �Ǵ� ��������.
	
	*/
	//itr = arr.begin() + 1;
	//if (*itr != 1)
	//{
	//	while (*itr != 1)
	//	{
	//		itr++;
	//	}

	//	arr.erase(itr);
	//	arr.insert(arr.begin() + 1, 1);
	//	cnt++;
	//}
	//if (*(arr.end() - 1) != N)
	//{
	//	itr = arr.end() - 1;
	//	while (*itr != N)
	//	{
	//		itr--;
	//	}

	//	arr.erase(itr);
	//	arr.push_back(N);
	//	cnt++;
	//}

	for (int i = 2; i <= N; i++)
	{
		max = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[i] > arr[j])
			{
				if (max < dp[j] + 1) max = dp[j] + 1;
			}
		}
		dp[i] = max;
	}
	max = 1;
	for (int i = 1; i <= N; i++)
	{
		max = dp[i] > max ? dp[i] : max;
	}

	cnt += (N - max);

	cout << cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}