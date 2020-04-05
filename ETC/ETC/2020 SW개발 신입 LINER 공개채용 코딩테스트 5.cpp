#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first > b.first;
}

vector<string> solution(vector<vector<string>> dataSource, vector<string> tags) {
	vector<string> answer;
	vector<pair<int, string>> v;

	for (int i = 0; i < dataSource.size(); i++) {
		int cnt = 0;
		for (int j = 1; j < dataSource[i].size(); j++) {
			if (find(tags.begin(), tags.end(), dataSource[i][j]) != tags.end()) {
				cnt++;
			}
		}
		v.push_back(make_pair(cnt, dataSource[i][0]));
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == 0) break;
		answer.push_back(v[i].second);
	}

	return answer;
}