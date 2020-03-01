#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++)
	{
		int idx = 0;
		bool check = true;
		
		for (int j = 0; j < skill_trees[i].size(); j++)
		{
			int loca = skill.find(skill_trees[i][j]);
			if (loca != -1)
			{
				if (skill_trees[i][j] == skill[idx])
				{
					idx++;
					check = true;
				}
				else
				{
					check = false;
					break;
				}
			}
		}

		if (check) answer++;
	}

	return answer;
}
int main()
{
	string a = "CBD";
	vector<string> b = { "BACDE","CBADF","AECB","BDA","EFG" };


	//string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//vector<string> b = { "ZABCDEFGHIJKLMNOPQRSTUVWXY","ABC","XYZ","" };

	solution(a, b);
	return 0;
}