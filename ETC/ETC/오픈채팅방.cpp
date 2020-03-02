#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<string, string>> tmp;
	map<string, string> member;
	stringstream ss;
	string command, uid, name;

	for (int i = 0; i < record.size(); i++)
	{
		ss.str(record[i]);
		ss >> command;

		if (command == "Enter")
		{
			ss >> uid; ss >> name;
			if (member.find(uid) == member.end()) member.insert(make_pair(uid, name));
			else member[uid] = name;

			tmp.push_back(make_pair(uid, "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù."));
		}
		else if (command == "Leave")
		{
			ss >> uid;
			tmp.push_back(make_pair(uid, "´ÔÀÌ ³ª°¬½À´Ï´Ù."));
		}
		else if (command == "Change")
		{
			ss >> uid; ss >> name;
			if (member.find(uid) == member.end()) member.insert(make_pair(uid, name));
			else member[uid] = name;
		}
		ss.clear();
	}

	for (int i = 0; i < tmp.size(); i++)
	{
		answer.push_back(member[tmp[i].first] + tmp[i].second);
	}
	return answer;
}

#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> member;
	vector<pair<string, string>> chat;
	string cmd, id, name;
	stringstream ss;

	for (int i = 0; i < record.size(); i++)
	{
		ss.str(record[i]);
		ss >> cmd;

		if (cmd == "Enter")
		{
			ss >> id; ss >> name;
			if (member.find(id) == member.end()) member.insert({ id,name });
			else member[id] = name;

			chat.push_back({ id, "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù." });
		}
		else if (cmd == "Leave")
		{
			ss >> id; ss >> name;
			chat.push_back({ id, "´ÔÀÌ ³ª°¬½À´Ï´Ù." });
		}
		else//cmd=="Change"
		{
			ss >> id; ss >> name;
			member[id] = name;
		}

		ss.clear();
	}

	for (int i = 0; i < chat.size(); i++)
	{
		answer.push_back(member[chat[i].first] + chat[i].second);
	}


	return answer;
}