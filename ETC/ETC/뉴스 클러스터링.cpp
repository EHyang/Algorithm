#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check_alp(char t)
{
	return ('a' <= t && t <= 'z');
}

int solution(string str1, string str2) {
	int answer = 0;

	vector<string> v1, v2;
	for (int i = 0; i < str1.size(); i++)
	{
		str1[i] = tolower(str1[i]);
	}
	for (int i = 0; i < str2.size(); i++)
	{
		str2[i] = tolower(str2[i]);
	}
	if (str1 == str2)
		return 65536;

	string tmp;

	for (int i = 0; i < str1.size() - 1; i++)
	{
		if (check_alp(str1[i]) && check_alp(str1[i + 1]))
		{
			tmp += str1[i];
			tmp += str1[i + 1];
			v1.push_back(tmp);
			tmp = "";
		}
	}

	for (int i = 0; i < str2.size() - 1; i++)
	{
		if (check_alp(str2[i]) && check_alp(str2[i + 1]))
		{
			tmp += str2[i];
			tmp += str2[i + 1];
			v2.push_back(tmp);
			tmp = "";
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	vector<string>::iterator it;
	int hap = v1.size() + v2.size(), same = 0;

	for (string a : v1)
	{
		for (it = v2.begin(); it != v2.end(); ++it)
		{
			if (a == *it)
			{
				same++;
				v2.erase(it);
				break;
			}
		}
	}
	hap -= same;

	float rate = (float)same / (float)hap;

	answer = rate * 65536;

	return answer;
}

int main()
{
	string a = "FRANCE";
	string b = "french";

	string c = "aa1+aa2";
	string d = "AAAA12";

	string e = "aaab";
	string f = "aabab";

	solution(a, b);
}