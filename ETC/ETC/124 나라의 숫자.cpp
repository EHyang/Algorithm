#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";

	vector<int> tmp;

	while (n / 3 > 0)
	{
		tmp.push_back(n % 3);
		n /= 3;
	}
	tmp.push_back(n);

	for (int i = 0; i < tmp.size()-1; i++)
	{
		if (tmp[i] <= 0)
		{
			tmp[i] += 3;
			tmp[i + 1] = tmp[i + 1] - 1;
		}
	}

	if (tmp[tmp.size() - 1] != 0) answer += to_string(tmp[tmp.size() - 1]);

	for (int i = tmp.size() - 2; i >= 0; i--)
	{
		if (tmp[i] == 3)
			answer += '4';
		else
			answer += to_string(tmp[i]);
	}

	return answer;
}

int main()
{
	solution(211);

	return 0;
}