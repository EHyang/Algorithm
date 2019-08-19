#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> tmp;
int Max(int num)
{
	int mx = 0;
	for (int i = 0; i <= num; i++)
	{
		mx = max(mx, tmp[i]);
	}

	return mx;
}

int main()
{
	vector<int> A;
	vector<int> B;
	vector<int> result;

	int T;

	int N, M;
	int temp;
	int re_temp = 0;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			A.push_back(temp);
		}
		for (int i = 0; i < M; i++)
		{
			cin >> temp;
			B.push_back(temp);
		}

		if (N < M)
		{
			for (int j = 0; j <= M - N; j++)
			{
				for (int i = 0; i < N; i++)
				{
					re_temp += A[i] * B[i + j];
				}
				tmp.push_back(re_temp);
				re_temp = 0;

			}
			result.push_back(Max(M - N));
		}
		else if (N > M)
		{
			for (int j = 0; j <= N - M; j++)
			{
				for (int i = 0; i < M; i++)
				{
					re_temp += A[i + j] * B[i];
				}
				tmp.push_back(re_temp);
				re_temp = 0;

			}
			result.push_back(Max(N - M));
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				re_temp += A[i] * B[i];
			}
			tmp.push_back(re_temp);
			re_temp = 0;
			result.push_back(Max(0));
		}
		A.clear();
		B.clear();
		tmp.clear();
	}

	for (int i = 0; i < T; i++)
	{
		printf("#%d %d\n", i + 1, result[i]);
	}
	
}