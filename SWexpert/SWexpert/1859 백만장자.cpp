#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> value;


int get_max_value(int start, int N)
{
	int Max_value = 0;
	for(int i = start; i<N;i++)
	{
		Max_value = max(Max_value, value[i]);
	}

	return Max_value;

}
int main()
{
	int T;
	int N;
	int temp;
	int count = 0;
	long sell = 0;
	int max;
	long sum = 0;
	
	vector<long> sell_price;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			value.push_back(temp);
		}

		max = get_max_value(0, N);
		for (int i = 0; i < N; i++)
		{
			if (max == value[i])
			{
				temp = value[i] * count - sum;
				sell += temp;
				max = get_max_value(i + 1, N);
				sum = 0;
				count = 0;
			}
			else
			{
				sum += value[i];
				count++;
			}
		}

		sell_price.push_back(sell);
		sell = 0;
		value.clear();
	}
	
	for (int i = 0; i < T; i++)
	{
		printf("#%d %ld \n", i+1, sell_price[i]);
	}

	return 0;
}