#include <iostream>


#include <string>
#include <vector>

using namespace std;

int solution(string inputString) {
	int answer = -1;
	int cnt = 0;
	// (0) {1} [2] <3>

	bool arr[4] = { 1,1,1,1 };

	for (int i = 0; i < inputString.length(); i++)
	{
		switch (inputString[i])
		{
		case '(':
			arr[0] = false;
			break;
		case')':
			if (arr[0]) return -1;
			arr[0] = true;
			cnt++;
			break;

		case '{':
			arr[1] = false;
			break;
		case '}':
			if (arr[1]) return -1;
			arr[1] = true;
			cnt++;
			break;

		case '[':
			arr[2] = false;
			break;
		case ']':
			if (arr[2]) return -1;
			cnt++;
			break;

		case '<':
			arr[3] = false;
			break;
		case '>':
			if (arr[3]) return -1;
			cnt++;
			break;

		default:
			break;
		}
	}
	answer = cnt;
	return answer;
}


int main()
{
	string in = "if (Count of eggs is 4.) {Buy milk.}";

	cout << solution(in);

	return 0;
}