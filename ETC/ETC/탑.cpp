#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	answer.assign(heights.size(), 0);
	int idx = heights.size() - 1;

	while (idx > 0)
	{
		for (int i = idx-1; i >= 0; i--)
		{
			if (heights[idx] < heights[i])
			{
				answer[idx] = i + 1;
				break;
			}
		}
		idx--;
	}

	return answer;
}

int main()
{
	vector<int> a = { 6,9,5,7,4 };

	solution(a);

	return 0;
}