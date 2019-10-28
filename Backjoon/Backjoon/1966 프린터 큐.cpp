#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;

	cin >> t;

	while (t--)
	{
		int N, M, tmp;
		int count = 0;

		queue<pair<int, int>> q;
		priority_queue<int> pq;

		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			q.push(make_pair(i, tmp));
			pq.push(tmp);
		}

		while (!q.empty())
		{
			if (q.front().second == pq.top())
			{
				count++;
				if (q.front().first == M)
					break;
				else
				{
					q.pop();
					pq.pop();
				}
			}
			else
			{
				q.push(make_pair(q.front().first, q.front().second));
				q.pop();
			}
		}

		cout << count << endl;
	}

	return 0;
}