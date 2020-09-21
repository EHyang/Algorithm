#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string first_step(string a) {
	for (int i = 0; i < a.size(); i++)
	{
		a[i] = tolower(a[i]);
	}

	return a;
}

string second_step(string a) {
	string ret = "";

	for (int i = 0; i < a.size(); i++)
	{
		if (('a' <= a[i] && a[i] <= 'z') || ('0' <= a[i] && a[i] <= '9') || (a[i] == '-') || (a[i] == '.') || (a[i] == '_'))
		{
			ret += a[i];
		}
	}
	return ret;
}

string third_step(string a) {
	int cnt = 0;
	string ret = "";
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '.')
		{
			if (cnt == 0)
			{
				cnt++;
				ret += a[i];
				continue;
			}
			else if (cnt >= 1)
			{
				cnt++;
				continue;
			}
		}
		else if (a[i] != '.')
		{
			cnt = 0;
			ret += a[i];
		}
	}
	return ret;
}

string fourth_step(string a) {
	string ret = "";

	for (int i = 0; i < a.size(); i++)
	{
		if ((i == 0 || i == a.size() - 1) && a[i] == '.')
			continue;
		else
			ret += a[i];
	}
	return ret;
}

string fifth_step(string a)
{
	if (a.size() == 0)
		a += "a";
	return a;
}

string sixth_step(string a)
{
	if (a.size() > 15)
		a = a.substr(0, 15);

	a = fourth_step(a);
	return a;
}

string seventh_step(string a)
{

	string::iterator itr;

	if (a.size() <= 2)
	{
		itr = a.end() - 1;

		while (a.size() != 3)
		{
			a += *itr;
		}
	}
	return a;
}

string solution(string new_id) {
	string answer = "";

	answer = first_step(new_id);
	answer = second_step(answer);
	answer = third_step(answer);
	answer = fourth_step(answer);
	answer = fifth_step(answer);
	answer = sixth_step(answer);
	answer = seventh_step(answer);

	return answer;
}

int main()
{
	string a = "abcdefghijklmn.p";
	solution(a);

	return 0;
}