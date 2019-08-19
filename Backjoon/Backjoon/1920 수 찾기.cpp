#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

vector<int> A;
vector<int> B;
int check(int ch, int N)
{
	int left = 0;
	int right = N - 1;
	int answer = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (A[mid] >= ch)
		{
			right = mid - 1;
			answer = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	if (A[answer] == ch)
		return 1;
	else
		return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, tmp;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		A.push_back(tmp);
	}

	sort(A.begin(), A.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> tmp;
		B.push_back(tmp);
	}

	for (int i = 0; i < M; i++)
	{
		cout << check(B[i], N) << endl;
	}

	return 0;
}