#include <iostream>
#include <vector>

#pragma	warning(disable:4996)

using namespace std;

int main()
{
	int N;
	int temp;
	int max = -1;

	vector<int> stack;
	vector<int> result;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		if (temp > max)
		{
			result.push_back(0);
			max = temp;
		}
		else
		{
			for (int j = i-1; j >= 0; j--)
			{
				if (stack[j] >= temp)
				{
					result.push_back(j + 1);
					break;
				}
				else if (j == 0 && stack[j] < temp)
					result.push_back(0);
			}
		}
		stack.push_back(temp);
		
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d ", result[i]);
	}

	return 0;
}