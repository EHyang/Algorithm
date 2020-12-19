#include <iostream>
#include <queue>

using namespace std;

int emoji;
int sec = INT32_MAX;
bool visit[1002][1002] = { false };

class Data{
public:
	int emo;
	int clip;
	int time;

	Data(int a, int b, int c)
	{
		emo = a;
		clip = b;
		time = c;
	}
};

void init()
{
	cin >> emoji;
}

void solve()
{
	queue<Data> q;
	q.push(Data(1, 0, 0));

	while (!q.empty())
	{
		int emo = q.front().emo;
		int clip = q.front().clip;
		int time = q.front().time;

		q.pop();

		if(visit[emo][clip]) continue;

		visit[emo][clip] = true;

		if (emo == emoji)
		{
			cout << time;
			return;
		}

		if (emo > 1001 || clip > 1001) continue;

		// 복사
		q.push(Data(emo, emo, time + 1));

		// 붙여넣기
		if (clip > 0 && clip < 1001 && (emo+clip) <= 1001)
		{
			q.push(Data(emo + clip, clip, time + 1));
		}

		// 삭제하기
		if (emo > 0)
		{
			q.push(Data(emo - 1, clip, time + 1));
		}
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