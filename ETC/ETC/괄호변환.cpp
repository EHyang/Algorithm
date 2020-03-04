#include <string>
#include <vector>
#include <sstream>

using namespace std;

int d = 0;

bool correct_str(string a)
{
	int c = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '(') c++;
		else c--;

		if (c < 0) return false;
	}

	if (c == 0)
		return true;
	else return false;
}

string solution(string p) {
	d++;
	if (d == 0)
	{
		if (correct_str(p))
		{
			return p;
		}
	}
	if (p == "") return "";

	string answer = "";
	int co = 0;
	char c;
	string u = "";
	string v = "";
	stringstream ss;

	ss.str(p);

	for (; ss >> c;)
	{
		if (c == '(') co++;
		else co--;

		u += c;

		if (co == 0)
		{
			ss >> v;
			break;
		}
	}

	if (correct_str(u))
	{
		answer += u;
		answer += solution(v);
	}
	else
	{
		string temp = "(";

		temp += solution(v);
		temp += ")";

		for (int i = 1; i < u.size() - 1; i++)
		{
			if (u[i] == '(') temp += ")";
			else temp += "(";
		}

		answer += temp;
	}


	return answer;
}

int main()
{
	solution("()))((()");

	return 0;
}