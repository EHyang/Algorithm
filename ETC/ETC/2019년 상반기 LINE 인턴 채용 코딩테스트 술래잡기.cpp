#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;

queue<pair<pair<int, int>,int>> q;
bool check(int n)
{
	return (0 <= n && n <= 200000);
}

int BFS()
{
	int answer = -1;
	while (!q.empty())
	{
		int now = q.front().first.first;
		int time = q.front().first.second;
		int cony_now = q.front().second;

		q.pop();

		if (now == cony_now)
		{
			answer = time;
			break;
		}

		if (now > 200000 || cony_now > 200000)
			break;

		int back = now - 1;
		int next = now + 1;
		int tel = now * 2;
		time = time + 1;
		cony_now += time;

		if (check(back) && cony_now <= 200000)
		{
			q.push({ { back,time}, cony_now});
		}
		if (check(next) && cony_now <= 200000)
		{

			q.push({ { next,time },cony_now });
		}
		if (check(tel) && cony_now <= 200000)
		{
			q.push({{ tel,time },cony_now });
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

	q.push({ { K,0 },N });

	cout << BFS();

	return 0;
}