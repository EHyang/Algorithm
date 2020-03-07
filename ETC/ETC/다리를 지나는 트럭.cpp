#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	vector<int> truck;
	queue<int> q;
	truck.assign(truck_weights.size(), 0);
	int sum = 0;
	int time = 1;
	int idx = 0;
	int start = 0;
	q.push(idx);
	sum += truck_weights[idx];
	idx++;
	while (!q.empty())
	{
		time++;
		for (int i = start; i < start + q.size(); i++)
		{
			truck[i]++;

			if (truck[i] == bridge_length)
			{
				q.pop();
				sum -= truck_weights[i];
				start++;
			}
		}
		if (idx < truck_weights.size())
		{
			if (sum + truck_weights[idx] <= weight)
			{
				q.push(idx);
				sum += truck_weights[idx];
				idx++;
			}
		}
	}
	answer = time;

	return answer;
}
int main()
{
	vector<int> a = { 7,4,5,6 };
	solution(100, 100, a);
}