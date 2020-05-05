//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//int N, M;
//int map[51][51];
//int min_ch_val = 99999999;
//
//vector<pair<int, int>> idx;
//
//void copy(int(*a)[51], int(*b)[51])
//{
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			b[i][j] = a[i][j];
//		}
//	}
//}
//
//void calc(int(*m)[51])
//{
//	int val = 0;
//
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			val += m[i][j];
//		}
//	}
//
//	if (val < min_ch_val)
//		min_ch_val = val;
//}
//
//void distance(int (*m)[51])
//{
//	int board[51][51];
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			board[i][j] = 0;
//		}
//	}
//
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			if (m[i][j] == 1)
//			{
//				for (int k = 0; k < idx.size(); k++)
//				{
//					int tmp;
//					tmp = abs(i - idx[k].first) + abs(j - idx[k].second);
//					if (k == 0) board[i][j] = tmp;
//					else board[i][j] = tmp < board[i][j] ? tmp : board[i][j];
//				}
//			}
//		}
//	}
//
//	calc(board);
//}
//
//void dfs(int(*m)[51], int cnt)
//{
//	if (cnt == M)
//	{
//		for (int i = 1; i <= N; i++)
//		{
//			for (int j = 1; j <= N; j++)
//			{
//				if (m[i][j] == 3)
//					idx.push_back({ i,j });
//			}
//		}
//
//		distance(m);
//
//		idx.clear();
//		return;
//	}
//	
//	int cp[51][51];
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			if (m[i][j] == 2)
//			{
//				copy(m, cp);
//				m[i][j] = 3;
//				dfs(m, cnt + 1);
//				copy(cp, m);
//			}
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//
//	cin >> N >> M;
//	int cnt = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//	int cp_map[51][51];
//
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			if (map[i][j] == 2)
//			{
//				copy(map, cp_map);
//				map[i][j] = 3;
//				dfs(map, 1);
//				copy(cp_map, map);
//			}
//		}
//	}
//
//	cout << min_ch_val;
//
//	return 0;
//}

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int map[51][51];
int min_ch_val = 99999999;

vector<int> idx;
vector<pair<int, int>> chicken;

void calc()
{
	int board[51][51] = { 0, };
	vector<pair<int, int>> tmp;

	for (int i = 0; i < idx.size(); i++)
	{
		if (idx[i] == 1)
			tmp.push_back({ chicken[i].first,chicken[i].second });
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] == 1)
			{
				for (int t = 0; t < M; t++)
				{
					int temp;
					temp = abs(i - tmp[t].first) + abs(j - tmp[t].second);
					if (t == 0) board[i][j] = temp;
					else board[i][j] = board[i][j] > temp ? temp : board[i][j];
				}
			}
		}
	}
	int val = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			val += board[i][j];
		}
	}

	min_ch_val = min_ch_val > val ? val : min_ch_val;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}

	for (int i = 0; i < chicken.size(); i++)
	{
		if (i < M)
			idx.push_back(1);
		else
			idx.push_back(0);
	}
	
	sort(idx.begin(), idx.end());
	
	do {
		calc();
	} while (next_permutation(idx.begin(), idx.end()));

	cout << min_ch_val;

	return 0;
}