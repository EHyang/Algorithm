#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dp;
vector<int> input;
int main()
{
	int tmp;
	int top = 0;

	for (int i = 0; i < 10; i++)
	{
		cin >> tmp;
		input.push_back(tmp);
	}
	dp.assign(input.size(), 0);
	dp[0] = input[0];

	for (int i = 1; i < 10; i++)
	{
		dp[i] = max(0, dp[i - 1]) + input[i];

		top = top < dp[i] ? dp[i] : top;
	}

	cout << top;

	return 0;
}