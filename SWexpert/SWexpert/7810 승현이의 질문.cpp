#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T, count = 1;
	int N, tmp;

	cin >> T;
	while (T--)
	{
		cin >> N;
		arr.push_back(0);
		for (int i = 1; i <= N; i++)
		{
			cin >> tmp;
			arr.push_back(tmp);
		}
		sort(arr.begin(), arr.end());
		int answer = 0;
		int Left = 1, right = N;


		while (Left <= right)
		{
			int mid = (Left + right) / 2;
			int count = 0;

			for (int i = N; i >= 1; i--)
			{
				if (arr[i] < mid) break;
				count++;
			}
			if (count >= mid)
			{
				answer = mid;
				Left = mid + 1;
			}
			else if (count < mid)
			{
				right = mid - 1;
			}
		}

		cout << "#" << count++ << " " << answer << endl;
		arr.clear();
	}
	return 0;
}
