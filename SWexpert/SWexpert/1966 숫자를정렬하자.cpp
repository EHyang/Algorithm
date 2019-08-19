#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int T;
	int N, tmp;
	vector<int> a;
	vector<vector<int>> ans;
	
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			a.push_back(tmp);
		}

		sort(a.begin(), a.end());
		ans.push_back(a);
		printf("#%d ", test + 1);

		for (int i = 0; i < N; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");

		a.clear();
	}

}