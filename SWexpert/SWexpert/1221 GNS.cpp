#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N, test;
	string temp;
	string testcase;
	vector<int> result;

	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> testcase;

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			if (temp == "ZRO")
				result.push_back(0);
			else if (temp == "ONE")
				result.push_back(1);
			else if (temp == "TWO")
				result.push_back(2);
			else if (temp == "THR")
				result.push_back(3);
			else if (temp == "FOR")
				result.push_back(4);
			else if (temp == "FIV")
				result.push_back(5);
			else if (temp == "SIX")
				result.push_back(6);
			else if (temp == "SVN")
				result.push_back(7);
			else if (temp == "EGT")
				result.push_back(8);
			else if (temp == "NIN")
				result.push_back(9);
		}

		sort(result.begin(), result.end());

		cout << testcase << endl;

		for (int i = 0; i < N; i++)
		{
			switch (result[i])
			{
			case 0:
				printf("ZRO ");
				break;
			case 1:
				printf("ONE ");
				break;
			case 2:
				printf("TWO ");
				break;
			case 3:
				printf("THR ");
				break;
			case 4:
				printf("FOR ");
				break;
			case 5:
				printf("FIV ");
				break;
			case 6:
				printf("SIX ");
				break;
			case 7:
				printf("SVN ");
				break;
			case 8:
				printf("EGT ");
				break;
			case 9:
				printf("NIN ");
				break;
			default:
				break;
			}
		}
		result.clear();
		cout << endl;
	}

}