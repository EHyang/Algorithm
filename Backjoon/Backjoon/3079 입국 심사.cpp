#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

typedef long long ll;

vector<long long> time;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, tmp;
	ll left = 1, right = 1000000000000000000;
	ll mid, count = 0, result;


	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		time.push_back(tmp);
	}

	while (left <= right)
	{
		mid = (left + right) / 2;

		for (int i = 0; i < N; i++)
		{
			count += mid / time[i];
		}
		if (count >= M)
		{
			right = mid - 1;
		}
		else
			left = mid + 1;

		count = 0;
	}
	cout << left;


	return 0;
}