#include <iostream>

using namespace std;

int N, S;
int number[21];
int same_num_cnt = 0;

void DFS(int idx, int sum)
{
	sum += number[idx];

	if (idx > N) return;

	if (sum == S)
		same_num_cnt++;

	DFS(idx + 1, sum);
	DFS(idx + 1, sum -= number[idx]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> S;

	for (int i = 1; i <= N; i++)
	{
		cin >> number[i];
	}
	DFS(1, 0);

	cout << same_num_cnt;

	return 0;
}