
#include <iostream>


#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair<int, double> &a, pair<int, double> &b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	int reach[502];
	int clear[502];
	vector<pair<int, double>> rate;
	for (int i = 1; i <= N + 1; i++)
	{
		reach[i] = 0;
		clear[i] = 0;
	}

	for (int i = 0; i < stages.size(); i++)
	{
		for (int j = 1; j <= stages[i]; j++)
		{
			reach[j]++;
			if (j <= stages[i] - 1)
				clear[j]++;
		}
	}
	double r = 0;
	for (int i = 1; i <= N; i++)
	{

		r = ((double)(reach[i] - clear[i]) / (double)reach[i]);
		if (reach[i] == 0) r = 0;

		rate.push_back({ i,r });
	}

	sort(rate.begin(), rate.end(), compare);

	for (int i = 0; i < rate.size(); i++)
	{
		answer.push_back(rate[i].first);
	}
	return answer;
}


int main()
{
	vector<int> stages = { 2,1,2,6,2,4,3,3 };

	solution(8, stages);


	
}