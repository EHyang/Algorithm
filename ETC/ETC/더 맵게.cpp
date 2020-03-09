#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
		
	priority_queue<int,vector<int>,greater<int>> pq;

	for (int i = 0; i < scoville.size(); i++)
	{
		pq.push(scoville[i]);
	}

	while (pq.top() < K)
	{
		if (pq.size() == 1)
		{
			answer = -1;
			break;
		}
		int fir = pq.top();
		pq.pop();
		int sec = pq.top();
		pq.pop();

		pq.push(fir + (sec * 2));
		answer++;
	}

	return answer;
}