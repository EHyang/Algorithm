#include <iostream>
#include <deque>
#include <vector>

#define endl '\n'

using namespace std;

deque<int> dq;
vector<deque<int>> map;

int rotate_check[5] = { 0 };
int check[5] = { 1,0,0,0,0 };

int result()
{
	int ans;

	ans = 8 * map[4][0] + 4 * map[3][0] + 2 * map[2][0] + map[1][0];

	return ans;
}

void rotate()
{
	for (int i = 1; i <= 4; i++)
	{
		check[i] = 0;
		if (rotate_check[i] == 1)
		{
			map[i].push_front(map[i].back());
			map[i].pop_back();
			rotate_check[i] = 0;
		}
		else if (rotate_check[i] == -1)
		{
			map[i].push_back(map[i].front());
			map[i].pop_front();
			rotate_check[i] = 0;
		}
	}
}

void solve(int num, int way)
{
	rotate_check[num] = way;
	check[num] = 1;
	if (num != 1 && check[num - 1] != 1)
	{
		if (map[num][6] != map[num - 1][2])
		{
			solve(num - 1, way * -1);
		}
	}
	if (num != 4 && check[num + 1] != 1)
	{
		if (map[num][2] != map[num + 1][6])
		{
			solve(num + 1, way * -1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; test++)
	{
		int K, tmp;

		cin >> K;
		dq.push_back(0);
		map.push_back(dq);
		dq.clear();

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> tmp;
				dq.push_back(tmp);
			}
			map.push_back(dq);
			dq.clear();
		}
		int num, way;

		for (int i = 0; i < K; i++)
		{
			cin >> num >> way;
			solve(num, way);
			rotate();
		}

		cout << "#" << test << " " << result() << endl;

		map.clear();
	}

	return 0;
}