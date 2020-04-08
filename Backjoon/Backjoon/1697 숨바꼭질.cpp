#include <iostream>
#include <queue>
using namespace std;

int h[100001];
int N, K;

queue<pair<int, int>> q;

bool check(int n)
{
	return (0 <= n && n <= 100000);
}

int BFS()
{
	int answer = 0;
	while (!q.empty())
	{
		int now = q.front().first;
		int time = q.front().second;
	
		q.pop();

		if (now == K)
		{
			answer = time;
			break;
		}
		int back = now - 1;
		int next = now + 1;
		int tel = now * 2;

		if (check(back) && h[back] == 0)
		{
			h[back] = time + 1;
			q.push({ back,time + 1 });
		}
		if (check(next) && h[next] == 0)
		{
			h[next] = time + 1;
			q.push({ next,time + 1 });
		}
		if (check(tel) && h[tel] == 0)
		{
			h[tel] = time + 1;
			q.push({ tel,time + 1 });
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	
	q.push({ N,0 });

	cout << BFS();

	return 0;
}