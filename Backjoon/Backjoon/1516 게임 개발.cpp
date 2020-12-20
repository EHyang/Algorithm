#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

queue<int> q;

vector<int> be_cnt, be_time, time;
vector<vector<int>> graph;

void init()
{
	cin >> N;

	graph.assign(N + 1, time);

	be_cnt.assign(N + 1, 0);
	be_time.assign(N + 1, 0);
	time.assign(N + 1, 0);

	int t, n;

	for (int i = 1; i <= N; i++)
	{
		cin >> t;

		time[i] = t;

		for (;;)
		{
			cin >> n;
			if (n == -1)
				break;

			be_cnt[i]++; // 선행 건물의 수
			graph[n].push_back(i); // 그래프 그리기
		}

		if (be_cnt[i] == 0)
			q.push(i);
	}
}

void solve()
{
	while (!q.empty())
	{
		int now = q.front();

		q.pop();

		for (int i = 0; i < graph[now].size(); i++)
		{
			int node = graph[now][i];

			be_time[node] = max(be_time[node], be_time[now] + time[now]);

			be_cnt[node]--;

			if (be_cnt[node] == 0)
			{
				q.push(node);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << be_time[i] + time[i] << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}