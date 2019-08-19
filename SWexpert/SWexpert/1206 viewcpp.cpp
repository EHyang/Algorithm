#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int L, temp;
	bool check = false;
	vector <int> height;
	vector <int> re;

	int result = 0;
	int tmp_Max = 0;

	for (int test = 0; test < 10; test++)
	{
		cin >> L;
		for (int i = 0; i < L; i++) {
			cin >> temp;
			height.push_back(temp);
		}

		for (int i = 2; i < L - 2; i++)
		{
			for (int j = -2; j <= 2; j++)
			{
				if (j == 0) continue;
				if (height[i] <= height[i + j])
				{
					check = false;
					break;
				}
				else {
					check = true;
					if (height[i + j] >= tmp_Max)
						tmp_Max = height[i + j];
				}
			}
			if (check)
			{
				temp = height[i] - tmp_Max;
				result += temp;
			}
			check = false;
			tmp_Max = 0;
		}

		re.push_back(result);
		result = 0;
		height.clear();
	}

	for (int test = 1; test <= 10; test++)
	{
		printf("#%d %d\n", test, re[test - 1]);
	}
}