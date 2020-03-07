#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	for (int i = 0; i < progresses.size(); i++)
	{
		progresses[i] = 100 - progresses[i];
	}

	int idx = 0;
	int end = progresses.size();
	while (idx < end)
	{
		for (int i = idx; i < end; i++)
		{
			progresses[i] -= speeds[i];
		}

		if (progresses[idx] <= 0)
		{
			int count = 0;
			int t = idx;
			for (int i = t;i< end && progresses[i] <= 0 ; i++)
			{
				count++;
				idx++;
			}

			answer.push_back(count);
		}

	}



	return answer;
}

int main()
{
	vector<int> a = { 93,30,55 };
	vector<int> b = { 1,30,5 };

	solution(a, b);
	

	return 0;
}