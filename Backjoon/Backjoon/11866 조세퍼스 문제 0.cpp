#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> input;
vector<int> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		input.push(i);
	}
	int count = 1;
	while (!input.empty())
	{
		if (count == K)
		{
			result.push_back(input.front());
			input.pop();
			count = 1;
		}
		else
		{
			input.push(input.front());
			input.pop();
			count++;
		}
	}
	cout << "<";
	for (int i = 0; i < N-1; i++)
	{
		cout << result[i] << ", ";
	}
	cout << result[N - 1] << ">";
}