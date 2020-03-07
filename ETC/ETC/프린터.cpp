#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	
	queue<pair<int, int>> q;
	vector<int> res;

	res.assign(priorities.size(), 0);
	for (int i = 0; i < priorities.size(); i++)
	{
		q.push({ i,priorities[i] });
	}
	int cnt = 1;
	bool chk;
	while (!q.empty())
	{
		chk = true;
		int idx = q.front().first;
		int val = q.front().second;

		q.pop();

		for (int i = 0; i < priorities.size(); i++)
		{
			if (i != idx && val < priorities[i])
			{
				chk = false;
				break;
			}
		}

		if (chk)
		{
			priorities[idx] = 0;
			res[idx] = cnt++;
		}
		else
		{
			q.push({ idx,val });
		}
	}

	answer = res[location];

	return answer;
}

int main()
{
	vector<int> a = { 2,1,3,2 };

	solution(a, 2);


	return 0;
}