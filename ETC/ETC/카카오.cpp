//#include <iostream>
//
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int calc(int left, int right, int goal, int use)
//{
//	int hand;
//	int left_distance;
//	int right_distance;
//
//	if (abs(left - goal) < 3)
//	{
//		left_distance = abs(left - goal);
//	}
//	else if (abs(left - goal) % 3 == 0)
//	{
//		left_distance = abs(left - goal) / 3;
//	}
//	else if (abs(left - goal) > 3)
//	{
//		left_distance = abs(left - goal) / 3 + abs(left - goal) % 3;
//	}
//
//	if (right == 3 && right == 6 && right == 9 && right == 10)
//		right -= 2;
//
//
//	if (abs(right - goal) < 3)
//	{
//		right_distance = abs(right - goal);
//	}
//	else if (abs(right - goal) % 3 == 0)
//	{
//		right_distance = abs(right - goal) / 3;
//	}
//	else if (abs(right - goal) > 3)
//	{
//		right_distance = abs(right - goal) / 3 + abs(right - goal) % 3;
//	}
//
//
//	if (left_distance < right_distance)
//	{
//		hand = 0;
//	}
//	else if (left_distance > right_distance)
//	{
//		hand = 1;
//	}
//	else if (left_distance == right_distance)
//	{
//		if (use == 0)
//		{
//			hand = 0;
//		}
//		else
//		{
//			hand = 1;
//		}
//	}
//
//	return hand;
//}
//
//string solution(vector<int> numbers, string hand) {
//	string answer = "";
//
//	int pre; // 우선순위 0은 왼손 1은 오른손;
//	int tmp;
//	if (hand[0] == 'l')
//		pre = 0;
//	else pre = 1;
//
//	int left_now = 10, right_now = 10;
//
//	for (int i = 0; i < numbers.size(); i++)
//	{
//		switch (numbers[i])
//		{
//		case 1:
//		case 4:
//		case 7:
//			left_now = numbers[i];
//			answer += "L";
//			break;
//		case 3:
//		case 6:
//		case 9:
//			right_now = numbers[i];
//			answer += "R";
//			break;
//		case 2:
//		case 5:
//		case 8:
//		case 0:
//			if (numbers[i] == 0) numbers[i] = 11;
//			tmp = calc(left_now, right_now, numbers[i], pre);
//			if (tmp == 0)
//			{
//				left_now = numbers[i];
//				answer += "L";
//			}
//			else
//			{
//				right_now = numbers[i];
//				answer += "R";
//			}
//		default:
//			break;
//		}
//	}
//
//	return answer;
//}
//
//
//int main()
//{
//	vector<int> n = { 0,2,0,5,0,8,0 };
//	string h = "right";
//
//	cout << solution(n, h);
//
//	return 0;
//}
//
//#include <iostream>
//
//#include <string>
//#include <vector>
//#include <sstream>
//#include <algorithm>
//
//using namespace std;
//
//long long calc(long long a, long long b, char op)
//{
//	switch (op)
//	{
//	case '+':
//		return a + b;
//	case '-':
//		return a - b;
//	case '*':
//		return a * b;
//	case '/':
//		return a / b;
//	default:
//		break;
//	}
//}
//
//long long solution(string expression) {
//	long long answer = 0;
//
//	vector<long long> v;
//	vector<char> op;
//
//	for (int i = 0; i < expression.size(); i++)
//	{
//		if ('0' <= expression[i] && expression[i] <= '9')
//			continue;
//
//		else
//			op.push_back(expression[i]);
//	}
//	
//	sort(op.begin(), op.end());
//	op.erase(unique(op.begin(), op.end()), op.end());
//
//	do
//	{
//		long long last_num = -1;
//		long long num;
//		string tmp, ans = "";
//		tmp = expression;
//
//		char oper;
//		bool operation = false;
//		for (int i = 0; i < op.size(); i++)
//		{
//			stringstream ss;
//
//			ss.str(tmp);
//			while (ss >> num)
//			{
//				if (last_num == -1)
//				{
//					last_num = num;
//					ss >> oper;
//					continue;
//				}
//				else
//				{
//					if (oper == op[i])
//					{
//						last_num = calc(last_num, num, oper);
//						ss >> oper;
//					}
//					else if (oper != op[i])
//					{
//						ans += to_string(last_num);
//						ans += oper;
//						last_num = num;
//						ss >> oper;
//					}
//				}
//			}
//			int t = ans.size();
//			if (ans == "" || '0' > ans[t-1] || '9' < ans[t-1])
//				ans += to_string(last_num);
//
//			tmp = ans;
//			ans = "";
//			last_num = -1;
//		}
//
//		answer = answer > abs(stoll(tmp)) ? answer : abs(stoll(tmp));
//
//	} while (next_permutation(op.begin(), op.end()));
//
//	return answer;
//}
//
//int main()
//{
//	string str = "50*6-3*2";
//
//	cout << solution(str);
//
//	return 0;
//}
//
//#include <iostream>
//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//void init(map<string, int> &a)
//{
//	for (auto i = a.begin(); i != a.end(); i++)
//	{
//		i->second = 0;
//	}
//}
//
//bool check(map<string, int> &a)
//{
//	for (auto i = a.begin(); i != a.end(); i++)
//	{
//		if (i->second == 0) return false;
//	}
//
//	return true;
//}
//
//vector<int> solution(vector<string> gems) {
//	vector<string> temp;
//	vector<int> answer;
//	vector<pair<int, int>> stp;
//	map<string, int> m;
//	for (int i = 0; i < gems.size(); i++)
//	{
//		temp.push_back(gems[i]);
//	}
//
//	sort(temp.begin(), temp.end());
//	temp.erase(unique(temp.begin(), temp.end()), temp.end());
//
//	for (int i = 0; i < temp.size(); i++)
//	{
//		m[temp[i]] = 0;
//	}
//
//	for (int i = 0; i < gems.size(); i++)
//	{
//		int start = i;
//		int end;
//		for (int j = i; j < gems.size(); j++)
//		{
//			m[gems[j]]++;
//
//			if (check(m))
//			{
//				stp.push_back({ start + 1,j + 1 });
//				break;
//			}
//		}
//		init(m);
//	}
//
//	int min_length = 999999;
//	int st, en;
//
//	for (int i = 0; i < stp.size(); i++)
//	{
//		if ((stp[i].second - stp[i].first) < min_length)
//		{
//			min_length = (stp[i].second - stp[i].first);
//			st = stp[i].first;
//			en = stp[i].second;
//		}
//	}
//
//	answer.push_back(st);
//	answer.push_back(en);
//
//	return answer;
//}
//
//int main()
//{
//	//vector<string> a = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
//	//vector<string> a = { "AA", "AB", "AC", "AA", "AC" };
//	vector<string> a = { "XYZ", "XYZ", "XYZ" };
//	vector<int> so;
//	so = solution(a);
//
//	cout << so[0] << " " << so[1] << endl;
//
//	return 0;
//}

#include <iostream>

#include <string>
#include <vector>

using namespace std;
// 0 우 1 하 2 좌 3 상
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0, };
int cost = 9999999, N;
int visit[25][25];
vector<vector<int>> map;

bool check(int x, int y)
{
	return 0 <= x && x < N && y >= 0 && y < N;
}

void dfs(int x, int y, int c, int d, int dir, int(*v)[25])
{
	int pee = d * 100 + c * 500;
	if (pee < cost) {
		if (x == N - 1 && y == N - 1)
		{
			cost = pee;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny) && v[nx][ny] != 1 && map[nx][ny] != 1)
			{
				v[nx][ny] = 1;
				if (dir == -1 || dir == i)
				{
					dfs(nx, ny, c, d + 1, i, v);
				}
				else
					dfs(nx, ny, c + 1, d + 1, i, v);

				v[nx][ny] = 0;
			}
		}
	}
}

int solution(vector<vector<int>> board) {
	N = board.size();
	map = board;

	visit[0][0] = 1;

	dfs(0, 0, 0, 0, -1, visit);

	return cost;
}

int main()
{
	vector<vector<int>> b = { {0,0,1,0},{0,0,0,0},{0,1,0,1},{1,0,0,0} };

	cout << solution(b);

	return 0;
}