#include <iostream>



#include <string>
#include <vector>

using namespace std;

int check_road(int start, string a, int n, int end)
{
	int cnt = 0;
	int lent = 0;
	int i;
	for (i = start; i < end; i++)
	{
		if (a[i] == '0')
		{
			cnt++;
			if (cnt > n) break;
		}
		lent++;
	}

	return lent;
}

int solution(string road, int n) {
	int answer = -1;
	int temp;

	for (int i = 0; i < road.size(); i++)
	{
		temp = check_road(i, road, n, road.size());
		answer = answer < temp ? temp : answer;
	}

	return answer;
}


int main()
{
	string a = "111011110011111011111100011111";
	string b = "001100";
	string c = "1100110110011101001";
	int n;

	cout << solution(c, 2);

	return 0;
}