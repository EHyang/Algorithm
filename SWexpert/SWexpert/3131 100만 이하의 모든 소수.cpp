#include <iostream>
#include <vector>

using namespace std;

int arr[1000001];
vector<int> cal;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

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

	for (int i : cal)
	{
		cout << i << " ";
	}
}
