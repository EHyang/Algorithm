#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> R;
vector<int> parking;
vector<int> W;
queue<int> delay;

int n, m, cash;

int empty_index()
{
	for (int i = 0; i < n; i++)
	{
		if (parking[i] == 0)
		{
			return i;
		}
	}

	return -1;
}
int find_index(int x)
{
	x = x * -1;
	for (int i = 0; i < n; i++)
	{
		if (parking[i] == x)
			return i;
	}
}


void solve(int x)
{
	int index = empty_index();

	if (x >= 0)
	{
		if (index != -1)
		{
			cash += (R[index] * W[x]);
			parking[index] = x;
		}
		else {
			delay.push(x);
		}
	}
	else
	{
		int fid = find_index(x);
		parking[fid] = 0;
		if (!delay.empty())
		{
			int d = delay.front();
			delay.pop();
			cash += (R[fid] * W[d]);
			parking[fid] = d;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;

	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		int tmp;
		cash = 0;

		W.push_back(0);

		cin >> n >> m;
		
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			R.push_back(tmp);
			parking.push_back(0);
		}

		for (int i = 0; i < m; i++)
		{
			cin >> tmp; 
			W.push_back(tmp);
		}

		for (int i = 0; i < 2 * m; i++)
		{
			cin >> tmp;
			solve(tmp);
		}

		cout << "#" << t << " " << cash << '\n';

		R.clear();
		W.clear();
		parking.clear();

	}


	return 0;
}