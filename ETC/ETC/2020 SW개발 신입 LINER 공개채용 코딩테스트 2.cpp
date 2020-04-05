

#include <string>
#include <vector>

using namespace std;

int solution(string answer_sheet, vector<string> sheets) {
	int answer = -1;
	int max_val = 0;

	for (int i = 0; i < sheets.size() - 1; i++) {
		for (int j = i + 1; j < sheets.size(); j++) {
			int cnt_question = 0;
			int cnt_continue = 0;
			for (int k = 0; k < answer_sheet.length(); k++) {
				if (sheets[i][k] == sheets[j][k] && sheets[i][k] != answer_sheet[k]) {
					cnt_continue++;
					cnt_question++;
					max_val = max_val < cnt_continue ? cnt_continue : max_val;
				}
				else {
					cnt_continue = 0;
				}
			}
			answer = answer > (cnt_question + max_val * max_val) ? answer : (cnt_question + max_val * max_val);
		}
	}
	return answer;
}