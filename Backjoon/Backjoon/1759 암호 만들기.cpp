//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int L, C;
//vector<char> cons, diph;
//vector<string> result;
//char temp;
//
//void dfs(bool first, string s, int length, int co_idx, int di_idx, int co, int di)
//{
//	string tmp;
//
//	if (length == L)
//	{
//		if (co >= 2 && di >= 1)
//		{
//			result.push_back(s);
//			return;
//		}
//		return;
//	}
//	char last;
//	if (length != 0)
//	{
//		first = false;
//		last = s[length - 1];
//	}
//	 자음 넣기
//	for (int i = co_idx; i < cons.size(); i++)
//	{
//		tmp = s;
//		if (!first)
//		{
//			if (cons[i] <= last) continue;
//		}
//		tmp += cons[i];
//		dfs(first, tmp, length + 1, i+1, di_idx, co + 1, di);
//	}
//	 모음 넣기
//	for (int i = di_idx; i < diph.size(); i++)
//	{
//		tmp = s;
//		if (!first)
//		{
//			if (diph[i] <= last) continue;
//		}
//		tmp += diph[i];
//		dfs(first, tmp, length + 1, co_idx, i+1, co, di + 1);
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	cin >> L >> C;
//
//	for (int i = 0; i < C; i++)
//	{
//		cin >> temp;
//		cin.ignore();
//		switch (temp)
//		{
//		case 'a':
//		case 'e':
//		case 'i':
//		case 'o':
//		case 'u':
//			diph.push_back(temp);
//			break;
//		default:
//			cons.push_back(temp);
//			break;
//		}
//	}
//
//	sort(cons.begin(), cons.end());
//
//	dfs(1,"", 0, 0, 0, 0, 0);
//
//	sort(result.begin(), result.end());
//
//	for (int i = 0; i < result.size(); i++)
//	{
//		cout << result[i] << endl;
//	}
//
//	return 0;
//}

/*

2020/05/19
자음 모음 하나로 합쳐서 맞음.
아직 위에코드 뭐가 틀린지를 모르겠음.
질문해논 상태
https://www.acmicpc.net/board/view/51392

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
vector<char> cons, diph;
vector<string> result;
char temp;

void dfs(bool first, string s, int length, int idx, int co, int di)
{
	string tmp;

	if (length == L)
	{
		if (co >= 2 && di >= 1)
		{
			result.push_back(s);
			return;
		}
		return;
	}
	char last;
	if (length != 0)
	{
		first = false;
		last = s[length - 1];
	}

	for (int i = idx; i < cons.size(); i++)
	{
		tmp = s;
		if (!first)
		{
			if (cons[i] <= last) continue;
		}
		tmp += cons[i];
		if (cons[i] == 'a' || cons[i] == 'e' || cons[i] == 'i' || cons[i] == 'o' || cons[i] == 'u')
		{
			dfs(first, tmp, length + 1, idx + 1, co, di + 1);
		}
		else
			dfs(first, tmp, length + 1, idx + 1, co + 1, di);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> temp;
		cons.push_back(temp);
	}

	sort(cons.begin(), cons.end());

	dfs(1, "", 0, 0, 0, 0);

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}

	return 0;
}