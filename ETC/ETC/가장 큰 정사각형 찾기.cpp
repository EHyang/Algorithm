#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int x = board.size();
	int y = board[0].size();

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (i == 0 || j == 0)
			{
				if (board[i][j] == 1 && answer == 0) answer = 1;
				continue;
			}
			if (board[i][j] != 0)
			{
				board[i][j] = min(min(board[i - 1][j - 1], board[i - 1][j]), board[i][j - 1]) + 1;
				answer = (answer < board[i][j] ? board[i][j] : answer);
			}
		}
	}

	return answer * answer;
}

int main()
{
	//vector<vector<int>> v = { {0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0} };
	//vector<vector<int>> v = { {0,0,1,1},{1,1,1,1} };
	vector<vector<int>> v =
	{
		{1,1,1,1},
		{1,1,0,0},
		{1,0,0,0}
	};
	cout << solution(v);
	return 0;
}