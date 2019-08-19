/*
아스토테네스의 체

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000001];
vector<int> cal;
int main()
{
	arr[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		int k = 2; 
		if (!arr[i]) {
			cal.push_back(i);
			while (i*k <= 1000000)
			{
				arr[i*k] = 1;
				k++;
			}
		}
	}

	int T, N;
	int count, c=0;
	cin >> T;
	
	while (T--)
	{
		cin >> N;
		count = 0;
		c = 0;
		for (; cal[c] <= N / 2;)
		{
			if (!arr[N - cal[c]])
				count++;
			
			c++;
		}
		cout << count << '\n';
	}
}
