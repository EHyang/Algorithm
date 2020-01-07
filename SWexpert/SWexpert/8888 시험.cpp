#include <iostream>
#include <memory.h>
using namespace std;

int test[2001] = { 0 };
int man[2001][2001] = { 0 }; // 각자 성적표
int man_sco[2001] = { 0 }; // 각자 총 점수
int man_hap[2001] = { 0 }; // 각자 맞춘 갯수

int N, T, P;

void cal()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			man_sco[i] += (man[i][j] * test[j]);
		}
	}
}

int calc_rank()
{
	int my_score = man_sco[P];
	int my_hap = man_hap[P];
	int high = 0, more = 0, fast = 0;

	for (int i = 1; i <= N; i++)
	{
		if (i == P) continue;

		if (man_sco[i] > my_score) high++;
		else if (man_sco[i] == my_score)
		{
			if (man_hap[i] > my_hap) more++;
			else if (man_hap[i] == my_hap && i < P) fast++;
		}
	}

	return high + more + fast + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
	{
		int rank, sum;

		cin >> N >> T >> P;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= T; j++)
			{
				cin >> man[i][j];
				if (man[i][j]) // i 번째사람이 j 문제 푼경우
				{
					man_hap[i]++;
				}
				else // 못푼경우
				{
					test[j]++;
				}
			}
		}
		cal();
		rank = calc_rank();
		sum = man_sco[P];

		cout << "#" << tc << " " << sum << " " << rank << '\n';
		memset(test, 0, sizeof(test));
		memset(man_hap, 0, sizeof(man_hap));
		memset(man_sco, 0, sizeof(man_sco));
	}
	return 0;
}