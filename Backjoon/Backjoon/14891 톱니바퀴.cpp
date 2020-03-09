#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

deque<int> dq;
vector<deque<int>> gear;

int visit[] = { 0,0,0,0 };
int ro_ch[] = { 0,0,0,0 };
int result()
{
	return gear[0][0] * 1 + gear[1][0] * 2 + gear[2][0] * 4 + gear[3][0] * 8;
}
void rotation()
{
	for (int i = 0; i < 4; i++)
	{
		visit[i] = 0;
		if (ro_ch[i] == -1)
		{
			gear[i].push_back(gear[i].front());
			gear[i].pop_front();
			ro_ch[i] = 0;
		}
		else if(ro_ch[i] == 1)
		{
			gear[i].push_front(gear[i].back());
			gear[i].pop_back();
			ro_ch[i] = 0;
		}
	}
}
void solve(int num, int dir)
{
	visit[num] = 1;
	ro_ch[num] = dir;
	if (num - 1 >= 0 && !visit[num - 1])
	{
		if (gear[num][6] != gear[num - 1][2])
		{
			solve(num - 1, dir*-1);
		}
	}
	if (num + 1 < 4 && !visit[num + 1])
	{
		if (gear[num][2] != gear[num + 1][6])
		{
			solve(num + 1, dir*-1);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string tmp;
	int K, num, dir;

	for (int i = 0; i < 4; i++)
	{
		cin >> tmp;
		for (int j = 0; j < 8; j++)
		{
			dq.push_back(tmp[j] - 48);
		}
		gear.push_back(dq);
		dq.clear();
	}

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> num >> dir;
		solve(num - 1, dir);
		rotation();
	}

	cout << result();

	return 0;
}