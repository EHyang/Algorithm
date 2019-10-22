#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<char> stack;

string makeanswer(int Mom, int Son)
{
	string answer;

	while (Son % 2 == 0)
	{
		Son /= 2;
		Mom /= 2;
	}

	answer += to_string(Son);
	answer += '/';
	answer += to_string(Mom);

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t, testcase;
	cin >> t;
	testcase = 1;

	while (t--)
	{
		string str, answer;
		cin >> str;

		int angle = 0;

		for (auto s : str)
		{
			if (s == 'n')
			{
				stack.push_back('n');
			}
			else if (s == 'w')
			{
				stack.push_back('w');
			}
		}

		int Am = 1, As;// 앞 수 분모, 분자
		int Bm = 1, Bs;// 뒷 수 분모, 분자

		if (stack.back() == 'n')
		{
			As = 0;
			stack.pop_back();
		}
		else
		{
			As = 90;
			stack.pop_back();
		}
		int ea = 1;
		while (!stack.empty())
		{
			Bm = pow(2, ea++);
			Bs = 90;
			if (stack.back() == 'n')
			{
				while (Am != Bm)
				{
					Am *= 2;
					As *= 2;
				}

				As -= Bs;
			}
			else
			{
				while (Am != Bm)
				{
					Am *= 2;
					As *= 2;
				}

				As += Bs;
			}
			stack.pop_back();
		}

		if (As%Am == 0)
		{
			answer = to_string(As / Am);
		}
		else
		{
			answer = makeanswer(Am, As);
		}

		cout << "#" << testcase++ <<" "<< answer << '\n';
	}
	   
	return 0;
}