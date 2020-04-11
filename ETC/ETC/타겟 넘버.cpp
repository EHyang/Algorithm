#include <iostream>

#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void DFS(vector<int> n,int idx,int depth,int sum,int target)
{
	if (depth == n.size()-1)
	{
		if (sum == target) cnt++;
		return;
	}

	for (int i = 1; i <= 2; i++)
	{
		int next_sum = (i % 2 == 1 ? sum + n[idx + 1] : sum - n[idx + 1]);
		DFS(n, idx + 1, depth + 1, next_sum, target);
	}
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	DFS(numbers, 0, 0,numbers[0]*-1,target);
	DFS(numbers, 0, 0, numbers[0], target);

	answer = cnt;
	return answer;
}

int main()
{
	vector<int> num = { 1,1,1,1,1 };

	cout << solution(num, 3);

	return 0;
}