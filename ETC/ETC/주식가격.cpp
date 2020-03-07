#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int idx = 0;

	while (idx < prices.size())
	{
		int cnt = 1;
		for (int i = idx+1; i < prices.size()-1; i++)
		{
			if (prices[idx] <= prices[i])
				cnt++;
			else
				break;
		}
		idx++;
		if (idx == prices.size()) answer.push_back(0);
		else
			answer.push_back(cnt);
	}

	return answer;
}

int main()
{
	vector<int> a = { 1,2,3,2,3 };
	solution(a);

	return 0;
}