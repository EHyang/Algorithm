#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

deque<int> dq;
vector<deque<int>> gear;
int result()
{
	return gear[0][0]*1 + gear[1][0]*2 + gear[2][0]*4 + gear[3][0]*8;
}
void rotation(int num,int dir)
{
	// -1 ¹Ý½Ã 1 ½Ã

	if (dir == -1)
	{
		gear[num].push_back(gear[num].front());
		gear[num].pop_front();
	}
	else
	{
		gear[num].push_front(gear[num].back());
		gear[num].pop_back();
	}
}
void right(int num, int dir)
{
	if (num + 1 < 4)
	{
		if (gear[num][2] != gear[num + 1][6])
		{
			right(num + 1, dir*-1);
		}
	}
	rotation(num, dir);
}
void left(int num, int dir)
{
	if (num - 1 >= 0)
	{
		if (gear[num][6] != gear[num - 1][2])
		{
			left(num - 1, dir*-1);
		}
	}
	rotation(num, dir);
}
void solve(int num, int dir)
{
	if (num - 1 >= 0)
	{
		if (gear[num][6] != gear[num - 1][2])
		{
			left(num - 1, dir*-1);
		}
	}
	if (num + 1 < 4)
	{
		if (gear[num][2] != gear[num + 1][6])
		{
			right(num + 1, dir*-1);
		}
	}
	rotation(num, dir);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string tmp;
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

	int K, num, dir;

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> num >> dir;

		solve(num-1, dir);
	}

	cout << result();

	return 0;
}