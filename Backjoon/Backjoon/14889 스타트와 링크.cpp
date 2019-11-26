#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int s[21][21];
int N;
int Answer = 101;

void calc(vector<int> &v1)
{
	int check[21];
	vector<int> v2;
	int Start_hap = 0;
	int Link_hap = 0;
	int gap;
	memset(check, 0, sizeof(int) * 21);

	for (int i = 0; i < v1.size(); i++)
	{
		check[v1[i]] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!check[i]) v2.push_back(i);
	}

	for (int i = 0; i < (N / 2) - 1; i++)
	{
		for (int j = i + 1; j < (N / 2); j++)
		{
			Start_hap += (s[v1[i]][v1[j]] + s[v1[j]][v1[i]]);
			Link_hap += (s[v2[i]][v2[j]] + s[v2[j]][v2[i]]);
		}
	}

	gap = abs(Start_hap - Link_hap);

	Answer = Answer > gap ? gap : Answer;
}

void DFS(vector<int> &mem, int start)
{
	if (mem.size() == N / 2)
	{
		calc(mem);
		return;
	}

	for (int i = start; i < N; i++)
	{
		mem.push_back(i+1);
		DFS(mem, i + 1);
		mem.pop_back();
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> s[i][j];
		}
	}

	vector<int> v;
	v.push_back(1);
	DFS(v, 1);

	cout << Answer;

	return 0;
}