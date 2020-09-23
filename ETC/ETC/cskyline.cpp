//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int N, W;
//int maxval;
//vector<int> t;
//vector<vector<int>> skyline;
//vector<pair<int, int>> input;
//
//void print_sky()
//{
//	for (int j = maxval; j >= 1; j--)
//	{
//		for (int i = 1; i <= W; i++)
//		{
//			cout << skyline[j][i] << " ";
//		}
//		cout << endl;
//	}
//}
//
//
//void fill_two(int x, int y, int end)
//{
//	for (int j = y; j <= end; j++)
//	{
//		for (int i = x; i >= 1; i--)
//		{
//			skyline[i][j] = 2;
//		}
//	}
//}
//
//void find_rec(int x, int y)
//{
//	int cnt = 0;
//	int tm_y = y;
//	while (skyline[x][tm_y] != 0)
//	{
//		if (skyline[x][tm_y] == 1 || skyline[x][tm_y] == 2)
//		{
//			skyline[x][tm_y] = 2;
//			tm_y++;
//			if (tm_y > W) break;
//		}
//	}
//	fill_two(x, y, tm_y-1);
//	//print_sky();
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//
//	cin >> N >> W;
//
//	t.assign(W + 1, 0);
//	int x, y, max = 0;
//	int cnt = 0;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> x >> y;
//		if (y > max) max = y;
//		input.push_back({ x,y });
//	}
//	maxval = max;
//	skyline.assign(max + 1, t);
//
//	int idx = 0;
//	int height;
//	for (int i = 1; i <= W; i++)
//	{
//		
//		if (idx <N && i == input[idx].first)
//		{
//			height = input[idx].second;
//			idx++;
//		}
//		for (int j = 1; j <= height; j++)
//		{
//			skyline[j][i] = 1;
//		}
//	}
//
//	for (int i = max; i >= 1; i--)
//	{
//		for (int j = 1; j <= W; j++)
//		{
//			if (skyline[i][j] == 1)
//			{
//				find_rec(i, j);
//				cnt++;
//			}
//		}
//	}
//
//	cout << cnt;
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, W;
	int x, y;
	int cnt = 0;

	cin >> N >> W;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;

		while (!(v.empty()) && !(v.back() <= y))
		{
			v.pop_back();
			cnt++;
		}
		if (y == 0) continue;
		if (v.empty() || v.back() < y) v.push_back(y);
	}

	while (!v.empty())
	{
		v.pop_back();
		cnt++;
	}
	cout << cnt;
	return 0;
}