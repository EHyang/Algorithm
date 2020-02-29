#include <string>
#include <vector>

using namespace std;

void arr_initial(int(*a)[31], int x, int y)
{

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			a[i][j] = 0;
		}
	}
}
int count_num(int(*a)[31], int x, int y)
{
	int count = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (a[i][j] == 1) count++;
		}
	}

	return count;
}
void del_board(vector<string> &a, int(*b)[31], int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (b[i][j] == 1) a[i][j] = ' ';
		}
	}
}
void slide(vector<string> &a, int x, int y)
{
	for (int i = y-1; i > 0; i--)
	{
		for (int j = x-1; j >= 0; j--)
		{
			if (a[i][j] == ' ')
			{
				for (int k = i-1; k >= 0; k--)
				{
					if (a[k][j] != ' ') {
						a[i][j] = a[k][j];
						a[k][j] = ' ';
						break;
					}
				}
			}
		}
	}
}


int solution(int m, int n, vector<string> board) {
	int answer = 0;

	int map[31][31];
	bool check = true;

	while (check)
	{
		arr_initial(map, n, m);
		check = false;
		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (board[i][j] != ' ')
				{
					if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1])
					{
						check = true;
						map[i][j] = 1;
						map[i][j + 1] = 1;
						map[i + 1][j] = 1;
						map[i + 1][j + 1] = 1;
					}
				}

			}
		}
		answer += count_num(map, n, m);
		del_board(board, map, n, m);
		slide(board, n, m);

	}

	return answer;
}

int main() {
	vector<string> board = { "CCBDE","AAADE","AAABF","CCBBF" };
	solution(4, 5, board);
}