#include <iostream>
#pragma warning(disable:4996)

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string split(string a)
{
	string sp;
	char stp[101];

	strcpy(stp, a.c_str());
	char *ptr = strtok(stp, "/");

	while (ptr != nullptr)
	{
		sp = string(ptr);
		ptr = strtok(nullptr, "/");
	}

	return "/"+sp;
}

vector<string> cp_man(vector<string> &a, string goal)
{
	vector<string> re;
	string::size_type n;
	for (int i = 0; i < a.size(); i++)
	{
		n = a[i].find(goal);
		if (n != string::npos)
			re.push_back(a[i].substr(n + (goal.length())));
	}

	return re;
}

void mk_func(vector<string> &a, string str)
{
	vector<string> ::iterator it;
	it = find(a.begin(), a.end(), str);
	if (it != a.end()) return;
	a.push_back(str);
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
}

void cp_func(vector<string> &a, string source, string dest)
{
	string split_str = split(source);
	vector<string> go = cp_man(a, source);
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == dest)
		{
			if (dest == "/")
			{
				for (int k = 0; k < go.size(); k++)
				{
					mk_func(a, (split_str + go[k]));
				}
			}
			else
			{
				for (int k = 0; k < go.size(); k++)
				{
					mk_func(a, (a[i] + split_str + go[k]));
				}
			}

			return;
		}
	}
}

void rm_func(vector<string> &a, string source)
{
	string::size_type n;
	bool check = false;
	for (int i = 0; i < a.size(); i++)
	{
		if(a[i].find(source) != string::npos)
			a[i].erase(a[i].find(source));
	}
}

vector<string> solution(vector<string> directory, vector<string> command) {
	vector<string> answer;

	for (int i = 0; i < command.size(); i++)
	{
		string cmd, a, b;
		stringstream ss;
		ss.str(command[i]);

		ss >> cmd;

		switch (cmd[0])
		{
		case 'm':
			ss >> a;
			mk_func(directory, a);
			break;
		case 'c':
			ss >> a;
			ss >> b;
			cp_func(directory, a, b);
			break;
		case 'r':
			ss >> a;
			rm_func(directory, a);
			break;
		default:
			break;
		}
	}
	sort(directory.begin(), directory.end());
	directory.erase(unique(directory.begin(), directory.end()), directory.end());

	for (int i = 1; i < directory.size(); i++)
	{
		answer.push_back(directory[i]);
	}


	return answer;
}


int main()
{
	vector<string> a = { "/",
"/hello",
"/hello/tmp",
"/root",
"/root/abcd",
"/root/abcd/etc",
"/root/abcd/hello" };
	vector<string> b = { "mkdir /root/tmp",
"cp /hello /root/tmp",
"rm /hello" };


	solution(a, b);
	return 0;
}

//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <map>
//using namespace std;
//
//map<string, int> m;
//map<string, int>::iterator iter;
//vector<vector<string>> answer;
//
//void trade(string s, string name, int n) {
//	if (s == "SAVE") {
//		int money = m[name] + n;
//		m[name] = money;
//	}
//	else {
//		int money = m[name] - n;
//		m[name] = money;
//	}
//}
//
//vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
//
//	for (int i = 0; i < snapshots.size(); i++) {
//		string s = snapshots[i][0];
//		int money = stoi(snapshots[i][1]);
//		m.insert({ s,money });
//	}
//
//		transactions.erase(unique(transactions.begin(), transactions.end()), transactions.end());
//
//	for (int i = 0; i < transactions.size(); i++) {
//		iter = m.find(transactions[i][2]);
//		if (iter != m.end()) {
//			trade(transactions[i][1], transactions[i][2], stoi(transactions[i][3]));
//		}
//		else {
//			m.insert({ transactions[i][2] ,stoi(transactions[i][3]) });
//		}
//	}
//	for (iter = m.begin(); iter != m.end(); iter++) {
//		string s = iter->first;
//		int n = iter->second;
//		vector <string> v;
//		v.push_back(s); v.push_back(to_string(n));
//		answer.push_back(v);
//		v.clear();
//	}
//	return answer;
//}
//
//int main() {
//	vector<vector<string>> snapshots = { {"ACCOUNT1","100"},{"ACCOUNT2","150"} };
//	vector<vector<string>> transactions = { {"1", "SAVE", "ACCOUNT2", "100"},{"2", "WITHDRAW", "ACCOUNT1", "50"},{"4", "SAVE", "ACCOUNT3", "500"},{"1", "SAVE", "ACCOUNT2", "100"} };
//	solution(snapshots, transactions);
//	for (int i = 0; i < answer.size(); i++) {
//		cout << answer[i][0] << answer[i][1] << "\n";
//	}
//
//}