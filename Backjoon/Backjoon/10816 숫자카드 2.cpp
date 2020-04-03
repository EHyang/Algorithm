//#include <iostream>
//#include <algorithm>
//
//typedef long long ll;
//using namespace std;
//
//ll card[500000];
//ll find_c[500000];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//
//	int N, M;
//	int result = 0;
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		cin >> card[i];
//	}
//
//	cin >> M;
//
//	for (int i = 0; i < M; i++)
//	{
//		cin >> find_c[i];
//	}
//
//	sort(card, card + N);
//
//	for (int i = 0; i < M; i++)
//	{
//
//		int left = 0, right = N - 1;
//
//		while ((card[left] != card[right]) && (left<right) )
//		{
//			int mid = (left + right) / 2;
//
//			if (card[mid] > find_c[i])
//			{
//				right = mid - 1;
//			}
//			else if (card[mid] == find_c[i])
//			{
//				if (card[left] == card[right] && card[left] == find_c[i]) break;
//
//				if (card[left] != find_c[i])
//				{
//					if (left > 1)left--;
//					else left++;
//				}
//				if (card[right] != find_c[i])
//				{
//					if (right < N - 1)right++;
//					else right--;
//				}
//				
//			}
//			else
//			{
//				left = mid + 1;
//			}
//		}
//
//		if ((card[left] == card[right]) && (card[left] == find_c[i])) result = right - left + 1;
//		else if (right - left < 0) result = 0;
//		else
//			result = right - left;
//
//
//		cout << result << " ";
//	}
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//
//	int N, M, findNum;
//
//	cin >> N;
//	vector<int> v(N);
//
//	for (int i = 0; i < N; i++)
//		cin >> v[i];
//
//	sort(v.begin(), v.end());
//
//	cin >> M;
//
//	for (int i = 0; i < M; i++)
//	{
//		cin >> findNum;
//
//		cout << upper_bound(v.begin(), v.end(), findNum) - lower_bound(v.begin(), v.end(), findNum) << " ";
//	}
//
//	return 0;
//}

#include <iostream>

using namespace std;

int N[10000001][2] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, temp;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		if (temp >= 0) N[temp][0]++;
		else N[-temp][1]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;

		if (temp >= 0) cout << N[temp][0] << " ";
		else cout << N[-temp][1] << " ";
	}

	return 0;
}