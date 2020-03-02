#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	vector<string>::iterator it;

	int count = 2, total = 1;
	bool chk = false;

	for (int i = 1; i < words.size(); i++)
	{
		it = find(words.begin(), words.begin()+(i-1), words[i]);

		if (it != (words.begin()+ (i-1)))
		{
			chk = true;
			break;
		}

		if (words[i - 1][words[i - 1].size()-1] != words[i][0])
		{
			chk = true;
			break;
		}
		else
		{
			count++;
			if (count%n == 1) total++;
		}
	}
	
	if (chk)
	{
		if (count%n == 0) count = n;
		else
			count %= n;
	}
	else
	{
		count = 0;
		total = 0;
	}

	answer.push_back(count);
	answer.push_back(total);


	return answer;
}

int main() {
	//vector <string> words = { "hello", "one", "even", "never", "now", "world", "draw" };
	vector <string> words = { "tk", "kk", "kw", "wl", "ld", "dm", "mr","rt","tk" };
	
	solution(3, words);
}