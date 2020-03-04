#include <string>
#include <vector>
#include <sstream>


using namespace std;

int solution(string s) {
	int answer = s.size();

	stringstream ss;

	char c;

	for (int i = 1; i <= s.size() / 2; i++)
	{
		int cnt = 0;
		string k = s;
		ss.str(k);
		string tmp = "";
		string n = "";
		string ans = "";

		for (; ss >> c;)
		{
			n += c;

			if (n.size() == i)
			{
				if (cnt == 0)
				{
					tmp = n;
					cnt++;
					n = "";
				}
				else if (n == tmp)
				{
					cnt++;
					n = "";
				}
				else
				{
					if (cnt > 1)
						ans += to_string(cnt);
					ans += tmp;
					tmp = n;
					cnt = 1;
					n = "";
				}
			}
		}		
		if (cnt > 1)
		{
			ans += to_string(cnt);
		}
		ans+=tmp;
		if (n.size() != 0)
			ans += n;

		answer = (answer > ans.size() ? ans.size() : answer);
		ss.clear();
	}


	return answer;
}

int main()
{
	solution("aaaaaaaaaaabbbbbbbbbbb");
	
	return 0;
}