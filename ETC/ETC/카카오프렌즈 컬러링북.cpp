#include <vector>
#include <queue>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	
	int visit[101][101] = { 0, };

	queue<pair<int, int>> q;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cnt = 0;
			int pic;
			if (visit[i][j] != 1 && picture[i][j] != 0)
			{
				q.push({ i,j });
				cnt++;
				number_of_area++;
				pic = picture[i][j];
				visit[i][j] = 1;
			}

			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int k = 0; k < 4; k++)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx >= 0 && nx < m && ny >= 0 && ny < n)
					{
						if (visit[nx][ny] != 1 && picture[nx][ny] == pic)
						{
							q.push({ nx, ny });
							visit[nx][ny] = 1;
							cnt++;
						}
					}
				}
			}
		

			max_size_of_one_area = (max_size_of_one_area > cnt ? max_size_of_one_area : cnt);
			
		} 
	}


	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}
int main()
{
	vector<vector<int>> v = { {1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} };

	solution(6, 4, v);

	return 0;
}