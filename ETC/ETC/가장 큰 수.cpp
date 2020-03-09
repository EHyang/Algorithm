#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string &a, string &b)
{
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> str;

	for (int i = 0; i < numbers.size(); i++)
	{
		str.push_back(to_string(numbers[i]));
	}

	sort(str.begin(), str.end(), compare);

	for (string a : str)
	{
		answer += a;
	}
	if (str[0] == "0")
		answer = "0";
	return answer;
}

int main()
{
	vector<int> a = { 6,10,2 };
	solution(a);

	return 0;
}